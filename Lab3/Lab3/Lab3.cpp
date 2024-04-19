#include <iostream>
#include "Account.h"
#include "BankAccount.h"

int main(int argc, char** argv)
{
	BankAccount lBankAccount(12345);
	std::cout << "Balance: " << lBankAccount.balance() << std::endl;
	Account& lAccount = lBankAccount;
	lAccount.deposit(100.0);
		if (lAccount.withdraw(50.0))
		std::cout << "Social credit + 1, Wow!!~.~" << std::endl;
	else
		std::cout << "Social credit -999999999999, >.<" << std::endl;

	delete& lBankAccount;
	delete& lAccount;

	return 0;
}