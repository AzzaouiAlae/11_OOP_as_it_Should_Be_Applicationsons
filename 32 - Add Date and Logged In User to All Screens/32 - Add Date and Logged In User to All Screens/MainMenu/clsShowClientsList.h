#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "Bank/clsScreen.h"
#include "Bank/clsBank.h"

using namespace std;

class clsShowClientsList : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(11) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(9) << Client.PinCode;
		cout << "| " << left << setw(15) << Client.Balance << endl;
	}
public:

	static void ShowClientsListScreen()
	{
		if (CurrentUser.CheckPermissions(clsUser::enClientList))
		{
			_DrawScreenHeader("Access Denied! Contact your admin!");
			return;
		}
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		_DrawScreenHeader("Clients List", to_string(vClients.size()) + " Clients", 95);
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Clients Name";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(9) << "Pin Code";
		cout << "| " << left << setw(15) << "Balance";
		cout << endl <<_TextRepeat("-", 95) << endl;
		for (clsBankClient C : vClients)		
			_PrintClient(C);
		
		cout << endl << _TextRepeat("-", 95) << endl;
	}
};

