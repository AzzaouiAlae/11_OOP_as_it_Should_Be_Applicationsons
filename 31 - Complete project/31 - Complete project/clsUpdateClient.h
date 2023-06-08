#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBank.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsUpdateClient : protected clsScreen
{	
	static void _ReadClientInfo(clsBankClient &Client)
	{
		Client.FirstName = clsInputValidation::ReadString("Enter First name : ");
		Client.LastName = clsInputValidation::ReadString("Enter Last name : ");
		Client.Phone = clsInputValidation::ReadString("Enter Phone : ");
		Client.Email = clsInputValidation::ReadString("Enter Email : ");
		Client.PinCode = clsInputValidation::ReadString("Enter Pin Code : ");
		Client.Balance = clsInputValidation::ReadDoubleNumber("enter Balance : ");
	}
public :
	static void ShowUpdateClientsScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enUpdateClient))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			return;
		}
		_DrawScreenHeader("Update client screen");
		string AccNum = clsInputValidation::ReadString("enter account number : ");

		while (clsBankClient::Find(AccNum).IsEmpty())
		{
			AccNum = clsInputValidation::ReadString("Account Number not found enter another one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccNum);

		_PrintClientCard(Client);

		if (clsInputValidation::ValidationYesNo("\nAre you sure you want to update this client y/n : "))
		{
			_ReadClientInfo(Client);
			Client.Save();
			cout << "\nAccount updated successfully\n";
		}
	}
};

