#pragma once
#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsUtility.h"

using namespace std;

class clsTotalBalancesScreen
{
    static void _PrintClientBalanceLine(clsBankClient C)
    {
        cout << "| " << left << setw(20) << C.AccountNumber();
        cout << "| " << left << setw(35) << C.FullName();
        cout << "| " << left << setw(20) << C.AccountBalance << endl;
    }
public:
    static void PrintTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetCientsList();

        cout << "\t\t\tBalance List (" << vClients.size() << ") Client(s)\n";
        cout << "____________________________________________________________________________\n";
        cout << "| " << left << setw(20) << "Account Number";
        cout << "| " << left << setw(35) << "Clients Name";
        cout << "| " << left << setw(20) << "Balance" << endl;
        cout << "____________________________________________________________________________\n";

        if (vClients.size() == 0)
            cout << "\nNo Client avalible in the system\n";

        else
        {
            for (clsBankClient C : vClients)
            {
                _PrintClientBalanceLine(C);
            }
        }
        cout << "____________________________________________________________________________\n";

        double TotalBalances = clsBankClient::GetTotaleBalances();

        cout << "\n\t\t\tTotal Balances : " << TotalBalances << endl;

        cout << "\t\t\t" << clsUtility::ConvertNumberToText(TotalBalances) << endl;
    }
};

