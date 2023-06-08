#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "ManageUsers/clsListUsersScreen.h"
#include "ManageUsers/clsAddNewUser.h"
#include "MyLib/clsInputValidation.h"
#include "ManageUsers/clsDeleteUsers.h"
#include "ManageUsers/clsUpdateUser.h"
#include "ManageUsers/clsFindUser.h"

bool ManageUsers = true;

using namespace std;

class clsManageUsers : protected clsScreen
{
	enum enPerformUsersOption {
		enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, enMainMeune = 6,
	};
	static void _GoBackToMainMenu()
	{
		cout << "\n\nPress any key to go back to manage users...";
		system("pause>0");
	}

	static void _PerformManageUsers(enPerformUsersOption Option)
	{
		switch (Option)
		{
		case clsManageUsers::enListUsers:
			system("cls");
			clsListUsersScreen::ShowListUsersScreen();
			_GoBackToMainMenu();
			break;
		case clsManageUsers::enAddNewUser:
			system("cls");
			clsAddNewUser::ShowAddNewUsersScreen();
			_GoBackToMainMenu();
			break;
		case clsManageUsers::enDeleteUser:
			system("cls");
			clsDeleteUsers::ShowDeleteUsersScreen();
			_GoBackToMainMenu();
			break;
		case clsManageUsers::enUpdateUser:
			system("cls");
			clsUpdateUser::ShowUpdateUserScreen();
			_GoBackToMainMenu();
			break;
		case clsManageUsers::enFindUser:
			clsFindUser::ShowFindUserScreen();
			break;
		case clsManageUsers::enMainMeune:
			ManageUsers = false;
			break;		
		}
	}

public:
	static void ShowManageUsersScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enManageUser))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			_GoBackToMainMenu();
			return;
		}

		ManageUsers = true;
		while (ManageUsers)
		{
			system("cls");
			_DrawScreenHeader("Manage Users Screen");
			cout << "\t[1] List Users.\n";
			cout << "\t[2] Add new user.\n";
			cout << "\t[3] Delete user.\n";
			cout << "\t[4] Update Users.\n";
			cout << "\t[5] Find Users.\n";
			cout << "\t[6] Main Meune.\n";
			cout << _TextRepeat("-", 36) << endl;

			_PerformManageUsers((enPerformUsersOption)clsInputValidation::ReadDoubleNumber("choose what do you want to do[1 / 6] : ", 1, 6));
		}
	}
};

