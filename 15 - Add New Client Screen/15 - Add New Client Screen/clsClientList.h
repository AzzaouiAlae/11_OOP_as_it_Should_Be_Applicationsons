#pragma once
#include <iostream>
#include "clsBankClient.h"
#include <vector>
#include <iomanip>

using namespace std;

class clsClientList
{ 
    static void PrintClientObject(clsBankClient C)
    {
        cout << "| " << left << setw(15) << C.AccountNumber();
        cout << "| " << left << setw(20) << C.FullName();
        cout << "| " << left << setw(12) << C.Phone;
        cout << "| " << left << setw(20) << C.Email;
        cout << "| " << left << setw(10) << C.PinCode;
        cout << "| " << left << setw(10) << C.AccountBalance << endl;
    }

public:
    static void ShowClientList()
    {
        vector <clsBankClient> vClients = clsBankClient::GetCientsList();

        cout << "\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)\n";
        cout << "______________________________________________________________________________________________________\n";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Clients Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(10) << "Balance";
        cout << "\n______________________________________________________________________________________________________\n";

        if (vClients.size() == 0)
        {
            cout << "\nNo Client Avalibale in the system!\n";
        }
        else
        {
            for (clsBankClient C : vClients)
                PrintClientObject(C);
        }

        cout << "\n______________________________________________________________________________________________________\n\n";
    }

};

