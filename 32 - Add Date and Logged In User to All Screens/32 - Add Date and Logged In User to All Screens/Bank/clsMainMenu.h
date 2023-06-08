#pragma once
#include <iostream>
#include "clsScreen.h"
#include "MyLib/clsInputValidation.h"
#include "MainMenu/clsShowClientsList.h"
#include "MainMenu/clsAddNewClients.h"
#include "MainMenu/clsDeleteClients.h"
#include "MainMenu/clsUpdateClient.h"
#include "MainMenu/clsFindClient.h"
#include "MainMenu/clsManageUsers.h"
#include "MainMenu/clsTransactionClient.h"
#include "MainMenu/clsManageUsers.h"
#include "clsLoginRegisterScreen.h"
#include "clsShowCurrencyScreen.h"

bool BackToMain = true;

using namespace std;

class clsMainMenu : protected clsScreen
{
	enum enPerformMainOption{
		enList = 1, enAddNew = 2, enDelete = 3, enUpdate = 4, enFind = 5, enTransactions = 6, enManageUsers = 7, enLoginRegister = 8, enCurrency = 9, enLogout = 10
	};

	static void _PerformMainMenu(enPerformMainOption Option)
	{
		switch (Option)
		{
		case clsMainMenu::enList:
			system("cls");
			clsShowClientsList::ShowClientsListScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenu::enAddNew:
			system("cls");
			clsAddNewClients::ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenu::enDelete:
			system("cls");
			clsDeleteClients::ShowDeleteClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenu::enUpdate:
			system("cls");
			clsUpdateClient::ShowUpdateClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenu::enFind:
			system("cls");
			clsFindClient::ShowFindClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenu::enTransactions:
			system("cls");
			clsTransactionClient::ShowTransactionScreen();			
			break;
		case clsMainMenu::enManageUsers:
			system("cls");
			clsManageUsers::ShowManageUsersScreen();			
			break;
		case enLoginRegister:
			system("cls");
			clsLoginRegister::ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		case enCurrency:
			system("cls");			
			clsShowCurrencyScreen::ShowCurrencyScreen();
			break;
		case clsMainMenu::enLogout:
			BackToMain = false;
			CurrentUser = clsUser::Find("");			
			break;		
		}
	}
public:
	static void ShowMainMenuScreen()
	{
		BackToMain = true;

		while (BackToMain)
		{
			system("cls");

			_DrawScreenHeader("Main Menu Screen");
			cout << "\t[1] Show clients List.\n";
			cout << "\t[2] Add New Client.\n";
			cout << "\t[3] Delete Client.\n";
			cout << "\t[4] Update Client Info.\n";
			cout << "\t[5] Find Client.\n";
			cout << "\t[6] Transactions.\n";
			cout << "\t[7] Manage Users.\n";
			cout << "\t[8] Login Register.\n";
			cout << "\t[9] Currency Exchange.\n";
			cout << "\t[10] Logout.\n";
			cout << _TextRepeat("=", 36);
			_PerformMainMenu(enPerformMainOption(clsInputValidation::ReadShortNumber("\nChoose what do you want to do [1/10] : ", 1, 10)));
		}
	}
};

