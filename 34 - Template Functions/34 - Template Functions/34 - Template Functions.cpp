#include <iostream>

using namespace std;

template <typename T> T myMax(T Number1, T Number2)
{
    return (Number1 > Number2) ? Number1 : Number2;
}

int main()
{
    cout << myMax(10, 20) << endl;

    cout << myMax(4.52, 5.1) << endl;

    cout << myMax('b', 'a') << endl;

    system("pause>0");
}