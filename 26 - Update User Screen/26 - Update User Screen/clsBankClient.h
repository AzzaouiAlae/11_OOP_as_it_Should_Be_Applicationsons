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
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

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
				if(!C.MarkForDelete())
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

	void _AddNew()
	{
		_AddNewLineToFile(_ConvertClientObjectToText(*this));
	}

	void _AddNewLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
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

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

	string FullName()
	{
		return FirstName + " " + LastName;
	}

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
		enFailEmptyAcc = 0, enSucceeded = 1, enFailAccNumExsist = 2
	};

	enSavResult Save()
	{
		switch (_Mode)
		{
		case EmptyMode:
			return enFailEmptyAcc;

		case UpdateMode:
		{
			_Update();
			return enSucceeded;
		}
		case AddNewMode:
		{
			if (IsClientExist(AccountNumber()))
				return enFailAccNumExsist;
			else
			{
				_AddNew();
				_Mode = UpdateMode;
				return enSucceeded;
			}			
		}
		}
	}

	bool Delete()
	{
		vector <clsBankClient> vClient = _LoadDataClientsFromFile();

		_MarkForDelete = true;

		for (clsBankClient& C : vClient)
		{
			if (AccountNumber() == C.AccountNumber())
				C = *this;
		}

		_SaveDataClientsToFile(vClient);

		*this = _GetEmtyClientObject();

		return true;
	}

	static vector <clsBankClient> GetCientsList()
	{
		return _LoadDataClientsFromFile();
	}

	static double GetTotaleBalances()
	{
		vector <clsBankClient> vClients = GetCientsList();

		double TotalBalances = 0;

		for (clsBankClient C : vClients)
			TotalBalances += C.AccountBalance;

		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (_AccountBalance >= Amount)
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
		return false;		
	}

	static clsBankClient GetAddNewClient(string AccNum)
	{		
		return clsBankClient(AddNewMode, "", "", "", "", AccNum, "", 0);
	}
};

