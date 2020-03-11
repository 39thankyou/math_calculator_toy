#include"standarizing_to_rpn.h"
OPS_BEGIN
std::string _transfer_to_rpn(const std::string& s) {
	std::stack<char>stk;
	std::string result;
	bool last_is_num = true;
	for (auto c : s)
	{
		if (c == ' ')continue;
		if (OPS::is_num(c)) {
			if (!last_is_num) {
				result.push_back(' ');
			}
			result.push_back(c);
			last_is_num = true;
		}
		else if (c == ')') {
			while (!stk.empty() && stk.top() != '(') {
				result.push_back(' ');
				result.push_back(stk.top());
				stk.pop();
			}
			stk.pop();
		}
		else if (!stk.empty() && c != '(' && stk.top() != '(' && OPS::get_level(stk.top()) <= OPS::get_level(c)) {

			while (c != '(' && !stk.empty() && stk.top() != '(' && OPS::get_level(stk.top()) <= OPS::get_level(c)) {
				result.push_back(' ');
				result.push_back(stk.top());
				stk.pop();
				last_is_num = false;
			}
			stk.push(c);

		}
		else {
			stk.push(c);
			last_is_num = false;
		}
	}
	while (!stk.empty()) {
		if (stk.top() != '(')result.push_back(stk.top());
		stk.pop();
	}

	return result;
}



void add_zero(string& str) {
	for (auto it = str.begin(); it != str.end(); it++) {
		if (*it == '(' && *(it + 1) == '-') {
			it=str.insert(it + 1, '0');
		}
	}
}
OPS_END