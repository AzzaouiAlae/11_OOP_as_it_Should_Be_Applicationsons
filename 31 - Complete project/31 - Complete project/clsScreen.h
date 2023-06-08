#pragma once
#include <iostream>
#include "clsBank.h"
#include "clsUser.h"

using namespace std;

class clsScreen
{
public:
	static string _TextRepeat(string Text, short Repeats)
	{
		string text = "";
		for(short i = 0; i < Repeats; i++)
		{
			text += Text;
		}
		return text;
	}

	static void _GoBackToMainMenu()
	{
		cout << "\n\nPress any key to go back to main menu...";
		system("pause>0");
	}

	static void _DrawScreenHeader(string Title, string subTitle = "", short HeaderLong = 36)
	{
		short NumOfSpace;	
		
		cout << _TextRepeat("=", HeaderLong) << endl;

		NumOfSpace = (HeaderLong - Title.size()) / 2;
		cout << _TextRepeat(" ", NumOfSpace) << Title << endl;
		if (subTitle != "")
		{
			NumOfSpace = (HeaderLong - subTitle.size()) / 2;
			cout << _TextRepeat(" ", NumOfSpace) << subTitle << endl;
		}
		cout << _TextRepeat("=", HeaderLong) << endl;
	}

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n\nClient Card\n";
		cout << _TextRepeat("-", 30) << endl;
		cout << "Account Number  : " << Client.AccountNumber() << endl;
		cout << "Client Name     : " << Client.FullName() << endl;
		cout << "Phone           : " << Client.Phone << endl;
		cout << "Email           : " << Client.Email << endl;
		cout << "Pin Code        : " << Client.PinCode << endl;
		cout << "Account Balance : " << Client.Balance << endl;
		cout << _TextRepeat("-", 30) << endl;
	}	

	static void _PrintUserCard(clsUser User)
	{
		cout << "\n\nUser Card\n";
		cout << _TextRepeat("-", 30) << endl;
		cout << "Username    : " << User.Username() << endl;
		cout << "User Name   : " << User.FullName() << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Password    : " << User.Password << endl;
		cout << "Permissions : " << User.Permissions << endl;
		cout << _TextRepeat("-", 30) << endl;
	}
};

