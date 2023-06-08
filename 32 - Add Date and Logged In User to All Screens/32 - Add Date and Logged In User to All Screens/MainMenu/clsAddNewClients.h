#pragma once
#include <iostream>
#include "Global.h"
#include "Bank/clsScreen.h"
#include "Bank/clsBank.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsAddNewClients : protected clsScreen
{
	static clsBankClient _ReadNewBankClient(string AccNum)
	{
		clsBankClient Client = clsBankClient(clsBankClient::enMode::enAddNewMode, "", "", "", "", AccNum, "", 0);
		Client.FirstName = clsInputValidation::ReadString("Entre first name : ");
		Client.LastName = clsInputValidation::ReadString("Entre last name : ");
		Client.Email = clsInputValidation::ReadString("Entre Email : ");
		Client.Phone = clsInputValidation::ReadString("Entre phone : ");
		Client.PinCode = clsInputValidation::ReadString("Entre pin code : ");
		Client.Balance = clsInputValidation::ReadDoubleNumber("Entre balance : ");

		return Client;
	}
public:
	static void ShowAddNewClientsScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enAddNewClient))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			return;
		}
		_DrawScreenHeader("Add new client screen");
		string AccNum = clsInputValidation::ReadString("Enter account number : ");
		while (!clsBankClient::Find(AccNum).IsEmpty())
		{
			AccNum = clsInputValidation::ReadString("Account Number is already exist choose another one : ");
		}
		clsBankClient Client = _ReadNewBankClient(AccNum);
		
		clsBankClient::enSaveResult SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveSuccessfull:
			cout << "\nAccount Added Successfully.\n";
			break;
		case clsBankClient::enFailSaveEmpty:
			cout << "\nFail empty client.\n";
			break;
		default:
			break;
		}
	}
};

