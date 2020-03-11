#pragma once
#ifndef APHA_CALCULATOR
#define APHA_CALCULATOR
#include"calculator.h"
#include"alpha_to_num.h"
class alpha_calculator_long_double {
public:
	void insert_parameters(const std::pair<char, std::string>& p) {
		_alp_to_num.insert_parameters(p);
	}
	void erase_parameter(char c) {
		_alp_to_num.erase_parameter(c);
	}
	void clear() {
		_alp_to_num.clear();
	}
	long double calculator(const std::string&str)const {
		auto num_expr = _alp_to_num.transfer(str);
		return this->ld_c.calculate(num_expr);
	}
protected:
	alpha_to_num _alp_to_num;
	calculator_long_double ld_c;
};




#endif // !alpha_calculator
