#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUsers.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
public:
    static void DeleteUsers()
    {
        _DrawHeder("Delete Users Screen");

        string Username = clsInputValidation::ReadString("\nPlease enter the account number : ");

        while (!clsUsers::IsUserExist(Username))
        {
            Username = clsInputValidation::ReadString("\nUsername was not found, choose anothre one : ");
        }

        clsUsers User = clsUsers::Find(Username);

        _PrintUserCard(User);

        string msg = "\nAre you sure you want to delete this User y/n : ";

        if (clsInputValidation::ValidationYesNo(msg))
        {
            if (User.Delete())
            {
                cout << "\nUser deleted Successfully\n";

                _PrintUserCard(User);
            }
            else
                cout << "Error! User was not deleted";
        }
    }
};

