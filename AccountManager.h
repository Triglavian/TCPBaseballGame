#pragma once
#include <iostream>
#include <list>
#include "AccountForm.h"

class AccountManager	//db class
{
public:
	AccountManager();
	~AccountManager();
	bool Registration(const AccountForm& tempAcc);	//validate registration result
	bool LogIn(const AccountForm& acc);	//validate log in result
	bool LogOut(AccountForm& acc);		//clear param account data
private:
	bool IsInvalidAcc(const AccountForm& tempAcc);			//validate is exist account
	void AccountRegistraion(const AccountForm& tempAcc);	//register account to db
	std::list<AccountForm>* acc;	//db
};