#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsInputValidation
{
public:
	static bool IsNumberBetween(int Num, int From, int To)
	{
		return Num >= From && Num <= To;
	}
	static bool IsNumberBetween(double Num, double From, double To)
	{
		return Num >= From && Num <= To;
	}

	enum enNumFromTo {
		enFromNum = 1, enToNum = 2
	};

	static short ReadShortNumber(string msg)
	{
		short num = 0;
		cout << msg;
		cin >> num;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalide Number, " << msg;
			cin >> num;
		}

		return num;
	}

	static short ReadShortNumber(string msg, int FromTo, enNumFromTo FromOrTo)
	{
		short num = 0;
		string Wrong = "";
		if (enFromNum == FromOrTo)
		{
			do {
				cout << Wrong;
				num = ReadShortNumber(msg);
				Wrong = "Wrong!! ";
			} while (num < FromTo);
		}
		else
		{
			do {
				cout << Wrong;
				num = ReadShortNumber(msg);
				Wrong = "Wrong!! ";
			} while (num > FromTo);
		}

		return num;
	}

	static short ReadShortNumber(string msg, int From, int To)
	{
		short num = 0;
		string Wrong = "";
		do {
			cout << Wrong;
			num = ReadIntNumber(msg);
			Wrong = "Wrong!! ";
		} while (num < From || num > To);

		return num;
	}

	static int ReadIntNumber(string msg)
	{
		int num = 0;
		cout << msg;
		cin >> num;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalide Number, " << msg;
			cin >> num;
		}

		return num;
	}

	static int ReadIntNumber(string msg, int FromTo, enNumFromTo FromOrTo)
	{
		int num = 0;
		string Wrong = "";
		if (enFromNum == FromOrTo)
		{
			do {
				cout << Wrong;
				num = ReadIntNumber(msg);
				Wrong = "Wrong!! ";
			} while (num < FromTo);
		}
		else
		{
			do {
				cout << Wrong;
				num = ReadIntNumber(msg);
				Wrong = "Wrong!! ";
			} while (num > FromTo);
		}

		return num;
	}

	static int ReadIntNumber(string msg, int From, int To)
	{
		int num = 0;
		string Wrong = "";
		do {
			cout << Wrong;
			num = ReadIntNumber(msg);
			Wrong = "Wrong!! ";
		} while (num < From || num > To);

		return num;
	}

	static double ReadDoubleNumber(string msg)
	{
		double num = 0;
		cout << msg;
		cin >> num;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalide Number, " << msg;
			cin >> num;
		}

		return num;
	}

	static double ReadDoubleNumber(string msg, double FromTo, enNumFromTo FromOrTo)
	{
		double num = 0;
		string Wrong = "";

		if (enFromNum == FromOrTo)
		{
			do {
				cout << Wrong;
				num = ReadIntNumber(msg);
				Wrong = "Wrong!! ";
			} while (num < FromTo);
		}

		else
		{
			do {
				cout << Wrong;
				num = ReadIntNumber(msg);
				Wrong = "Wrong!! ";
			} while (num > FromTo);
		}

		return num;
	}

	static double ReadDoubleNumber(string msg, double From, double To)
	{
		double num = 0;
		string Wrong = "";
		do {
			cout << Wrong;
			num = ReadIntNumber(msg);
			Wrong = "Wrong!! ";
		} while (num < From || num > To);

		return num;
	}

	static string ReadString()
	{
		string Text;
		getline(cin >> ws, Text);
		return Text;
	}

	static string ReadString(string msg)
	{
		cout << msg;
		string Text;
		getline(cin >> ws, Text);
		return Text;
	}

	static string ToLower(string Text)
	{
		string LowerText = "";
		for (short i = 0; i < Text.length(); i++)
		{
			LowerText += tolower(Text[i]);
		}
		return LowerText;
	}

	static bool ValidationYesNo(string msg)
	{
		cout << msg;
		string Answer;
		getline(cin >> ws, Answer);
		Answer = ToLower(Answer);
		return Answer == "y";
	}

};