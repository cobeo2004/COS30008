#include "BankAccount.h"

BankAccount::BankAccount(uint64_t aNumber, double aBalance, double aInterestRate) noexcept :
	Account(aNumber, aBalance),
	fInterestRate(aInterestRate)
{}

bool BankAccount::withdraw(double aAmount) noexcept 
{
	if ((this->balance() - aAmount) > 0.0)
		return Account::withdraw(aAmount);
	return false;
}

bool BankAccount::creditInterest(double aInterval) noexcept
{
	return deposit((this->balance() * fInterestRate / 100) * aInterval);
}
bool BankAccount::applyServiceFee(double aFee) noexcept
{
	return Account::withdraw(aFee);
}