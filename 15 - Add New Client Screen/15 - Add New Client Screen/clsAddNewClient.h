#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;

class clsAddNewClient
{
    static void ReadClientInfo(clsBankClient& Client)
    {
        Client.FirstName = clsInputValidation::ReadString("Plaese enter first Name : ");

        Client.LastName = clsInputValidation::ReadString("Plaese enter last name : ");

        Client.Email = clsInputValidation::ReadString("Plaese enter email : ");

        Client.Phone = clsInputValidation::ReadString("Plaese enter phone : ");

        Client.PinCode = clsInputValidation::ReadString("Plaese enter pin code : ");

        Client.AccountBalance = clsInputValidation::ReadDoubleNumber("Plaese enter balance : ");                   
    }

    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card\n";
        cout << "__________________________________\n";
        cout << "First Name      : " << Client.FirstName << endl;
        cout << "Last Name       : " << Client.LastName << endl;
        cout << "Email           : " << Client.Email << endl;
        cout << "Phone           : " << Client.Phone << endl;
        cout << "Account Number  : " << Client.AccountNumber() << endl;
        cout << "Pin Code        : " << Client.PinCode << endl;
        cout << "Account Balance : " << to_string(Client.AccountBalance) << endl;
        cout << "__________________________________\n";
    }

public:
    static void AddNewClient()
    {
        string AccNum = clsInputValidation::ReadString("Please enter Client Account Number : ");
        while (clsBankClient::IsClientExist(AccNum))
        {
            AccNum = clsInputValidation::ReadString("Account Number is already exist choose another one : ");
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClient(AccNum);

        ReadClientInfo(NewClient);

        clsBankClient::enSavResult SaveResult;

        SaveResult = NewClient.Save();

        if (SaveResult == clsBankClient::enSucceeded)
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _Print(NewClient);
        }
        else if (SaveResult == clsBankClient::enFailEmptyAcc)
        {
            cout << "\nError account was not saved because it's Empty\n";
        }
        else if (SaveResult == clsBankClient::enFailAccNumExsist)
        {
            cout << "\nError account was not saved because account number is used!\n";
        }
    }
};

