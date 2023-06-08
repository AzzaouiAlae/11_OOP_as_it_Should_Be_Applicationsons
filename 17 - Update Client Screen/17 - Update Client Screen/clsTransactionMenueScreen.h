#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidation.h"

using namespace std;

bool BackToTransaction = true;

class clsTransactionMenueScreen : protected clsScreen
{
	enum enTransactionOption {
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMeune = 4
	};

	static void _ReturnToTransaction()
	{
		cout << "\nPress any key to go back to main Menue...";
		system("pause>0");
	}

	static void _ShowDepositScreen()
	{
		cout << "Deposit screen Will be here";
	}

	static void _ShowWithdrawScreen()
	{
		cout << "Withdraw screen Will be here";
	}

	static void _ShowTotalBalancesScreen()
	{
		cout << "Total Balances screen Will be here";
	}		

	static void _PerformTransaction(enTransactionOption Option)
	{
		switch(Option)
		{
		case eDeposit:
			system("cls");
			_ShowDepositScreen();
			_ReturnToTransaction();
			break;

		case eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_ReturnToTransaction();
			break;

		case eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_ReturnToTransaction();
			break;

		case eMainMeune:
			system("cls");
			BackToTransaction = false;
			break;
		}
	}

public:
	static void ShowTransactionScreen()
	{
		BackToTransaction = true;

		while (BackToTransaction)
		{
			system("cls");

			_DrawHeder("Transaction Screen");
			cout << "[1] Deposit.\n";
			cout << "[2] Withdraw.\n";
			cout << "[3] Total Balances.\n";
			cout << "[4] Main Menue.\n";
			cout << "===================================\n";
			string msg = "choose what do you want to do [1/4] : ";
			_PerformTransaction((enTransactionOption)clsInputValidation::ReadShortNumber(msg, 1, 4));
		}
		

	}
};

