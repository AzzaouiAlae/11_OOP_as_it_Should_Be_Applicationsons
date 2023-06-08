#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "MyLib/clsInputValidation.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateRateScreen : protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card\n";
		cout << _TextRepeat("-", 30) << endl;
		cout << "Country  : " << Currency.Country() << endl;
		cout << "Code     : " << Currency.Code() << endl;
		cout << "Name     : " << Currency.Currency() << endl;
		cout << "Rate(1$) : " << Currency.Rate() << endl;
		cout << _TextRepeat("-", 30) << endl;
	}

	static void _Update(clsCurrency &Currency)
	{
		cout << "\nUpdate Currency Rate:\n";
		cout << _TextRepeat("-", 35) << endl;
		Currency.Rate(clsInputValidation::ReadDoubleNumber("\nEnter new Rate : "));
		Currency.Update();
	}
public :
	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("Update Rate Screen");
		string Code = clsInputValidation::ReadString("Please enter Currency Code : ");
		while (clsCurrency::FindCurrenciesByCode(Code).IsEmpty())
		{
			Code = clsInputValidation::ReadString("Currency Code not found choose another one : ");
		}
		clsCurrency Currency = clsCurrency::FindCurrenciesByCode(Code);
		_PrintCurrencyCard(Currency);

		if (clsInputValidation::ValidationYesNo("\nAre you sure you want to update this rate of this currency y/n : "))
		{
			_Update(Currency);
			_PrintCurrencyCard(Currency);
		}
		
	}
};

