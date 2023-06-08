#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "MyLib/clsString.h"

using namespace std;

class clsLogRegister
{
	string _Date_Time;
	string _Username;
	string _Password;
	short _Permissions;

	static clsLogRegister _GetEmptyLog()
	{
		return clsLogRegister("", "", "", 0);
	}

	static clsLogRegister _ConvertLineToLogObject(string Line)
	{
		vector <string> vData = clsString::SplitString(Line, "#||#");

		if (vData.size() == 4)
			return clsLogRegister(vData[0], vData[1], vData[2], stoi(vData[3]));

		else
			return _GetEmptyLog();
	}

	static vector <clsLogRegister> _LoadLoginRegisterFromFile()
	{
		vector <clsLogRegister> vLog;
		fstream MyFile;
		string Line;
		MyFile.open("LoginRegister.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				vLog.push_back(_ConvertLineToLogObject(Line));
			}
			MyFile.close();
		}
		return vLog;
	}

public:
	clsLogRegister(string Date_Time, string Username, string Password, short Permissions)
	{
		_Date_Time = Date_Time;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;
	}

	static vector <clsLogRegister> GetLogList()
	{
		return _LoadLoginRegisterFromFile();
	}

	string DateTime()
	{
		return _Date_Time;
	}

	string Username()
	{
		return _Username;
	}

	string Password()
	{
		return _Password;
	}

	short Permission()
	{
		return _Permissions;
	}
};

