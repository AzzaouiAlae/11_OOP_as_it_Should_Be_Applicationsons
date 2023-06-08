#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "Bank/clsBank.h"
#include <iomanip>

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
	static void _PrintTransferLog(clsBankClient::strTransferLog Log)
	{
		cout << "| " << left << setw(25) << Log.DateTime;
		cout << "| " << left << setw(10) << Log.S_Acc;
		cout << "| " << left << setw(10) << Log.D_Acc;
		cout << "| " << left << setw(10) << Log.Amount;
		cout << "| " << left << setw(10) << Log.S_Balance;
		cout << "| " << left << setw(10) << Log.D_Balance;
		cout << "| " << Log.User << endl;
	}
public :
	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::strTransferLog> vLog = clsBankClient::GetTransferLogList();

		_DrawScreenHeader("Transfer Log List Screen", "(" + to_string(vLog.size()) + ") Record(s).", 100);

		cout << "\n" << _TextRepeat("-", 100) ;
		cout << "\n| " << left << setw(25) << "Date Time";
		cout << "| " << left << setw(10) << "S_Acc";
		cout << "| " << left << setw(10) << "D_Acc";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S_Balance";
		cout << "| " << left << setw(10) << "D_Balance";
		cout << "| " << "User";
		cout << "\n" << _TextRepeat("-", 100) << endl;

		for (clsBankClient::strTransferLog &Log : vLog)
		{
			_PrintTransferLog(Log);
		}
		cout << _TextRepeat("-", 100) << endl;
	}
};

