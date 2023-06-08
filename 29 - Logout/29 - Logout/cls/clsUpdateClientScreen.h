#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
   

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

        _PrintClientCard(Client);

        cout << "\nUpdate Client Info : \n";
        cout << "__________________________________\n";

        _ReadAddClientInfo(Client);

        clsBankClient::enSavResult SaveResult;

        SaveResult = Client.Save();

        if (SaveResult == clsBankClient::enSucceeded)
        {
            cout << "\nAccount Updated Successfully!\n";
            _PrintClientCard(Client);
        }
        else if (SaveResult == clsBankClient::enFailEmptyAcc)
        {
            cout << "\nerror Account was not saved because it's empty\n";
        }
    }

};

