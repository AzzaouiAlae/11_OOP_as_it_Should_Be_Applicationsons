#pragma once
#include <iostream>
#include "bank/clsScreen.h"
#include "MyLib/clsInputValidation.h"
#include "Bank/clsBank.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
	static clsBankClient _ReadClient()
	{
		string Acc = clsInputValidation::ReadString("please enter account number to transfer from : ");
		while (clsBankClient::Find(Acc).IsEmpty())
		{
			Acc = clsInputValidation::ReadString("Account number not found! enter another one : ");
		}
		clsBankClient acc = clsBankClient::Find(Acc);
		_PrintClientTransferCard(acc);
		return acc;
	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");
		
		clsBankClient acc1 = _ReadClient();
		
		clsBankClient acc2 = _ReadClient();;

		float Amount = clsInputValidation::ReadDoubleNumber("enter trasfer amount : ");
		
		while (true)
		{
			if (clsInputValidation::ValidationYesNo("\nAre you sure you want to perform this operation? y/n : "))
			{
				if (acc1.Transfer(acc2, Amount))
				{
					cout << "\n\nTransfer done successfully\n";
					_PrintClientTransferCard(acc1);
					_PrintClientTransferCard(acc2);
					break;
				}

				else
					Amount = clsInputValidation::ReadDoubleNumber("Amount Exceeds the available Balance, enter another amount : ");
			}
			else
			{
				cout << "Transfer was canceled\n";
				break;
			}
		}
	}
};

