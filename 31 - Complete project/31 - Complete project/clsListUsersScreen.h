#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsListUsersScreen : protected clsScreen
{
	static void _PrintUser(clsUser User)
	{
		cout << "| " << left << setw(12) << User.FirstName;
		cout << "| " << left << setw(12) << User.LastName;
		cout << "| " << left << setw(25) << User.Email;
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(12) << User.Username();
		cout << "| " << left << setw(12) << User.Password;
		cout << "| " << left << setw(15) << User.Permissions << endl;		
	}

public :
	static void ShowListUsersScreen()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();
		_DrawScreenHeader("List users screen", "(" + to_string(vUsers.size()) + ") User(s)", 110);

		cout << "| " << left << setw(12) << "FirstName";
		cout << "| " << left << setw(12) << "LastName";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Username";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(15) << "Permissions";
		cout << endl <<_TextRepeat("-", 110) << endl;

		for (clsUser U : vUsers)		
			_PrintUser(U);
		
		cout << endl << _TextRepeat("-", 110) << endl;
	}
};