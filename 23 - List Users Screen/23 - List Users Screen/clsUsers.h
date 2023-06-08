#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsUsers : public clsPerson
{
	enum enMode {
		EmptyMode = 0, UpdatedMode = 1, AddNewMode = 2
	};

	enMode _Mode;
	string _Username;
	string _Password;
	short _permission;

	bool _MarkForDeleted = false;

	static clsUsers _GetEmptyMode()
	{
		return clsUsers(EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUsers ConvertLineToObjectUser(string Line, string Delim = "#||#")
	{
		vector <string> vData = clsString::SplitString(Line, Delim);
		if (vData.size() == 7)
		{
			clsUsers User = clsUsers(UpdatedMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stod(vData[6]));
			return User;
		}
		else
			return _GetEmptyMode();
	}

	static vector <clsUsers> _LoadUsersListFromFile()
	{
		vector <clsUsers> Usesrs;

		fstream MyFile;
		string Line;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsUsers User = ConvertLineToObjectUser(Line);
				Usesrs.push_back(User);
			}
			MyFile.close();
		}
		return Usesrs;
	}

public:
	clsUsers(enMode mode, string firstName, string lastName, string email, string phone, string username, string password, short permission) 
		: clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		_Username = username;
		_Password = password;
		_permission = permission;
	}

	bool IsEmpy()
	{
		return _Mode == EmptyMode;
	}

	void SetMode(enMode mode)
	{
		_Mode = mode;
	}
	enMode GetMode()
	{
		return _Mode;
	}
	__declspec(property(get = GetMode, put = SetMode)) enMode Mode;

	string Username()
	{
		return _Username;
	}

	void SetPassword(string Pass)
	{
		_Password = Pass;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermission(double permission)
	{
		_permission = permission;
	}
	double GetPermission()
	{
		return _permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission)) double Permission;

	static vector <clsUsers> GetUsersList()
	{
		return _LoadUsersListFromFile();
	}
	


};
