#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
{

public:
	static void ShowWithdrawScreen()
	{
		_DrawHeder("Withdraw Screen");
		string AccNum = clsInputValidation::ReadString("Please enter Account Number : ");

		while (!clsBankClient::IsClientExist(AccNum))
		{
			AccNum = clsInputValidation::ReadString("Account Number not found, choose anothre one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccNum);

		_PrintClientCard(Client);

		double Amount = clsInputValidation::ReadDoubleNumber("Please enter Withdraw Amount : ", 1, clsInputValidation::enFromNum);

		if (clsInputValidation::ValidationYesNo("\n\nAre you sure you want to perform this Transaction (y/n): "))
		{
			if(Client.Withdraw(Amount))
			{
				cout << "\nAmount withdraw successfully!\n";
				cout << "\nNew Balance is : " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\n      Your Balance is: " << Client.AccountBalance;
			}
		}
		else
		{
			cout << "\nTransaction was cancelled\n";
		}
	}
};

