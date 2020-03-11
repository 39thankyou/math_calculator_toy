#include "science_expr_calculator.h"
using namespace std;
calculator_long_double  science_expr_calculator::ld_c;

long double science_expr_calculator::do_calculator(const std::string& str) const
{
	return this->ld_c.calculate(str);
}

void science_expr_calculator::test() const
{
	string str;
	cout << "请输入一个符合规范的float表达式;" << endl;
	while (cin >> str) {
		cout << "结果：" << this->do_calculator(str) << endl;
		cout << "请再输入一个符合规范的float表达式" << endl;
	}
}
