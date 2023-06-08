#pragma once
#include <iostream>
#include "Bank/clsScreen.h"
#include "MyLib/clsInputValidation.h"
#include "clsListCurrencies.h"
#include "clsFindCurrency.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculator.h"

using namespace std;

bool BackToCurrency = true;

class clsShowCurrencyScreen : protected clsScreen
{
	enum enCurrencyMenueOption {
		enListCurrencies = 1, enFindCurrency = 2, enUpdateRate = 3, enCurrencyCalculator = 4, enMainMenue = 5
	};

	static void _BackToCurrencyScreen()
	{
		cout << "\n\nPress any key to go back to Currency Menue...";
		system("pause>0");
	}

	static void _PerformCurrencyOption(enCurrencyMenueOption Option)
	{
		switch (Option)
		{
		case clsShowCurrencyScreen::enListCurrencies:
			system("cls");
			clsListCurrencies::ShowListCurrencies();
			_BackToCurrencyScreen();
			break;
		case clsShowCurrencyScreen::enFindCurrency:
			system("cls");
			clsFindCurrency::ShowFindCurrencyScreen();
			_BackToCurrencyScreen();
			break;
		case clsShowCurrencyScreen::enUpdateRate:
			system("cls");
			clsUpdateRateScreen::ShowUpdateRateScreen();
			_BackToCurrencyScreen();
			break;
		case clsShowCurrencyScreen::enCurrencyCalculator:
			system("cls");
			clsCurrencyCalculator::ShowCurrencyCalcScreen();
			_BackToCurrencyScreen();
			break;
		case clsShowCurrencyScreen::enMainMenue:
			BackToCurrency = false;
			break;	
		}
	}

public:
	static void ShowCurrencyScreen()
	{
		BackToCurrency = true;

		while (BackToCurrency)
		{
			system("cls");
			_DrawScreenHeader("Currency Exchange Screen");

			cout << _TextRepeat("-", 36) << endl;
			cout << "\t[1] List Currencies." << endl;
			cout << "\t[2] Find Currency." << endl;
			cout << "\t[3] Update Rate." << endl;
			cout << "\t[4] Currency Calculator." << endl;
			cout << "\t[5] Main Menue." << endl;
			cout << _TextRepeat("-", 36) << endl;
			_PerformCurrencyOption(enCurrencyMenueOption(clsInputValidation::ReadIntNumber("Choose what do you want to do [1 to 5] : ", 1, 5)));
		}		

	}
};

