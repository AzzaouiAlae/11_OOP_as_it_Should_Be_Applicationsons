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

	static clsUsers _GetEmptyUser()
	{
		return clsUsers(EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUsers _ConvertLineToObjectUser(string Line, string Delim = "#||#")
	{
		vector <string> vData = clsString::SplitString(Line, Delim);
		if (vData.size() == 7)
		{
			clsUsers User = clsUsers(UpdatedMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stod(vData[6]));
			return User;
		}
		else
			return _GetEmptyUser();
	}

	static string _ConvertObjectUserToLine(clsUsers User, string Delim = "#||#")
	{
		return User.FirstName + Delim +
			User.LastName + Delim + User.Email + Delim +
			User.Phone + Delim + User.Username() + Delim +
			User.Password + Delim + to_string(User.Permission);
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
				clsUsers User = _ConvertLineToObjectUser(Line);
				Usesrs.push_back(User);
			}
			MyFile.close();
		}
		return Usesrs;
	}

	static void _SaveUsersDataToFile(vector <clsUsers> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		string Line;
		if (MyFile.is_open())
		{
			for (clsUsers& U : vUsers)
			{
				if (!U.MarkForDeleted())
				{
					Line = _ConvertObjectUserToLine(U);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	static void _AddNewLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	void _UpdateObjectUser()
	{
		vector <clsUsers> vUsers = _LoadUsersListFromFile();
		for (clsUsers& U : vUsers)
		{
			if (U.Username() == Username())
				U = *this;
		}
		_SaveUsersDataToFile(vUsers);
	}


public:
	enum enPermission {
		eAll = -1, enPerListClient = 1, enPerAddNew = 2, enPerDelete = 4,
		enPerUpdate = 8, enPerFind = 16, enPerTransactions = 32, enPerManage = 64
	}; 

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

	bool MarkForDeleted()
	{
		return _MarkForDeleted;
	}

	static clsUsers Find(string username)
	{
		vector <clsUsers> Users = _LoadUsersListFromFile();
		for (clsUsers U : Users)
		{
			if (U.Username() == username)
			{
				return U;
			}
		}
		return _GetEmptyUser();
	}

	static vector <clsUsers> GetUsersList()
	{
		return _LoadUsersListFromFile();
	}

	static clsUsers GetAddNewUser(string Username)
	{
		return clsUsers(AddNewMode, "", "", "", "", Username, "", 0);
	}

	enum enSaveResult {
		enFailEmptyUser, enFailUserExist, enSucceeded
	};

	bool Delete()
	{
		_MarkForDeleted = true;
		vector <clsUsers> vUsers = _LoadUsersListFromFile();

		for (clsUsers& U : vUsers)
		{
			if (U.Username() == Username())
				U = *this;
		}
		_SaveUsersDataToFile(vUsers);

		*this = _GetEmptyUser();

		return true;
	}

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case EmptyMode:
			return enFailEmptyUser;

		case UpdatedMode:
		{
			_UpdateObjectUser();
			return enSucceeded;
		}

		case AddNewMode:
		{
			if (IsUserExist(Username()))
				return enFailUserExist;

			else
			{
				_AddNewLineToFile(_ConvertObjectUserToLine(*this));
				_Mode = UpdatedMode;
				return enSucceeded;
			}
		}
		}
	}

	static bool IsUserExist(string username)
	{
		return (!Find(username).IsEmpy());
	}

	static clsUsers AddNewUser(string Username)
	{
		return clsUsers(AddNewMode, "", "", "", "", Username, "", -1);
	}
};