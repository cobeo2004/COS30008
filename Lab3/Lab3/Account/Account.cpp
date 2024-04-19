#include "Account.h"

Account::Account(uint64_t aNumber, double aBalance) noexcept :
	fBalance(aBalance),
	fNumber(aNumber)
{
}

bool Account::deposit(double aAmount) noexcept
{
	fBalance += aAmount;
	return true;
}

bool Account::withdraw(double aAmount) noexcept
{
	fBalance -= aAmount;
	return true;
}


