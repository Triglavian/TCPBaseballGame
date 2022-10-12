#pragma once
#include <iostream>
#include <list>
#include "AccountForm.h"

class AccountManager
{
public:
	AccountManager();
	~AccountManager();
	bool Registration(const AccountForm& tempAcc);
	bool LogIn(const AccountForm& acc);
	bool LogOut(AccountForm& acc);
private:
	bool IsInvalidAcc(const AccountForm& tempAcc);
	void AccountRegistraion(const AccountForm& tempAcc);
	std::list<AccountForm>* acc;
};