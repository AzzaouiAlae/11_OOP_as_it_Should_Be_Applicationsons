#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidation.h"

using namespace std;

class clsAddNewUsers : protected clsScreen
{
	static void _ReadNewUser(clsUsers &User)
	{
		User.FirstName = clsInputValidation::ReadString("Enter First Name : ");

		User.LastName = clsInputValidation::ReadString("Enter Last Name : ");

		User.Email = clsInputValidation::ReadString("Enter Email : ");

		User.Phone = clsInputValidation::ReadString("Enter Phone : ");

		User.Password = clsInputValidation::ReadString("Enter Password : ");

		if(clsInputValidation::ValidationYesNo("Do you want to give full access y/n : "))
			User.Permission = -1;
		else
		{
			if (clsInputValidation::ValidationYesNo("Client List y/n : "))
				User.Permission += clsUsers::enPerListClient;

			if (clsInputValidation::ValidationYesNo("Add New Client y/n : "))
				User.Permission += clsUsers::enPerAddNew;

			if (clsInputValidation::ValidationYesNo("Delete Client y/n : "))
				User.Permission += clsUsers::enPerDelete;

			if (clsInputValidation::ValidationYesNo("Update Client Info : "))
				User.Permission += clsUsers::enPerUpdate;

			if (clsInputValidation::ValidationYesNo("Find Client y/n : "))
				User.Permission += clsUsers::enPerFind;

			if (clsInputValidation::ValidationYesNo("Transactions y/n : "))
				User.Permission += clsUsers::enPerTransactions;

			if (clsInputValidation::ValidationYesNo("Manage users y/n : "))
				User.Permission += clsUsers::enPerManage;
		}

	}
public:
	static void ShowAddNewClientUser()
	{
		do {
			system("cls");
			_DrawHeder("Add New User Screen");
			string Username = clsInputValidation::ReadString("Enter username :");

			while (clsUsers::IsUserExist(Username))
			{
				Username = clsInputValidation::ReadString("Username alredy exists,enter another one : ");
			}

			clsUsers User = clsUsers::AddNewUser(Username);

			_ReadNewUser(User);

			if (User.Save() == clsUsers::enSucceeded)
			{
				cout << "\nUser Added successfully\n";
				_PrintUserCard(User);
			}

			else if (User.Save() == clsUsers::enFailEmptyUser)
				cout << "\nUser is Empty\n";

			else if (User.Save() == clsUsers::enFailUserExist)
				cout << "\nUsername alredy exists\n";
			
		} while (clsInputValidation::ValidationYesNo("\nDo you want to add another user y/n : "));
		
		
	}
};

