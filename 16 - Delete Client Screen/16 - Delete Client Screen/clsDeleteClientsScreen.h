#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;

class clsDeleteClientsScreen
{
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

public :
    static void DeleteClient()
    {
        string AccNum = clsInputValidation::ReadString("\nPlease enter the account number : ");

        while (!clsBankClient::IsClientExist(AccNum))
        {
            AccNum = clsInputValidation::ReadString("\naccount number was not found, choose anothre one : ");
        }

        clsBankClient Client = clsBankClient::Find(AccNum);

        _Print(Client);

        string msg = "\nAre you sure you want to delete this client y/n : ";

        if (clsInputValidation::ValidationYesNo(msg))
        {
            if (Client.Delete())
            {
                cout << "\nAccount deleted Successfully\n";

                _Print(Client);
            }

            else
                cout << "Error Client was not deleted";
        }
    }

};

