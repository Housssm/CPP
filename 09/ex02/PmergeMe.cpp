#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <ctime>
#include <iomanip>
#include <cctype>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::isValidPositiveInt(const std::string& str, int& value) const
{
	if (str.empty())
		return false;

	size_t i = 0;
	if (str[0] == '+')
		i++;
	if (i == str.length())
		return false;

	for (; i < str.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}

	std::istringstream iss(str);
	long num = 0;
	if (!(iss >> num) || !iss.eof() || num <= 0 || num > INT_MAX)
		return false;

	value = static_cast<int>(num);
	return true;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int val = 0;
		if (!isValidPositiveInt(argv[i], val))
			throw std::runtime_error("Error");
		_vec.push_back(val);
		_deq.push_back(val);
	}
}

// ============================================================================
// SUITE DE JACOBSTHAL (ordre optimal d'insertion binaire)
// J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2 * J(n-2) -> 0, 1, 1, 3, 5, 11, 21, 43...
// ============================================================================

std::vector<size_t> PmergeMe::buildJacobsthalOrderVec(size_t n) const
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < n)
	{
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	std::vector<bool> inserted(n, false);
	// L'élément 0 (b1) est déjà inséré en tête de mainChain
	inserted[0] = true;

	for (size_t k = 2; k < jacob.size(); ++k)
	{
		size_t idx = std::min(jacob[k], n);
		while (idx > 0)
		{
			size_t pos = idx - 1;
			if (!inserted[pos])
			{
				order.push_back(pos);
				inserted[pos] = true;
			}
			--idx;
		}
	}

	for (size_t i = 0; i < n; ++i)
	{
		if (!inserted[i])
			order.push_back(i);
	}
	return order;
}

std::deque<size_t> PmergeMe::buildJacobsthalOrderDeq(size_t n) const
{
	std::deque<size_t> order;
	if (n == 0)
		return order;

	std::deque<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < n)
	{
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	std::deque<bool> inserted(n, false);
	inserted[0] = true;

	for (size_t k = 2; k < jacob.size(); ++k)
	{
		size_t idx = std::min(jacob[k], n);
		while (idx > 0)
		{
			size_t pos = idx - 1;
			if (!inserted[pos])
			{
				order.push_back(pos);
				inserted[pos] = true;
			}
			--idx;
		}
	}

	for (size_t i = 0; i < n; ++i)
	{
		if (!inserted[i])
			order.push_back(i);
	}
	return order;
}

// ============================================================================
// FORD-JOHNSON POUR STD::VECTOR
// ============================================================================

void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;

	// 1. Gestion d'un éventuel élément impair laissé de côté
	bool hasStraggler = (arr.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler)
	{
		straggler = arr.back();
		arr.pop_back();
	}

	// 2. Formation des paires (grand, petit)
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// 3. Tri récursif des plus grands éléments de chaque paire
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].first);

	fordJohnsonVector(mainChain);

	// 4. Réalignement des petits éléments (pend) selon le nouvel ordre de mainChain
	std::vector<int> pend;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].first == mainChain[i])
			{
				pend.push_back(pairs[j].second);
				used[j] = true;
				break;
			}
		}
	}

	// 5. Insertion gratuite de b1 tout au début (puisque b1 <= a1)
	mainChain.insert(mainChain.begin(), pend[0]);

	// 6. Insertion binaire des éléments restants de pend selon l'ordre de Jacobsthal
	std::vector<size_t> order = buildJacobsthalOrderVec(pend.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int valToInsert = pend[order[i]];
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
		mainChain.insert(pos, valToInsert);
	}

	// 7. Insertion de l'élément impair s'il existait
	if (hasStraggler)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}

// ============================================================================
// FORD-JOHNSON POUR STD::DEQUE
// ============================================================================

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return;

	bool hasStraggler = (arr.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler)
	{
		straggler = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].first);

	fordJohnsonDeque(mainChain);

	std::deque<int> pend;
	std::deque<bool> used(pairs.size(), false);
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].first == mainChain[i])
			{
				pend.push_back(pairs[j].second);
				used[j] = true;
				break;
			}
		}
	}

	mainChain.insert(mainChain.begin(), pend[0]);

	std::deque<size_t> order = buildJacobsthalOrderDeq(pend.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int valToInsert = pend[order[i]];
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
		mainChain.insert(pos, valToInsert);
	}

	if (hasStraggler)
	{
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}

// ============================================================================
// EXÉCUTION ET CHRONOMÉTRAGE
// ============================================================================

void PmergeMe::run(int argc, char **argv)
{
	parseArgs(argc, argv);

	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::clock_t startVec = std::clock();
	fordJohnsonVector(_vec);
	std::clock_t endVec = std::clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	std::clock_t startDeq = std::clock();
	fordJohnsonDeque(_deq);
	std::clock_t endDeq = std::clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
}