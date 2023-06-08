#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client)
    {

        if (clsInputValidation::ValidationYesNo("Do you want to change the first name (y/n): "))
            Client.FirstName = clsInputValidation::ReadString("Plaese enter first Name : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the last name (y/n): "))
            Client.LastName = clsInputValidation::ReadString("Plaese enter last name : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the email (y/n): "))
            Client.Email = clsInputValidation::ReadString("Plaese enter email : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the phone (y/n): "))
            Client.Phone = clsInputValidation::ReadString("Plaese enter phone : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the pin code (y/n): "))
            Client.PinCode = clsInputValidation::ReadString("Plaese enter pin code : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the balance (y/n): "))
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
    static void UpdateClient()
    {
        _DrawHeder("Update client screen");

        string AccNum = clsInputValidation::ReadString("\nPlease eneter client account number :");
        while (!clsBankClient::IsClientExist(AccNum))
        {
            AccNum = clsInputValidation::ReadString("Account Number not found, choose another one : ");
        }
        clsBankClient Client = clsBankClient::Find(AccNum);

        _Print(Client);

        cout << "\nUpdate Client Info : \n";
        cout << "__________________________________\n";

        _ReadClientInfo(Client);

        clsBankClient::enSavResult SaveResult;

        SaveResult = Client.Save();

        if (SaveResult == clsBankClient::enSucceeded)
        {
            cout << "\nAccount Updated Successfully!\n";
            _Print(Client);
        }
        else if (SaveResult == clsBankClient::enFailEmptyAcc)
        {
            cout << "\nerror Account was not saved because it's empty\n";
        }
    }

};

