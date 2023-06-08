#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    if (Client.Mode == 1)
    {
        if (clsInputValidation::ValidationYesNo("Do you want to change the first name (y/n): "))
            Client.FirstName = clsInputValidation::ReadString("Plaese enter first Name : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the last name (y/n): "))
            Client.LastName = clsInputValidation::ReadString("Plaese enter last name : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the email (y/n): "))
            Client.Email = clsInputValidation::ReadString("Plaese enter email : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the phone (y/n): "))
            Client.Phone = clsInputValidation::ReadString("Plaese enter phone : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the pin code (y/n): "))
            Client.PinCode = clsInputValidation::ReadString("Plaese enter pin code : ");

        if (clsInputValidation::ValidationYesNo("Do you want to change the balance (y/n): "))
            Client.AccountBalance = clsInputValidation::ReadDoubleNumber("Plaese enter balance : ");
    }    
    else
    {
        Client.FirstName = clsInputValidation::ReadString("Plaese enter first Name : ");

        Client.LastName = clsInputValidation::ReadString("Plaese enter last name : ");

        Client.Email = clsInputValidation::ReadString("Plaese enter email : ");

        Client.Phone = clsInputValidation::ReadString("Plaese enter phone : ");

        Client.PinCode = clsInputValidation::ReadString("Plaese enter pin code : ");

        Client.AccountBalance = clsInputValidation::ReadDoubleNumber("Plaese enter balance : ");
    }        
}

void AddNewClient()
{
    string AccNum = clsInputValidation::ReadString("Please enter Client Account Number : ");
    while (clsBankClient::IsClientExist(AccNum))
    {
        AccNum = clsInputValidation::ReadString("Account Number is already exist choose another one : ");
    }
    clsBankClient NewClient = clsBankClient::GetAddNewClient(AccNum);

    ReadClientInfo(NewClient);

    clsBankClient::enSavResult SaveResult;

    SaveResult = NewClient.Save();

    if (SaveResult == clsBankClient::enSucceeded)
    {
        cout << "\nAccount Addeded Successfully :-)\n";
        NewClient.Print();
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

int main()
{
    AddNewClient();
    system("pause>0");
}