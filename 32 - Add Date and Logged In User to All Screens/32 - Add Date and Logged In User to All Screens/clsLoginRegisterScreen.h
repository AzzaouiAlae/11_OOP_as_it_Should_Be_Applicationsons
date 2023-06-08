#pragma once
#include <iostream>
#include "Bank/clsUser.h"
#include "Bank/clsScreen.h"
#include <iomanip>
#include "clsLogRegister.h"

using namespace std;

class clsLoginRegister : protected clsScreen
{
	static void _PrintLogObject(clsLogRegister Log)
	{
		cout << "| " << left << setw(30) << Log.DateTime();
		cout << "| " << left << setw(20) << Log.Username();
		cout << "| " << left << setw(20) << Log.Password();
		cout << "| " << Log.Permission() << endl;
	}

public:
	static void ShowLoginRegisterScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enLogRegister))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			return;
		}

		_DrawScreenHeader("Login Register", "", 90);
		cout << _TextRepeat("-", 90) << endl;
		cout << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << "Permissions";
		cout << "\n" << _TextRepeat("-", 90) << endl;
		vector <clsLogRegister> vLog = clsLogRegister::GetLogList();
		for (clsLogRegister Log : vLog)
		{
			_PrintLogObject(Log);
		}
		cout << "\n" << _TextRepeat("-", 90) << endl;
	}
};

