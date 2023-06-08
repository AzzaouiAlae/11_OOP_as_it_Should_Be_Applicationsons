#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"

using namespace std;

class clsAddNewClient : protected clsScreen
{
public:
    static void AddNewClient()
    {
        clsScreen::_DrawHeder("Add new client screen");
        string AccNum = clsInputValidation::ReadString("\nPlease enter Client Account Number : ");
        while (clsBankClient::IsClientExist(AccNum))
        {
            AccNum = clsInputValidation::ReadString("Account Number is already exist choose another one : ");
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClient(AccNum);

        _ReadAddClientInfo(NewClient);

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

