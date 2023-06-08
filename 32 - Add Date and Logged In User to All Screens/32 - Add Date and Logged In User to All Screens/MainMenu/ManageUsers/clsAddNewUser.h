#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "Bank/clsUser.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsAddNewUser : protected clsScreen
{
	static short _ReadPermissions()
	{
		short Permissions = 0;

		if (clsInputValidation::ValidationYesNo("Do you want to give full access y/n : "))
		{
			Permissions = -1;
			return Permissions;
		}
		else
		{
			if (clsInputValidation::ValidationYesNo("Do you want to give access to client list y/n : "))			
				Permissions += clsUser::enClientList;
			
			if (clsInputValidation::ValidationYesNo("Do you want to give access to add new clients y/n : "))
				Permissions += clsUser::enAddNewClient;

			if (clsInputValidation::ValidationYesNo("Do you want to give access to delete client y/n : "))
				Permissions += clsUser::enDeleteClient;

			if (clsInputValidation::ValidationYesNo("Do you want to give access to update client info y/n : "))
				Permissions += clsUser::enUpdateClient;

			if (clsInputValidation::ValidationYesNo("Do you want to give access to find client y/n : "))
				Permissions += clsUser::enFindClient;

			if (clsInputValidation::ValidationYesNo("Do you want to give access to transactions y/n : "))
				Permissions += clsUser::enTransactions;

			if (clsInputValidation::ValidationYesNo("Do you want to give access to Manage Users y/n : "))
				Permissions += clsUser::enManageUser;

			if (clsInputValidation::ValidationYesNo("Do you want to give access to Login Register y/n : "))
				Permissions += clsUser::enLogRegister;
		}
		return Permissions;
	}

	static clsUser _ReadNewBankClient(string username)
	{
		clsUser User = clsUser(clsUser::enAddNewMode, "", "", "", "", username, "", 0);
		User.FirstName = clsInputValidation::ReadString("Entre first name : ");
		User.LastName = clsInputValidation::ReadString("Entre last name : ");
		User.Email = clsInputValidation::ReadString("Entre Email : ");
		User.Phone = clsInputValidation::ReadString("Entre phone : ");
		User.Password = clsInputValidation::ReadString("Entre Password : ");
		User.Permissions = _ReadPermissions();

		return User;
	}
public:
	static void ShowAddNewUsersScreen()
	{
		_DrawScreenHeader("Add new user");
		string username = clsInputValidation::ReadString("enter username : ");
		while (!clsUser::Find(username).IsEmpty())
		{
			username = clsInputValidation::ReadString("username is already exist choose another one : ");
		}
		clsUser User = _ReadNewBankClient(username);
		clsUser::enSaveResult Result;
		Result = User.Save();

		if (Result == clsUser::enSuccessful)
		{
			cout << "\nUser Added successfully\n\n";
			_PrintUserCard(User);
		}
	}
};