#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "MyLib/clsString.h"
#include "MyLib/clsDate.h"
#include "MyLib/clsUtility.h"

using namespace std;

class clsUser : public clsPerson
{
public : enum enMode {
		enEmptyMode, enUpdateMode, enAddNewMode
	};

private : 
	string _Username;
	string _Password;
	short _Permissions;
	enMode _Mode;
	bool MarkForDelete = false;

	string _PerperLogInRecord()
	{
		string LogLine = clsDate::GetDateTimeNow() + "#||#"
			+ Username() + "#||#" + Password + "#||#" + to_string(Permissions);

		return LogLine;
	}

	static clsUser _ConvertLineToUser(string Line)
	{
		vector <string> vData = clsString::SplitString(Line, "#||#");

		clsUtility::DecryptText(vData[5], 2);

		return clsUser(enUpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stoi(vData[6]));
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		string Line;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUser(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static void _SaveUserDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsUser U : vUsers)
			{
				if (!U.MarkForDelete)			
					MyFile << _ConvertUserToLine(U) << endl;
			}
			MyFile.close();
		}
	}

	static clsUser _GetEmptyUser()
	{
		return clsUser(enEmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertUserToLine(clsUser User)
	{
		string Pass = User.Password;
		clsUtility::EncryptText(Pass, 2);
		return User.FirstName + "#||#" + User.LastName + "#||#" + User.Email + "#||#" + User.Phone + "#||#"
			+ User.Username() + "#||#" + Pass + "#||#" + to_string(User.Permissions);
	}

	static void _AddNewLineToFile(clsUser User)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << _ConvertUserToLine(User) << endl;
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser &U : vUsers)
		{
			if (U.Username() == Username())
			{
				U = *this;
				break;
			}
		}
		_SaveUserDataToFile(vUsers);
	}

public:
	clsUser(enMode mode, string firstName, string lastName, string email, string phone, string username, string password, short permissions) : 
		clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		_Username = username;
		_Password = password;
		_Permissions = permissions;
	}

	void RegisterLogIn()
	{
		string Line = _PerperLogInRecord();

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::app | ios::out);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	enum enPermissions {
		enClientList = 1, enAddNewClient = 2, enDeleteClient = 4, enUpdateClient = 8, enFindClient = 16, enTransactions = 32, enManageUser = 64, enLogRegister = 128
	};

	string Username()
	{
		return _Username;
	}

	void setPassword(string password)
	{
		_Password = password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = setPassword)) string Password;

	void SetPermissions(short permissions)
	{
		_Permissions = permissions;
	}
	short GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	void SetMode(enMode mode)
	{
		_Mode = mode;
	}
	enMode GetMode()
	{
		return _Mode;
	}
	__declspec(property(get = GetMode, put = SetMode)) enMode Mode;

	bool IsEmpty()
	{
		return _Mode == enEmptyMode;
	}

	static clsUser Find(string Username)
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser U : vUsers)
		{
			if (U.Username() == Username)
				return U;
		}
		return _GetEmptyUser();
	}

	static clsUser Find(string Username, string Password)
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser U : vUsers)
		{
			if (U.Username() == Username && U.Password == Password)
				return U;
		}
		return _GetEmptyUser();
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckPermissions(enPermissions PermissionsOf_)
	{
		if (Permissions == -1)
			return false;
		
		return !((PermissionsOf_ & Permissions) == PermissionsOf_);
	}

	enum enSaveResult {
		enSuccessful, enFailEmpty, enFailExiste
	};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsUser::enEmptyMode:
			return enFailEmpty;
			
		case clsUser::enUpdateMode:
			_Update();
			return enSuccessful;
			
		case clsUser::enAddNewMode:		
			_AddNewLineToFile(*this);
			return enSuccessful;
		}
		
	}

	void Delete()
	{
		MarkForDelete = true;		

		_Update();

		*this = _GetEmptyUser();
	}

	void Update()
	{
		_Update();
	}


};

