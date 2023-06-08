#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "clsCurrency.h"
#include "MyLib/clsInputValidation.h"

using namespace std;

class clsCurrencyCalculator : protected clsScreen
{
	static clsCurrency _ReadCurrency(string msg)
	{
		string Code = clsInputValidation::ReadString(msg);
		while (clsCurrency::FindCurrenciesByCode(Code).IsEmpty())
		{
			Code = clsInputValidation::ReadString("currency Code not found choose another one : ");
		}
		return clsCurrency::FindCurrenciesByCode(Code);
	}

	static double _CounvertCurrency(clsCurrency FromCurrency, clsCurrency ToCurrency, double Amount)
	{
		return ((1 / FromCurrency.Rate()) * Amount) * ToCurrency.Rate();
	}
public:
	static void ShowCurrencyCalcScreen()
	{
		_DrawScreenHeader("Currency Calculator Screen");

		clsCurrency FromCurrency = _ReadCurrency("\nPlease enter from currency code : ");
		clsCurrency ToCurrency = _ReadCurrency("\nPlease enter to currency code : ");

		double Amount = clsInputValidation::ReadDoubleNumber("\nenter amount : ");

		cout << endl <<Amount << " " << FromCurrency.Code() << " = " << FromCurrency.CounvertCurrency(ToCurrency, Amount) << " " << ToCurrency.Code();
	}
};