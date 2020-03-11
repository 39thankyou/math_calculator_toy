#pragma once
#ifndef _CALCULATOR
#define _CALCULATOR
#include<iostream>
#include<string>
#include<functional>
#include"standarizing_to_rpn.h"
#include<string_view>
#include<algorithm>
template<typename num_type>
num_type _compute(num_type n1, num_type n2, char op) {
	switch (op)
	{
	case '^':return pow(n1, n2); break;
	case '+':return n1 + n2; break;
	case '-':return n1 - n2; break;
	case '*':return n1 * n2; break;
	case '/':return n1 / n2; break;
	default:throw"erro";break;
	}
}

template<typename num_type>
class _calculator_base {
public:
	using transfer_to_value_function = std::function<num_type(const std::string&)>;
	num_type calculate(const std::string&)const;
protected:
	_calculator_base(std::function<num_type(const std::string&)>f):sto_num_type(f){}
	transfer_to_value_function sto_num_type;
};

template<typename num_type>
num_type _calculator_base<num_type>::calculate(const std::string&rp)const{
	std::stack<num_type>stk;
	std::string rpn=transfer_to_rpn(rp),tmp;
	auto it = rpn.begin();
	while (it != rpn.end()) {
		if (*it == ' ') { it++; continue; }
		if (OPS::is_num(*it)) {
			auto not_num = std::find_if(it, rpn.end(), [=](const char& c) {return !OPS::is_num(c); });
			tmp = std::string{ it,not_num };
			num_type num = sto_num_type(tmp);
			stk.push(num);
			it = not_num;
		}
		else {
			num_type n1, n2;
			n2 = stk.top();
			stk.pop();
			n1 = stk.top();
			stk.pop();
			stk.push(_compute(n1, n2, *it));
			it++;
		}
	}
	return stk.top();
}
#endif // !calculator
