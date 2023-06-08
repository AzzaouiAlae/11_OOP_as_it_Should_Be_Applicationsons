#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "MyLib/clsInputValidation.h"

class clsFindUser : protected clsScreen
{
public:
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find user screen");
		string username = clsInputValidation::ReadString("Enter username : ");

		while (clsUser::Find(username).IsEmpty())
		{
			username = clsInputValidation::ReadString("username is already exist choose another one : ");
		}
		_PrintUserCard(clsUser::Find(username));
	}
};

