#include <iostream>
#include "clsLogin.h"

int main()
{
    while (true)
    {
        if (!clsLogin::Login())
            break;
    }
}