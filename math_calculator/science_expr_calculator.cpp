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
	cout << "������һ�����Ϲ淶��float���ʽ;" << endl;
	while (cin >> str) {
		cout << "�����" << this->do_calculator(str) << endl;
		cout << "��������һ�����Ϲ淶��float���ʽ" << endl;
	}
}
