#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUsers.h"

using namespace std;

class clsUpdateUsersScreen : protected clsScreen
{
public:
    static void ShowUpdateUserScreen()
    {
        _DrawHeder("Update user screen");

        string username = clsInputValidation::ReadString("\nPlease eneter username number :");
        while (!clsUsers::IsUserExist(username))
        {
            username = clsInputValidation::ReadString("username not found, choose another one : ");
        }
        clsUsers User = clsUsers::Find(username);

        _PrintUserCard(User);

        cout << "\nUpdate User Info : \n";
        cout << "__________________________________\n";

        _ReadUpdateUserInfo(User);

        clsUsers::enSaveResult SaveResult;

        SaveResult = User.Save();

        if (SaveResult == clsUsers::enSucceeded)
        {
            cout << "\nUser Updated Successfully!\n";
            _PrintUserCard(User);
        }
        else if (SaveResult == clsUsers::enFailEmptyUser)
        {
            cout << "\nerror User was not saved because it's empty\n";
        }
    }
};

