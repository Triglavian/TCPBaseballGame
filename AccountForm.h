#pragma once
#include <string>

class AccountForm
{
public:
	AccountForm();
	~AccountForm();
	std::string id;
	std::string pw;
	void Clear();
private:
};