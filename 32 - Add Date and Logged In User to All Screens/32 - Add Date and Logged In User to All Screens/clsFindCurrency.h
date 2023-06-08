#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "MyLib/clsInputValidation.h"
#include "clsCurrency.h"
#include "MyLib/clsString.h"

class clsFindCurrency : protected clsScreen
{
	enum enFindBy
	{
		enCode = 1, enCountry = 2
	};

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

	static void _ShowResult(clsCurrency Currency)
	{
		if (Currency.IsEmpty())		
			cout << "\n\nCurrency not found!\n";
		
		else
			_PrintCurrencyCard(Currency);
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");
		if (clsInputValidation::ReadShortNumber("Find By: [1] Code or [2] Country : ", 1, 2) == enCode)
		{
			string Code = clsInputValidation::ReadString("\nPlease enter Currency Code : ");
			clsCurrency Currency = clsCurrency::FindCurrenciesByCode(Code);
			_ShowResult(Currency);
		}

		else
		{
			string Country = clsInputValidation::ReadString("\nPlease enter Country name : ");
			clsCurrency Currency = clsCurrency::FindCurrenciesByCountry(Country);
			_ShowResult(Currency);
		}
	}
};