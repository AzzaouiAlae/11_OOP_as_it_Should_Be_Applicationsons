#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{
	string _Value;

	static char InvertChar(char MyChar)
	{
		return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
	}	

	static bool isVowel(char MyChar)
	{
		MyChar = tolower(MyChar);
		return ((MyChar == 'a') || (MyChar == 'e') || (MyChar == 'i') || (MyChar == 'o') || (MyChar == 'u'));
	}

	static void PrintWord(string Text, short Start, short Stop)
	{
		for (; Start <= Stop; Start++)
			cout << Text[Start];

		cout << endl;
	}

	static short vectorCounts(vector <string>& MyWords)
	{
		short Counter = 0;
		for (string& Word : MyWords)
			Counter++;

		return Counter;
	}

public:
	enum enSmallCapital { Small = 0, Capital = 1, All = 2 };

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static void PrintFirstLetterInEachWord(string Word)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < Word.length(); i++)
		{
			if (isFirstLetter && Word[i] != ' ')
				cout << Word[i] << endl;

			isFirstLetter = Word[i] == ' ' ? true : false;
		}
	}
	void PrintFirstLetterInEachWord()
	{
		PrintFirstLetterInEachWord(_Value);
	}

	static string LowerFirstLetter(string Text)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < Text.length(); i++)
		{
			if (isFirstLetter && Text[i] != ' ')
				Text[i] = tolower(Text[i]);

			isFirstLetter = Text[i] == ' ' ? true : false;
		}
		return Text;
	}
	string LowerFirstLetter()
	{
		return LowerFirstLetter(_Value);
	}

	static void UpperFirstLetterWords(string& Text)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			if (isFirstLetter && Text[i] != ' ')
				Text[i] = toupper(Text[i]);

			isFirstLetter = Text[i] == ' ' ? true : false;
		}
	}
	void UpperFirstLetterWords()
	{
		UpperFirstLetterWords(_Value);
	}

	static string InvertTextLettersCase(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = InvertChar(Text[i]);
		}			

		return Text;
	}
	string InvertTextLettersCase()
	{
		return InvertTextLettersCase(_Value);
	}

	static short CountLettersCase(string Text, enSmallCapital Case = All)
	{
		short Counter = 0;
		if (Case == All)
			return Text.length();

		if (Case == Small)
		{
			for (int i = 0; i < Text.length(); i++)
			{
				if (islower(Text[i]))
					Counter++;
			}
		}
		else
		{
			for (int i = 0; i < Text.length(); i++)
			{
				if (isupper(Text[i]))
					Counter++;
			}
		}
		return Counter;
	}
	short CountLettersCase(enSmallCapital Case = All)
	{
		return CountLettersCase(_Value, Case);
	}

	static short LetterCounter(string Text, char Letter)
	{
		short Counter = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] == Letter)
				Counter++;
		}
		return Counter;
	}
	short LetterCounter(char Letter)
	{		
		return LetterCounter(_Value, Letter);
	}

	static short LetterCounterAllCase(string Text, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		if (MatchCase)
		{
			for (int i = 0; i < Text.length(); i++)
			{
				if (Text[i] == Letter)
					Counter++;
			}
		}
		else
		{
			for (int i = 0; i < Text.length(); i++)
			{
				if (Text[i] == Letter || InvertChar(Text[i]) == Letter)
					Counter++;
			}
		}
		return Counter;
	}
	short LetterCounterAllCase(char Letter, bool MatchCase = true)
	{
		return LetterCounterAllCase(_Value, Letter, MatchCase);
	}

	static short VowelCount(string Text)
	{
		short Count = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (isVowel(Text[i]))
				Count++;
		}
		return Count;
	}
	short VowelCount()
	{
		return VowelCount(_Value);
	}	

	static void PrintWordsInLine(string Text)
	{
		short PrevNum = 0;
		cout << "\nYour Words in the text : \n\n";
		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] == ' ')
			{
				PrintWord(Text, PrevNum, i - 1);
				PrevNum = i + 1;
			}
			else if (i + 1 == Text.length())
				PrintWord(Text, PrevNum, i);
		}
	}
	void PrintWordsInLine()
	{
		PrintWordsInLine(_Value);
	}

	static short CountEachWordInText(string Text)
	{
		short Counter = 0, pos = 0;
		string Delim = " ";

		while ((pos = Text.find(Delim)) != string::npos)
		{
			if (Text.substr(0, pos) != "")			
				Counter++;				
			
			Text = Text.erase(0, pos + Delim.length());
		}

		if (Text != "")
			Counter++;

		return Counter;
	}
	short CountEachWordInText()
	{
		return CountEachWordInText(_Value);
	}

	static vector <string> SplitString(string Text, string delim)
	{
		vector <string> vecWords;
		short pos = 0;
		string sWord;
		while ((pos = Text.find(delim)) != string::npos)
		{
			sWord = Text.substr(0, pos);
			if (sWord != "")
			{
				vecWords.push_back(sWord);
				sWord = "";
			}

			Text = Text.erase(0, pos + delim.length());
		}

		if (Text != "")
			vecWords.push_back(Text);

		return vecWords;
	}
	vector <string> SplitString(string delim)
	{
		return SplitString(_Value, delim);
	}
	
	static string TrimLeft(string Text)
	{
		while (Text[0] == ' ')
			Text = Text.erase(0, 1);

		return Text;
	}
	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

	static string TrimRight(string Text)
	{
		while (Text[Text.length() - 1] == ' ')
			Text = Text.erase(Text.length() - 1, 1);

		return Text;
	}
	string TrimRight()
	{
		return TrimRight(_Value);
	}

	static string Trim(string Text)
	{
		Text = TrimLeft(Text);

		Text = TrimRight(Text);

		return Text;
	}
	string Trim()
	{
		return Trim(_Value);
	}

	static string JoinString(vector <string>& MyListe, string Delim)
	{
		string JoinNames = "";
		for (string& Name : MyListe)
			JoinNames += (Name + Delim);


		return JoinNames.substr(0, JoinNames.length() - Delim.length());
	}

	static string JoinString(string MyArrListe[], short Lenght, string Delim)
	{
		string JoinNames = "";
		for (int i = 0; i < Lenght; i++)
			JoinNames += (MyArrListe[i] + Delim);


		return JoinNames.substr(0, JoinNames.length() - Delim.length());
	}

	static string ReverseWords(string Text)
	{
		string Revers = "";
		for (int i = Text.length() - 1; i >= 0; i--)
		{
			if (Text[i] == ' ')
			{
				Revers += (Text.substr(i + 1, Text.length() - i - 1) + " ");
				Text.erase(i, Text.length() - i);
			}
		}
		if (Text != "")
			Revers += Text;

		return Revers;
	}
	string ReverseWords()
	{
		return ReverseWords(_Value);
	}

	static string ToUpper(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
			Text[i] = toupper(Text[i]);

		return Text;
	}
	string ToUpper()
	{
		return ToUpper(_Value);
	}

	static string ToLower(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
			Text[i] = tolower(Text[i]);

		return Text;
	}
	string ToLower()
	{
		return ToLower(_Value);
	}

	static string ReplaceText(string Text, string Search, string Replace, bool Case = true)
	{
		short pos;
		string strPart = "";

		if (Case)
		{
			while ((pos = Text.find(Search)) != string::npos)
			{
				strPart = Text.substr(0, pos);

				strPart += Replace;

				strPart += Text.substr(pos + Search.length(), Text.length() - 1);

				Text = strPart;
			}
		}
		else
		{
			string TextUpper = ToUpper(Text);
			while ((pos = ToUpper(Text).find(ToUpper(Search))) != string::npos)
			{
				strPart = Text.substr(0, pos);

				strPart += Replace;

				strPart += Text.substr(pos + Search.length(), Text.length() - 1);

				Text = strPart;
			}
		}

		return Text;
	}
	string ReplaceText(string Search, string Replace, bool Case = true)
	{
		return ReplaceText(_Value, Search, Replace, Case);
	}

	static string RemovePunct(string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			if (ispunct(Text[i]))
			{
				Text.erase(i, 1);
				i--;
			}
				
		}
		return Text;
	}
	string RemovePunct()
	{
		return RemovePunct(_Value);
	}
};

