#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBank.h"
#include "MyLib/clsUtility.h"

using namespace std;

class clsTotalBalances : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(25) << Client.FullName();
		cout << "| " << left << setw(15) << Client.Balance << endl;
	}
public:
	static void ShowTotalBalanceScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		float TotalBalance = 0;
		_DrawScreenHeader("Clients List", to_string(vClients.size()) + " Clients", 65);
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(25) << "Clients Name";
		cout << "| " << left << setw(15) << "Balance";
		cout << endl << _TextRepeat("-", 65) << endl;
		for (clsBankClient C : vClients)
		{
			_PrintClient(C);
			TotalBalance += C.Balance;
		}
		cout << endl << _TextRepeat("-", 65) << endl;

		cout << "\t\tTotal Balance : " << to_string((int)TotalBalance) << endl;
		cout << "\t\t" << clsUtility::ConvertNumberToText(TotalBalance);
	}
};