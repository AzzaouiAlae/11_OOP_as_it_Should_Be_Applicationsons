#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsBankClient.h"

class clsDepositScreen : protected clsScreen
{
public:

	static void ShowDepositScreen()
	{
		_DrawHeder("Deposit Screen");
		string AccNum = clsInputValidation::ReadString("Please enter Account Number : ");

		while (!clsBankClient::IsClientExist(AccNum))
		{
			AccNum = clsInputValidation::ReadString("Account Number not found, choose anothre one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccNum);

		_Print(Client);

		double Amount = clsInputValidation::ReadDoubleNumber("Please enter deposit Amount : ", 1, clsInputValidation::enFromNum);

		if (clsInputValidation::ValidationYesNo("\n\nAre you sure you want to perform this Transaction (y/n): "))
		{ 
			Client.Deposit(Amount);

			cout << "\nAmount deposited successfully!\n";
			cout << "\nNew Balance is : " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\nTransaction was cancelled\n";
		}
	}
};

