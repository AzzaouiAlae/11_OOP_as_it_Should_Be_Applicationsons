#pragma once
#include <iostream>
#include "Bank/clsUser.h"
#include "Global.h"
#include "MyLib/clsInputValidation.h"
#include "Bank/clsScreen.h"
#include "Bank/clsMainMenu.h"
#include "MyLib/clsDate.h"

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
	static bool Login()
	{
		bool FailLogin = false;
		short CountFails = 0;
		clsScreen::_DrawScreenHeader("Login screen");
		do {
			if (FailLogin)
			{
				CountFails++;
				cout << "\nInvalid username/password\n";
				cout << "You have " << (3-CountFails) << " trial(s) to login\n\n";
				if (CountFails == 3)
				{
					cout << "\n\nyou are loked after 3 faild trails\n";
					return false;
				}
			}
			_Login();
			FailLogin = CurrentUser.IsEmpty();
		} while (FailLogin);
		CurrentUser.RegisterLogIn();
		clsMainMenu::ShowMainMenuScreen();
		system("cls");
		return true;
	}
};

