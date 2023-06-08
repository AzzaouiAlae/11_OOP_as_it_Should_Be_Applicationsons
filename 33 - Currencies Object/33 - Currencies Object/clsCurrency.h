#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"

using namespace std;

class clsCurrency
{
public: enum enMode{enEmpty = 0, enUpdate = 1};

private:
	enMode _Mode;
	string _Country;
	string _CountryCode;
	string _Currency;
	double _Rate;

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(enEmpty, "", "", "", 0);
	}

	static clsCurrency _ConvertLineToCurrencyObject(string Line)
	{
		vector <string> vData = clsString::SplitString(Line, "#//#");

		if (vData.size() == 4)
			return clsCurrency(enUpdate, vData[0], vData[1], vData[2], stod(vData[3]));

		else
			return _GetEmptyObject();
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vCurrencys;
		fstream MyFile;
		string Line;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				vCurrencys.push_back(_ConvertLineToCurrencyObject(Line));
			}
			MyFile.close();
		}
		return vCurrencys;
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency)
	{
		return Currency.Country() + "#//#" + Currency.CountryCode() + "#//#" +
			Currency.Currency() + "#//#" + to_string(Currency.Rate());
	}

	static void _SaveCurrencyToFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsCurrency &Cur : vCurrencies)
			{
				MyFile << _ConvertCurrencyObjectToLine(Cur) << endl;
			}
			MyFile.close();
		}
	}

public:
	clsCurrency(enMode mode, string country, string countryCode, string currency, double rate)
	{
		_Mode = mode;
		_Country = country;
		_CountryCode = countryCode;
		_Currency = currency;
		_Rate = rate;
	}

	string Country()
	{
		return _Country;
	}

	string CountryCode()
	{
		return _CountryCode;
	}

	string Currency()
	{
		return _Currency;
	}

	double Rate()
	{
		return _Rate;
	}

	void Rate(double NewRate)
	{
		_Rate = NewRate;
	}

	bool IsEmpty()
	{
		return _Mode;
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	void Update()
	{
		vector <clsCurrency> vCurrencies;

		for (clsCurrency &C : vCurrencies)
		{
			if (C.Country() == Country())
				C = *this;
		}

		_SaveCurrencyToFile(vCurrencies);
	}
};