#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"

using namespace std;

class clsDeleteClientsScreen :protected clsScreen
{    

public :
    static void DeleteClient()
    {
        _DrawHeder("Delete Clients Screen");

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

