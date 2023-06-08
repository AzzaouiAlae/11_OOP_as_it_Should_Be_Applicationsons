#pragma once
#include <iostream>
#include <string>
#include "Bank/clsScreen.h"
#include "Bank/clsBank.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsDeposit : protected clsScreen
{
public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");
		string AccNum = clsInputValidation::ReadString("Please enter Account Number : ");
		while (clsBankClient::Find(AccNum).IsEmpty())
		{
			AccNum = clsInputValidation::ReadString("Account Number not found enter another one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccNum);

		_PrintClientCard(Client);

		float Amount = clsInputValidation::ReadDoubleNumber("Please enter deposit Amount : ");
		
		if (clsInputValidation::ValidationYesNo("\nAre you sure you want to perform this Transaction (y/n): "))
		{
			Client.Deposit(Amount);
			cout << "\nAmount deposited successfully!\n";
			cout << "\nNew Balance is :" << to_string(Client.Balance);
		}
		else
			cout << "\nTransaction was cancelled\n";
	}
};

