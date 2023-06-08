#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "Bank/clsBank.h"
#include "Transaction/clsDeposit.h"
#include "Transaction/clsWithdraw.h"
#include "Transaction/clsTotalBalances.h"
#include "MyLib/clsInputValidation.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

bool BackToTransaction = true;

class clsTransactionClient : protected clsScreen
{
	enum enTransactionOption {
		enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enTransfer = 4 , enTransferLog = 5, enMainMenue = 6
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
		case clsTransactionClient::enTransfer:
			system("cls");
			clsTransferScreen::ShowTransferScreen();
			_GoBackToTransaction();
			break;
		case clsTransactionClient::enTransferLog:
			system("cls");
			clsTransferLogScreen::ShowTransferLogScreen();
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
			cout << "\t[4] Transfer.\n";
			cout << "\t[5] Transfer Log.\n";
			cout << "\t[6] Main Menue.\n";
			cout << _TextRepeat("=", 36);
			_PerformTransaction((enTransactionOption)clsInputValidation::ReadShortNumber("\nchoose what do you want to do [1/6] :", 1, 6));
		}
	}
};

