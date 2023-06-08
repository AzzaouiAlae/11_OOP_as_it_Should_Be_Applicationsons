#pragma once
#include <iostream>
#include "cls/clsUsers.h"
#include "cls/clsInputValidation.h"
#include "cls/clsScreen.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{

public:
    static void FindUsersScreen()
    {
        _DrawHeder("Find User Screen");

        string Username = clsInputValidation::ReadString("\nPlease enter Username : ");

        while (!clsUsers::IsUserExist(Username))
        {
            Username = clsInputValidation::ReadString("\nUsername is not found, choose another one : ");
        }

        clsUsers User = clsUsers::Find(Username);

        _PrintUserCard(User);
    }
};

