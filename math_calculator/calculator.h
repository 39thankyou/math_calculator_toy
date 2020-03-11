#pragma once
#ifndef CALCULATOR
#define CALCULATOR
#include"_calculator.h"

class calculator_int
	:public _calculator_base<int>
{
public:
	calculator_int(
		transfer_to_value_function f = [](const std::string& str) {return std::stoi(str); }
	) :_calculator_base<int>(f)
	{}
};


class calculator_ulong
	:public _calculator_base<unsigned long>
{
public:
	calculator_ulong(
		transfer_to_value_function f = [](const std::string& str) {return std::stoul(str); }
	) :_calculator_base<unsigned long>(f)
	{}
};



class calculator_double
	:public _calculator_base<double>
{
public:
	calculator_double(
		transfer_to_value_function f = [](const std::string& str) {return std::stod(str); }
	) :_calculator_base<double>(f)
	{}
};

class calculator_float
	:public _calculator_base<float>
{
public:
	calculator_float(
		transfer_to_value_function f = [](const std::string& str) {return std::stof(str); }
	) :_calculator_base<float>(f)
	{}
};


class calculator_long_double
	:public _calculator_base<long double>
{
public:
	calculator_long_double(
		transfer_to_value_function f = [](const std::string& str) {return std::stold(str); }
	) :_calculator_base<long double>(f)
	{}
};
class calculator_long_long
	:public _calculator_base<long long>
{
public:
	calculator_long_long(
		transfer_to_value_function f = [](const std::string& str) {return std::stoll(str); }
	) :_calculator_base<long long>(f)
	{}
};
class calculator_ulong_long
	:public _calculator_base<unsigned long long>
{
public:
	calculator_ulong_long(
		transfer_to_value_function f = [](const std::string& str) {return std::stoull(str); }
	) :_calculator_base<unsigned long long>(f)
	{}
};




#endif // !CALCULATOR
