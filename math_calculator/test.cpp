#include<iostream>
#include"calculator.h"
#include"alpa_calculator.h"
using namespace std;

void test_calculator();
void transfer_to_996_salary();

int main()
{
	//transfer_to_996_salary();
	alpha_calculator_long_double c;

	string num;
	while (cin >> num) {
		c.insert_parameters({ 'x' ,num });
		cout << c.calculator("x^2-2*x-5") << endl;
	}

	system("pause");
}

void test_calculator()
{
	string float_express = "1+2*(-1.2)+3.14";
	string int_express = "1+2*(-3)-7/(3+2)";
	calculator_float cf;
	calculator_double cd;
	calculator_long_double cld;


	calculator_int ci;
	calculator_ulong cul;
	calculator_long_long cll;
	calculator_ulong_long cull;

	cout << float_express << endl;
	cout << "cf:  " << cf.calculate(float_express) << endl;
	cout << "cd:  " << cd.calculate(float_express) << endl;
	cout << "cld:  " << cld.calculate(float_express) << endl;

	cout << int_express << endl;
	cout << "ci:  " << ci.calculate(int_express) << endl;
	cout << "cul:  " << cul.calculate(int_express) << endl;
	cout << "cll:  " << cll.calculate(int_express) << endl;
	cout << "cull:  " << cull.calculate(int_express) << endl;



	string str;

	cout << "请输入一个符合规范的float表达式;" << endl;
	while (cin >> str) {
		cout << "结果：" << cld.calculate(str) << endl;

		cout << "请再输入一个符合规范的float表达式" << endl;
	}
}

long double get_your_955salary_per_hour(long double s) {
	static  const constexpr size_t month_hours = (size_t)5 * 8 * 4 + 16;
	return s / month_hours;

}
void transfer_to_996_salary()
{

	const static constexpr long long month_hours = (size_t)312;
	alpha_calculator_long_double ald;
	string expr = "208*x+104*1.5*x";

	long double salary;
	string str;
	cout << "请输入一个月薪;" << endl;
	//cin >> str;
	while (cin >> salary) {
		str = to_string(get_your_955salary_per_hour(salary));
		ald.insert_parameters({ 'x',str });
		cout << "根据你的月薪算的996应得的合法收入：" << long long(ald.calculator(expr)) << endl;
		cout << "请再输入一个月薪" << endl;
	}

}
