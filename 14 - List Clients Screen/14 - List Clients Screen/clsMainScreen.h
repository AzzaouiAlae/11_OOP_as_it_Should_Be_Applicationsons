#pragma once
#include <iostream>
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsClientList.h"

using namespace std;

bool _BackToMain = true;

class clsMainScreen : protected clsScreen
{	
	enum enMainMenueOption {
		eClientList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5,  eTransactions = 6, eManageUsers = 7, eLogout = 8
	};

	static void _GoBackToMainMenue()
	{
		cout << "\nPress any key to go back to main Menue...";
		system("pause>0");
	}

	static void _ShowClientList()
	{
		//cout << "\tClient List will be here\n";
		clsClientList::ShowClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		cout << "\tAdd New Client Screen will be here\n";
	}

	static void _ShowDeleteClientScreen()
	{
		cout << "\tDelete Client Screen will be here\n";
	}

	static void _ShowUpdateClientScreen()
	{
		cout << "\tUpdate Client Screen will be here\n";
	}

	static void _ShowFindClientScreen()
	{
		cout << "\tFind Client Screen will be here\n";
	}

	static void _ShowTransactionScreen()
	{
		cout << "\tTransaction Screen will be here\n";
	}

	static void _ShowManageUsersScreen()
	{
		cout << "\tManage Users Screen will be here\n";
	}

	static void _PerfromMainMenuOption(enMainMenueOption Option)
	{
		system("cls");

		switch (Option)
		{
		case eClientList:
			_ShowClientList();
			_GoBackToMainMenue();
			break;

		case eAddNewClient:
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;

		case eDeleteClient:
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case eUpdateClient:
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case eFindClient:
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;

		case eTransactions:
			_ShowTransactionScreen();
			_GoBackToMainMenue();
			break;

		case eManageUsers:
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;

		case eLogout:
			_BackToMain = false;
			break;
		}
	}	
	
public:
	static void showMainMenue()
	{
		while (_BackToMain)
		{
			system("cls");

			_DrawHeder("Main Menue Screen");

			cout << "\t[1] Show clients List.\n";
			cout << "\t[2] Add New Client.\n";
			cout << "\t[3] Delete Client.\n";
			cout << "\t[4] Update Client Info.\n";
			cout << "\t[5] Find Client.\n";
			cout << "\t[6] Transactions.\n";
			cout << "\t[7] Manage Users.\n";
			cout << "\t[8] Logout.\n";
			cout << "===================================\n";
			string msg = "choose what do you want to do [1/8] : ";
			_PerfromMainMenuOption(enMainMenueOption(clsInputValidation::ReadShortNumber(msg, 1, 8)));
		}	
	}
};

