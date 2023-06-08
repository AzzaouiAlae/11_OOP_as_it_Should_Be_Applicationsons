#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "Bank/clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsListCurrencies : protected clsScreen
{
	static void _PrintCurrencyObject(clsCurrency Currency)
	{		
		cout << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.Code();
		cout << "| " << left << setw(43) << Currency.Currency();
		cout << "| " << left << setw(25) << to_string(Currency.Rate());		
	}
public:
	static void ShowListCurrencies()
	{
		vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

		_DrawScreenHeader("List Currencies", "(" + to_string(vCurrency.size()) + ") Currency", 100);
		
		cout << _TextRepeat("-", 100) << endl;
		cout << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(43) << "Name";
		cout << "| " << left << setw(25) << "Rate/(1$)";
		cout << endl <<_TextRepeat("-", 100) << endl;

		for (clsCurrency &Currency : vCurrency)
		{
			_PrintCurrencyObject(Currency);
			cout << endl;
		}

		cout << endl << _TextRepeat("-", 100) << endl;
	}
};

