#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "MyLib/clsInputValidation.h"
#include "Bank/clsBank.h"

using namespace std;

class clsDeleteClients : protected clsScreen
{
	
public :
	static void ShowDeleteClientsScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enDeleteClient))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			return;
		}
		_DrawScreenHeader("Delet Client Screen");
		string AccNum = clsInputValidation::ReadString("Enter Account Number : ");
		while (clsBankClient::Find(AccNum).IsEmpty())
		{
			AccNum = clsInputValidation::ReadString("\nAccount Number not found enter another one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccNum);

		_PrintClientCard(Client);

		if (clsInputValidation::ValidationYesNo("\nAre you sure you want to delete this client y/n: "))
		{
			Client.Delete();
			cout << "\nAccount deleted Successfully\n";	
			_PrintClientCard(Client);
		}
		else
			cout << "\ndeleted was cancelled\n";
	}
};

