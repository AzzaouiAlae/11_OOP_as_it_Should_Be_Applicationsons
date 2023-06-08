#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"

using namespace std;

class clsFindClients : protected clsScreen
{
    

public:
    static void FindClientsScreen()
    {
        _DrawHeder("Find Clients Screen");

        string AccNum = clsInputValidation::ReadString("\nPlease enter accaount number : ");

        while (!clsBankClient::IsClientExist(AccNum))
        {
            AccNum = clsInputValidation::ReadString("\nAccaount number is not found, choose another one : ");
        }

        clsBankClient Client = clsBankClient::Find(AccNum);

        _PrintClientCard(Client);
    }

};

