#pragma once
#include <iostream>
#include "clsScreen.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsWithdraw : protected clsScreen
{
public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");
		string AccNum = clsInputValidation::ReadString("Please enter Account Number : ");
		while (clsBankClient::Find(AccNum).IsEmpty())
		{
			AccNum = clsInputValidation::ReadString("Account Number not found enter another one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccNum);

		_PrintClientCard(Client);

		float Amount = clsInputValidation::ReadDoubleNumber("Please enter withdraw Amount : ");

		if (clsInputValidation::ValidationYesNo("\nAre you sure you want to perform this Transaction (y/n): "))
		{
			Client.Withdraw(Amount);
			cout << "\nAmount withdraw successfully!\n";
			cout << "\nNew Balance is :" << to_string(Client.Balance);
		}
		else
			cout << "\nTransaction was cancelled\n";
	}
};

