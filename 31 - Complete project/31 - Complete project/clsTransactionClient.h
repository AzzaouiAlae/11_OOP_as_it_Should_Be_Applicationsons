#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBank.h"
#include "clsDeposit.h"
#include "clsWithdraw.h"
#include "clsTotalBalances.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

bool BackToTransaction = true;

class clsTransactionClient : protected clsScreen
{
	enum enTransactionOption {
		enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enMainMenue = 4 
	};

	static void _GoBackToTransaction()
	{
		cout << "\n\nPress any key to go back to Transaction Menue...";
		system("pause>0");
	}

	static void _PerformTransaction(enTransactionOption Option)
	{
		switch (Option)
		{
		case clsTransactionClient::enDeposit:
			system("cls");
			clsDeposit::ShowDepositScreen();
			_GoBackToTransaction();
			break;
		case clsTransactionClient::enWithdraw:
			system("cls");
			clsWithdraw::ShowWithdrawScreen();
			_GoBackToTransaction();
			break;
		case clsTransactionClient::enTotalBalances:
			system("cls");
			clsTotalBalances::ShowTotalBalanceScreen();
			_GoBackToTransaction();
			break;
		case clsTransactionClient::enMainMenue:
			system("cls");
			BackToTransaction = false;
			break;
		}
	}

public:
	static void ShowTransactionScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enTransactions))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			_GoBackToMainMenu();
			return;
		}
		BackToTransaction = true;
		while (BackToTransaction)
		{
			system("cls");
			_DrawScreenHeader("Transaction screen");
			cout << "\t[1] Deposit.\n";
			cout << "\t[2] Withdraw.\n";
			cout << "\t[3] Total Balances.\n";
			cout << "\t[4] Main Menue.\n";
			cout << _TextRepeat("=", 36);
			_PerformTransaction((enTransactionOption)clsInputValidation::ReadShortNumber("\nchoose what do you want to do [1/4] :", 1, 4));
		}
	}
};

