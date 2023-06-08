#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsDeleteUsers : protected clsScreen
{
public:
	static void ShowDeleteUsersScreen()
	{
		_DrawScreenHeader("Delete Users Screen");
		string username = clsInputValidation::ReadString("enter username : ");

		while (clsUser::Find(username).IsEmpty())
		{
			username = clsInputValidation::ReadString("username not found enter another one : ");
		}
		clsUser User = clsUser::Find(username);

		_PrintUserCard(User);

		if (clsInputValidation::ValidationYesNo("\nAre you sure you want to delete this User y/n: "))
		{
			User.Delete();
			cout << "\nAccount deleted Successfully\n";
			_PrintUserCard(User);
		}
		else
			cout << "\ndeleted was cancelled\n";

		
	}
};

