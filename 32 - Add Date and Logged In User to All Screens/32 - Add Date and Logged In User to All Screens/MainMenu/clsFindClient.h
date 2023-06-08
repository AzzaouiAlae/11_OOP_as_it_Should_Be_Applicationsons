#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsFindClient : protected clsScreen
{
	
public:
	static void ShowFindClientsScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enFindClient))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			return;
		}
		_DrawScreenHeader("Find client screen");
		string AccNum = clsInputValidation::ReadString("enter Account Number : ");
		while (clsBankClient::Find(AccNum).IsEmpty())
		{
			AccNum = clsInputValidation::ReadString("\nAccount Number not found enter another one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccNum);
		_PrintClientCard(Client);
	}
};

