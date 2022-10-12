#include "AccountManager.h"

AccountManager::AccountManager()
{
	acc = new std::list<AccountForm>();
}

AccountManager::~AccountManager()
{
	if (acc != nullptr) {
		acc->clear();
		delete acc;
	}
}

bool AccountManager::Registration(const AccountForm& tempAcc)
{
	if (IsInvalidAcc(tempAcc) == true) return false;
	AccountRegistraion(tempAcc);
	return true;
}

bool AccountManager::LogIn(const AccountForm& acc)
{
	for (auto& _acc : *this->acc) {
		if (_acc.id == acc.id && _acc.pw == acc.pw) return true;
	}
	return false;
}

bool AccountManager::LogOut(AccountForm& acc)
{
	acc.Clear();
	return true;
}

bool AccountManager::IsInvalidAcc(const AccountForm& tempAcc)
{
	for (auto& _acc : *acc) {
		if (_acc.id == tempAcc.id) return true;
	}
	return false;
}

void AccountManager::AccountRegistraion(const AccountForm& tempAcc)
{
	acc->push_back(tempAcc);
}

//AccountForm AccountManager::LogIn()
//{
//	return ;
//}
