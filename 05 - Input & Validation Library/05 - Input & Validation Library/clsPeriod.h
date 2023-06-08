#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsPeriod
{
	clsDate _Start;
	clsDate _End;

	static int ReadNumInRange(string Message, int From, int To)
	{
		int Number;
		do {
			cout << Message;
			cin >> Number;
		} while (Number < From || Number > To);
		return Number;
	}

public:
	clsDate GetStartDate()
	{
		return _Start;
	}
	void SetStartDate(clsDate Start)
	{
		_Start = Start;
	}
	__declspec(property(get = GetStartDate, put = SetStartDate)) clsDate Start;

	clsDate GetEndDate()
	{
		return _End;
	}
	void SetEndDate(clsDate End)
	{
		_End = End;
	}
	__declspec(property(get = GetEndDate, put = SetEndDate)) clsDate End;

	clsPeriod()
	{

	}
	clsPeriod(clsDate start, clsDate end)
	{
		_Start = start;
		_End = end;
	}	

	static clsPeriod ReadPeriod(clsPeriod Period)
	{
		cout << "\nEnter Start Date:\n";
		Period.Start = clsDate::ReadFullDate(Period.Start);

		cout << "\nEnter End Date:\n";
		Period.End = clsDate::ReadFullDate(Period.End);

		return Period;
	}
	void ReadPeriod()
	{
		*this = ReadPeriod(*this);
	}

	static short DaysInPeriod(clsPeriod Period, bool IncludEndDay = false)
	{
		return clsDate::DaysBetweenDate1Date2(Period.Start, Period.End, IncludEndDay);
	}
	short DaysInPeriod(bool IncludEndDay = false)
	{
		return DaysInPeriod(*this, IncludEndDay);
	}

	enum enDateCompare {
		Before = -1,
		Equal = 0,
		After = 1
	};

	static enDateCompare CompareDate(clsDate Date1, clsDate Date2)
	{
		if (clsDate::IsDate1BeforeDate2(Date1, Date2))
			return Before;
		else if (clsDate::IsDate1EqualsDate2(Date1, Date2))
			return Equal;
		else
			return After;
	}
	enDateCompare CompareDate()
	{
		return CompareDate(Start, End);
	}

	static bool IsOverlapPeriod(clsPeriod Period1, clsPeriod Period2)
	{
		return CompareDate(Period1.Start, Period2.End) != After && CompareDate(Period1.End, Period2.Start) != Before;
	}
	bool IsOverlapPeriod(clsPeriod Period2)
	{
		return IsOverlapPeriod(*this, Period2);
	}

	static bool IsDateWithInPeriod(clsDate Date, clsDate PeriodStart, clsDate PeriodEnd)
	{
		if (CompareDate(Date, PeriodStart) == Before || CompareDate(Date, PeriodEnd) == After)
			return false;

		return true;
	}

	static bool IsDateWithInPeriod(clsPeriod Period, clsDate Date)
	{
		if (CompareDate(Date, Period.Start) == Before || CompareDate(Date, Period.End) == After)
			return false;

		return true;
	}
	bool IsDateWithInPeriod(clsDate Date)
	{
		return IsDateWithInPeriod(*this, Date);
	}

	static short CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
	{
		short CountDays = 0;

		if (IsOverlapPeriod(Period1, Period2))
		{
			int Period1Lenght = DaysInPeriod(Period1, true);
			int Period2Lenght = DaysInPeriod(Period2, true);

			if (Period1Lenght < Period2Lenght)
			{
				while (clsDate::IsDate1BeforeDate2(Period1.Start, Period1.End))
				{
					if (IsDateWithInPeriod(Period2, Period1.Start))
						CountDays++;

					Period1.Start = clsDate::IncreseDateByOneDay(Period1.Start);
				}
			}
			else
			{
				while (clsDate::IsDate1BeforeDate2(Period2.Start, Period2.End))
				{
					if (IsDateWithInPeriod(Period1, Period2.Start))
						CountDays++;

					Period2.Start = clsDate::IncreseDateByOneDay(Period2.Start);
				}
			}
		}
		else
			return 0;

		return CountDays;
	}
	short CountOverlapDays(clsPeriod Period2)
	{
		return CountOverlapDays(*this, Period2);
	}
};
