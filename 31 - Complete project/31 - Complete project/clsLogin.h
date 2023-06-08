#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "MyLib/clsInputValidation.h"
#include "clsScreen.h"
#include "clsMainMenu.h"

using namespace std;

class clsLogin : protected clsScreen
{
	static void _Login()
	{
		string Username = clsInputValidation::ReadString("enter username : ");
		string Password = clsInputValidation::ReadString("enter password : ");
		CurrentUser = clsUser::Find(Username, Password);
	}
public:
	static void Login()
	{	
		bool FailLogin = false;
		do {
			system("cls");
			clsScreen::_DrawScreenHeader("Login screen");
			if (FailLogin)
				cout << "Invalid username/password\n";

			_Login();

			FailLogin = CurrentUser.IsEmpty();

		} while (FailLogin);
		clsMainMenu::ShowMainMenuScreen();
	}
};

