#pragma once
#ifndef STAN_TO_RPN
#define STAN_TO_RPN

#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<vector>

#define OPS_BEGIN namespace OPS{
#define OPS_END }



OPS_BEGIN

using std::vector, std::string;
//符号集
const vector<vector<char>>ops_set
{
	{'^'},
	{'*','/'},
	{'+','-'}
};

//判断是否是数字
inline bool is_num(char c) {
	return c <= '9' && c >= '0' || c == '.';
}
inline bool is_op(char c) {
	for (const auto& cs : ops_set) {
		for (auto op : cs)
			if (op == c)return true;
	}
	return false;
}

//获取运算符优先级
inline size_t get_level(char op) {
	size_t i = 0;
	for (; i < ops_set[i].size(); i++) {
		for (size_t j = 0; j < ops_set[i].size(); j++) {
			if (ops_set[i][j] == op)return i;
		}
	}
	if (op == ops_set[i].size())throw "erro";
	return i;
}
std::string _transfer_to_rpn(const std::string& s);//转换为后缀码

void  add_zero(string& s);//补0

OPS_END

//转换为后缀码 --总
inline std::string transfer_to_rpn(const std::string&str) {
	std::string s = str;
	OPS::add_zero(s);
	return OPS::_transfer_to_rpn(s);
	
}

#endif // !STAN_TO_RPN
