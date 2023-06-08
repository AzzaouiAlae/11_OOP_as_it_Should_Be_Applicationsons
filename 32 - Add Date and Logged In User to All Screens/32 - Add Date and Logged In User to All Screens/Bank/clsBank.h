#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "MyLib/clsString.h"
#include "clsPerson.h"
#include "MyLib/clsDate.h"
#include "MyLib/clsUtility.h"

using namespace std;

class clsBankClient : public clsPerson
{
public : enum enMode {
		enEmptyMode, enUpdateMode, enAddNewMode
	};

	   struct strTransferLog
	   {
		   string DateTime;
		   string S_Acc;
		   string D_Acc;
		   float Amount;
		   float S_Balance;
		   float D_Balance;
		   string User;
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
		clsUtility::DecryptText(vData[5], 2);
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
		string PinCode = Client.PinCode;
		clsUtility::EncryptText(PinCode, 2);
		return Client.FirstName + "#||#" + Client.LastName + "#||#" + Client.Email + "#||#" + Client.Phone + "#||#" +
			Client._AccountNumber + "#||#" + PinCode + "#||#" + to_string(Client._Balance);
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

	string _ConvertLogToTextLine(clsBankClient DestinationClient, float Amount)
	{
		return clsDate::GetDateTimeNow() + "#||#" + AccountNumber() + "#||#" + DestinationClient.AccountNumber() + "#||#" +
			to_string(Amount) + "#||#" + to_string(Balance) + "#||#" + to_string(DestinationClient.Balance) + "#||#" + CurrentUser.Username();
	}

	void _SaveTransferLog(clsBankClient DestinationClient, float Amount)
	{
		string Line = _ConvertLogToTextLine(DestinationClient, Amount);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	static strTransferLog _ConvertLineToTransferLogStr(string Line)
	{
		strTransferLog Log;
		vector <string> vData = clsString::SplitString(Line, "#||#");
		Log.DateTime = vData[0];
		Log.S_Acc = vData[1];
		Log.D_Acc = vData[2];
		Log.Amount = stod(vData[3]);
		Log.S_Balance = stod(vData[4]);
		Log.D_Balance = stod(vData[5]);
		Log.User = vData[6];

		return Log;
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

	bool Transfer(clsBankClient &Client, float Amount)
	{
		if (Balance > Amount)
		{
			Balance -= Amount;
			Client.Balance += Amount;

			vector <clsBankClient> vClients = _LoadClientsDataFromFile();

			for (clsBankClient &C : vClients)
			{
				if (C.AccountNumber() == this->AccountNumber())				
					C = *this;
				
				else if (C.AccountNumber() == Client.AccountNumber())
					C = Client;
			}

			_SaveDataToFile(vClients);

			_SaveTransferLog(Client, Amount);
			
			return true;
		}
		else
			return false;
	}

	

	static vector <strTransferLog> GetTransferLogList()
	{
		vector <strTransferLog> vLog;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		string Line;
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				vLog.push_back(_ConvertLineToTransferLogStr(Line));				
			}
			MyFile.close();
		}
		return vLog;
	}
};

