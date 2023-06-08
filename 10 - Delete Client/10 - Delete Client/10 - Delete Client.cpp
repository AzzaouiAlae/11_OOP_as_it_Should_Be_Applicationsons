#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;

void DeleteClient()
{
    string AccNum = clsInputValidation::ReadString("\nPlease enter the account number : ");

    while (!clsBankClient::IsClientExist(AccNum))
    {
        AccNum = clsInputValidation::ReadString("\naccount number was not found, choose anothre one : ");
    }

    clsBankClient Client = clsBankClient::Find(AccNum);

    Client.Print();

    if (clsInputValidation::ValidationYesNo("\nAre you sure you want to delete this client y/n : "))
    {
        if (Client.Delete())
        {
            cout << "\nAccount deleted Successfully\n";

            Client.Print();
        }

        else
            cout << "Error Client was not deleted";
    }
}

int main()
{
    DeleteClient();

    system("pause>0");
}