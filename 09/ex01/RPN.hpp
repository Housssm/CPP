#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int evaluate(const std::string& expression);

	private:
		std::stack<int> _stack;

		bool isOperator(char c) const;
		int applyOperation(int a, int b, char op) const;
};

#endif