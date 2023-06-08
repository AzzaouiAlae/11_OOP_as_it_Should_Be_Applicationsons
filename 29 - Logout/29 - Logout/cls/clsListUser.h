#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUsers.h"

using namespace std;

class clsListUser : protected clsScreen
{
	static void _PrintUser(clsUsers User)
	{
		cout << "| " << left << setw(12) << User.FirstName;
		cout << "| " << left << setw(12) << User.LastName;
		cout << "| " << left << setw(24) << User.Email;
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(10) << User.Username();
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << User.Permission << endl;
	}
	public:
		static void ShowListUsers()
		{
			vector <clsUsers> vUsers = clsUsers::GetUsersList();
			_DrawHeder(110, "Liste Users Screen (" + to_string(vUsers.size()) + ") User(s)");
			cout << "| " << left << setw(12) << "First name";
			cout << "| " << left << setw(12) << "Last name";
			cout << "| " << left << setw(24) << "email";
			cout << "| " << left << setw(12) << "phone";
			cout << "| " << left << setw(10) << "username";
			cout << "| " << left << setw(10) << "password";
			cout << "| " << "permission\n";
			cout << WriteLetters(110, "-") << endl;

			for (clsUsers& U : vUsers)			
				_PrintUser(U);
			
			cout << WriteLetters(110, "-") << endl;

		}
};

