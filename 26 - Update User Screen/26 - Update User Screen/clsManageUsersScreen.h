#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsListUser.h"
#include "clsAddNewUsers.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUsersScreen.h"

using namespace std;

bool BackToManageMeune = true;

class clsManageUsersScreen : protected clsScreen
{
	enum enManageUserOption {
		eList = 1, eAddNew = 2, eDelete = 3, eUpdate = 4, eFind = 5, eMainMeune = 6
	};

	static void _GoBackToManageUserMeune()
	{
		cout << "\nPress any key to return to Manage User Meune...";
		system("pause>0");
	}

	static void _ListUser()
	{
		//cout << "List Users will be here\n";
		clsListUser::ShowListUsers();
	}

	static void _AddNewUser()
	{
		//cout << "Add New Users will be here\n";
		clsAddNewUsers::ShowAddNewClientUser();
	}

	static void _DeleteUsers()
	{
		//cout << "Delete Users will be here\n";
		clsDeleteUserScreen::DeleteUsers();
	}

	static void _UpdateUsers()
	{
		//cout << "Update Users will be here\n";
		clsUpdateUsersScreen::ShowUpdateUserScreen();
	}

	static void _FindUsers()
	{
		//cout << "Find Users will be here\n";
	}

	static void _PerformManageUser(enManageUserOption Option)
	{
		switch (Option)
		{
		case eList:
			system("cls");
			_ListUser();
			_GoBackToManageUserMeune();
			break;

		case eAddNew:
			system("cls");
			_AddNewUser();
			_GoBackToManageUserMeune();
			break;

		case eDelete:
			system("cls");
			_DeleteUsers();
			_GoBackToManageUserMeune();
			break;

		case eUpdate:
			system("cls");
			_UpdateUsers();
			_GoBackToManageUserMeune();
			break;

		case eFind:
			system("cls");
			_FindUsers();
			_GoBackToManageUserMeune();
			break;

		case eMainMeune:
			BackToManageMeune = false;
			break;
		}
	}
public:
	static void ShowManageUserScreen()
	{
		BackToManageMeune = true;
		while (BackToManageMeune)
		{
			system("cls");

			_DrawHeder("Manage User Screen");

			cout << "\t[1] List Users.\n";
			cout << "\t[2] Add new user.\n";
			cout << "\t[3] Delete user.\n";
			cout << "\t[4] Update Users.\n";
			cout << "\t[5] Find Users.\n";
			cout << "\t[6] Main Meune.\n";
			cout << "===================================\n";
			_PerformManageUser(enManageUserOption(clsInputValidation::ReadShortNumber("choose what do you want to do [1/6] : ", 1, 6)));
		}
		

	}
};

