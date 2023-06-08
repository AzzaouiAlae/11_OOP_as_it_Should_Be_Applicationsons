#include <iostream>
#include "clsUtility.h"

using namespace std;

int main()
{
    float A = 10.49, B = 10.60, C = -10.49, D = -10.60;

    cout << "A = " << clsUtility::MyRound(A) << endl;
    cout << "B = " << clsUtility::MyRound(B) << endl;
    cout << "C = " << clsUtility::MyRound(C) << endl;
    cout << "D = " << clsUtility::MyRound(D) << endl;
}