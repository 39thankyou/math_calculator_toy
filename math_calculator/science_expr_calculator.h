#pragma once
#ifndef S_E_C
#define S_E_C
#include<string>
#include"calculator.h"
class science_expr_calculator
{
public:
	long double do_calculator(const std::string& str)const;
	void test() const;
protected:
	static calculator_long_double ld_c;
};
#endif // !S_E_C
