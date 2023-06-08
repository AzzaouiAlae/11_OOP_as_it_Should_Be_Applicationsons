#include <iostream>
#include "clsBankClient.h"

using namespace std;

int main()
{
    clsBankClient Client1 = clsBankClient::Find("A10");
    Client1.Print();
}