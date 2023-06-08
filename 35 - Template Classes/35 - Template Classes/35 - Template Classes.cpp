#include <iostream>

using namespace std;

template <class T>
class Calculator {
private:
    T _Number1, _Number2;
public:
    Calculator(T num1, T num2)
    {
        _Number1 = num1;
        _Number2 = num2;
    }

    void PrintResult()
    {
        cout << _Number1 << " + " << _Number2 << " = " << Add() << endl;
        cout << _Number1 << " - " << _Number2 << " = " << Sub() << endl;
        cout << _Number1 << " * " << _Number2 << " = " << Multiplay() << endl;
        cout << _Number1 << " / " << _Number2 << " = " << Divad() << endl;
    }

    T Add()
    {
        return _Number1 + _Number2;
    }

    T Sub()
    {
        return _Number1 - _Number2;
    }

    T Multiplay()
    {
        return _Number1 * _Number2;
    }

    T Divad()
    {
        return _Number1 / _Number2;
    }
};

int main()
{
    Calculator <int> CalcInt(20, 10);

    Calculator <float> CalcFloat(10.54, 20.9);
    cout << "int Result:\n";
    CalcInt.PrintResult();

    cout << "\n\nfloat Result:\n";
    CalcFloat.PrintResult();
}