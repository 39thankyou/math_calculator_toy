#pragma once
#ifndef ALPHA_TO_NUM
#define ALPHA_TO_NUM
#include<string>

#include<unordered_map>

class alpha_to_num
{
public:
	std::string transfer (const std::string& ex)const;
	void insert_parameters(const std::pair<char, std::string>&p) {
		auto it = m.find(p.first);
		if (it != m.end()) { it->second = p.second; }
		m.insert(p);
	}
	void erase_parameter(char c) {
		m.erase(c);
	}
	void clear() {
		m.clear();
	}
protected:
	std::unordered_map<char, std::string>m;
};





inline std::string alpha_to_num::transfer(const std::string& ex) const
{
	std::string result;
	for (auto it = ex.cbegin(); it != ex.cend();it++ ) {
		if (std::isalpha(*it)) {
			char c = *it;
			result+=this->m.find(c)->second;
		}
		else {
			result.push_back(*it);
		}
	}
	return result;
}


#endif // !ALPHA_TO_NUM
