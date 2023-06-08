#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;

void ReadClientInfo(clsBankClient &Client)
{
    
    if(clsInputValidation::ValidationYesNo("Do you want to change the first name (y/n): "))
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

void UpdateClient()
{
    string AccNum = clsInputValidation::ReadString("Please eneter client account number :");
    while (!clsBankClient::IsClientExist(AccNum))
    {
        AccNum = clsInputValidation::ReadString("Account Number not found, choose another one : ");
    }
    clsBankClient Client = clsBankClient::Find(AccNum);

    Client.Print();

    cout << "\nUpdate Client Info : \n";
    cout << "__________________________________\n";

    ReadClientInfo(Client);

    clsBankClient::enSavResult SaveResult;

    SaveResult = Client.Save();

    if (SaveResult == clsBankClient::enSucceeded)
    {
        cout << "\nAccount Updated Successfully!\n";
        Client.Print();
    }
    else if(SaveResult == clsBankClient::enFailEmptyAcc)
    {
        cout << "\nerror Account was not saved because it's empty\n";
    }        
}

int main()
{
    UpdateClient();

    system("pause>0");
}