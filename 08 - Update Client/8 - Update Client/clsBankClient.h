#pragma once
#include <iostream>
#include "clsString.h"
#include "clsPerson.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
	enum enMode {
		EmptyMode = 1, UpdateMode = 2
	};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _GetEmtyClientObject()
	{
		return clsBankClient(EmptyMode,	"", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLineToCientObject(string Line)
	{
		vector <string> vClitObj = clsString::SplitString(Line, "#||#");
		if (vClitObj.size() == 7)
		{
			return clsBankClient(UpdateMode, vClitObj[0], vClitObj[1], vClitObj[2], vClitObj[3], vClitObj[4],
				vClitObj[5], stof(vClitObj[6]));
		}
		return _GetEmtyClientObject();
	}

	static vector <clsBankClient> _LoadDataClientsFromFile()
	{
		vector <clsBankClient> Clients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		string Line;
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCientObject(Line);
				Clients.push_back(Client);
			}
			MyFile.close();
		}
		return Clients;
	}

	static string _ConvertClientObjectToText(clsBankClient& C, string Delim = "#||#")
	{
		return C.FirstName + Delim + C.LastName + Delim
			+ C.Email + Delim + C.Phone + Delim + C.AccountNumber() + Delim
			+ C.PinCode + Delim + to_string(C.AccountBalance);		 
	}

	static void _SaveDataClientsToFile(vector <clsBankClient>&Clients)
	{
		fstream MyFile;
		string Line;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankClient& C : Clients)
			{
				MyFile << _ConvertClientObjectToText(C) << endl;
			}
		}
	}

	void _Update()
	{
		vector <clsBankClient> Clients = _LoadDataClientsFromFile();

		for (clsBankClient& C : Clients)
		{
			if (_AccountNumber == C.AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveDataClientsToFile(Clients);
	}

public:
	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance) :
		clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		_AccountNumber = accountNumber;
		_PinCode = pinCode;
		_AccountBalance = accountBalance;
	}

	void Print()
	{
		cout << "\nClient Card\n";
		cout << "__________________________________\n";
		cout << "First Name      : " << FirstName << endl;
		cout << "Last Name       : " << LastName << endl;
		cout << "Email           : " << Email << endl;
		cout << "Phone           : " << Phone << endl;
		cout << "Account Number  : " << _AccountNumber << endl;
		cout << "Pin Code        : " << _PinCode << endl;
		cout << "Account Balance : " << to_string(_AccountBalance) << endl;
		cout << "__________________________________\n";
	}

	bool IsEmpty()
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
	__declspec(property(get = GetMode, put = SetMode))enMode Mode;

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string pinCode)
	{
		_PinCode = pinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float accountBalance)
	{
		_AccountBalance = accountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	static clsBankClient Find(string accountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		string Line;		
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCientObject(Line);
				if (Client.AccountNumber() == accountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
			return _GetEmtyClientObject();
		}
		return _GetEmtyClientObject();
	}

	static clsBankClient Find(string accountNumber, string pinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		string Line;
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCientObject(Line);
				if (Client.AccountNumber() == accountNumber && Client.PinCode == pinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
			return _GetEmtyClientObject();
		}
		return _GetEmtyClientObject();
	}

	static bool IsClientExist(string accountNumber)
	{
		clsBankClient Client = clsBankClient::Find(accountNumber);
		return !(Client.IsEmpty());
	}

	enum enSavResult {
		enFailEmptyAcc = 0, enSucceeded = 1
	};

	enSavResult Save()
	{
		if (IsEmpty())
			return enFailEmptyAcc;

		else
		{
			_Update();
			return enSucceeded;
		}
	}
};
