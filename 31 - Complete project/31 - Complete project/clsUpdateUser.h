#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsUpdateUser : protected clsScreen
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
		}
		return Permissions;
	}

	static void _ReadUpdateUser(clsUser &User)
	{		
		User.FirstName = clsInputValidation::ReadString("Entre first name : ");
		User.LastName = clsInputValidation::ReadString("Entre last name : ");
		User.Email = clsInputValidation::ReadString("Entre Email : ");
		User.Phone = clsInputValidation::ReadString("Entre phone : ");
		User.Password = clsInputValidation::ReadString("Entre Password : ");

		User.Permissions = _ReadPermissions();
	}

public :
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

		string username = clsInputValidation::ReadString("enter username : ");

		while (clsUser::Find(username).IsEmpty())
		{
			username = clsInputValidation::ReadString("username not found enter another one : ");
		}
		clsUser User = clsUser::Find(username);

		_PrintUserCard(User);

		if (clsInputValidation::ValidationYesNo("\nAre you sure you want to Update this User y/n: "))
		{
			_ReadUpdateUser(User);
			User.Update();
			cout << "\nAccount Update Successfully\n";
			_PrintUserCard(User);
		}
		else
			cout << "\nUpdate was cancelled\n";

	}
};

