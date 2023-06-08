#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include "clsBank.h"
#include "clsUser.h"
#include "Global.h"
#include <ctime>

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

	static void _PrintUsername(short HeaderLong)
	{
		string username = "User : " + CurrentUser.Username();

		cout << username ;
	}

	static void _PrintDatetime(short HeaderLong)
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		string Date = "Date : " + to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);

		string username = "User : " + CurrentUser.Username();

		short NumOfSpace = (HeaderLong - Date.size() - username.size());

		cout << _TextRepeat(" ", NumOfSpace) << Date << endl << endl;
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

		_PrintUsername(HeaderLong);

		_PrintDatetime(HeaderLong);
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

	static void _PrintClientTransferCard(clsBankClient Client)
	{
		cout << "\n\nClient Card\n";
		cout << _TextRepeat("-", 30) << endl;		
		cout << "Client Name     : " << Client.FullName() << endl;
		cout << "Account Number  : " << Client.AccountNumber() << endl;		
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

