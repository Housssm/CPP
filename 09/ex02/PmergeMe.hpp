#pragma once
# include <vector>
# include <deque>
# include <string>
# include <utility>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void run(int argc, char **argv);

	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

		void parseArgs(int argc, char **argv);
		bool isValidPositiveInt(const std::string& str, int& value) const;

		// Algorithme Ford-Johnson pour std::vector
		void fordJohnsonVector(std::vector<int>& arr);
		std::vector<size_t> buildJacobsthalOrderVec(size_t n) const;

		// Algorithme Ford-Johnson pour std::deque
		void fordJohnsonDeque(std::deque<int>& arr);
		std::deque<size_t> buildJacobsthalOrderDeq(size_t n) const;
};