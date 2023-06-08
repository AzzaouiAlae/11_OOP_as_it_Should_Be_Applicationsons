#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "MyLib/clsString.h"
#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{
public : enum enMode {
		enEmptyMode, enUpdateMode, enAddNewMode
	};

private:
	string _AccountNumber;
	string _PinCode;
	float _Balance;
	enMode _Mode;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line)
	{
		vector <string> vData = clsString::SplitString(Line, "#||#");
		return clsBankClient(enUpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stof(vData[6]));
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		string Line;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static string _ConvertObjectClientToLine(clsBankClient Client)
	{
		return Client.FirstName + "#||#" + Client.LastName + "#||#" + Client.Email + "#||#" + Client.Phone + "#||#" +
			Client._AccountNumber + "#||#" + Client._PinCode + "#||#" + to_string(Client._Balance);
	}

	static void _SaveDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		
		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (!C.MarkForDelete())
					MyFile << _ConvertObjectClientToLine(C) << endl;
			}
		}
	}

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enEmptyMode, "", "", "", "", "", "", 0);
	}	

	void _AddNewClientToFile()
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << _ConvertObjectClientToLine(*this) << endl;
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveDataToFile(vClients);
	}
public:	
	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float balance) :
		clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		_AccountNumber = accountNumber;
		_PinCode = pinCode;
		_Balance = balance;
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

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
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetBalance(float balance)
	{
		_Balance = balance;
	}
	float GetBalance()
	{
		return _Balance;
	}
	__declspec(property(get = GetBalance, put = SetBalance)) float Balance;

	bool IsEmpty()
	{
		return _Mode == enEmptyMode;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient C : vClients)
		{
			if (C.AccountNumber() == AccountNumber)			
				return C;
			
		}
		return _GetEmptyClient();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient C : vClients)
		{
			if (C.AccountNumber() == AccountNumber && C.PinCode == PinCode)
				return C;
		}
		return _GetEmptyClient();
	}

	enum enSaveResult {
		enSaveSuccessfull, enFailSaveEmpty
	};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsBankClient::enEmptyMode:
			return enFailSaveEmpty;
			break;
		case clsBankClient::enUpdateMode:
			_Update();
			break;
		case clsBankClient::enAddNewMode:
			_AddNewClientToFile();
			return enSaveSuccessfull;
			break;
		default:
			break;
		}
	}

	void Delete()
	{
		
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		
		for (clsBankClient &C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;
			}				
		}
		_SaveDataToFile(vClients);

		*this = _GetEmptyClient();
	}

	void Deposit(float Amount)
	{
		_Balance += Amount;	
		
		Save();
	}

	void Withdraw(float Amount)
	{
		Deposit(Amount * -1);
	}
};

