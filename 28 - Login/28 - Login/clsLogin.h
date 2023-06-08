#pragma once
#include "cls/clsUsers.h"
#include "cls/clsMainScreen.h"
#include "cls/clsScreen.h"
#include "cls/clsInputValidation.h"
#include "Global.h"

using namespace std;

class clsLogin : protected clsScreen
{
public:
	static void ShowLoginScreen()
	{
		bool FailLogin = false;
		do {
			system("cls");

			_DrawHeder("Login Screen");

			if (FailLogin)
				cout << "\nInvalid username/password\n";

			string username = clsInputValidation::ReadString("enter username : ");
			string pass = clsInputValidation::ReadString("enter password : ");

			CurrentUser = clsUsers::Find(username, pass);

			FailLogin = CurrentUser.IsEmpy();

		} while (FailLogin);
		clsMainScreen::showMainMenue();
	}
		
};

