#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate
{
	short _Year;
	short _Month;
	short _Day;

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
	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	static clsDate ReadFullDate(clsDate Date)
	{		
		Date.Day = ReadNumInRange("Please enter a day : ", 1, 31);
		Date.Month = ReadNumInRange("Please enter a Month : ", 1, 12);
		Date.Year = ReadNumInRange("Please enter a Year : ", 1, 5000);		
		return Date;
	}
	void ReadFullDate()
	{
		*this = ReadFullDate(*this);
	}

	clsDate()
	{
		time_t t = time(0);
		tm* Now = localtime(&t);
		_Year = Now->tm_year + 1900;
		_Month = Now->tm_mon + 1;
		_Day = Now->tm_mday;
	}

	clsDate(string TextDate)
	{
		vector <string> vDate = clsString::SplitString(TextDate, "/");
		if (vDate.size() == 3)
		{
			_Day = stoi(vDate[0]);
			_Month = stoi(vDate[1]);
			_Year = stoi(vDate[2]);
		}
	}

	clsDate(short day, short month, short year)
	{
		_Year = year;
		_Month = month;
		_Day = day;
	}

	clsDate(short days, short year)
	{
		*this = ConvertDaysToDate(days, year);
	}

	static string ReadDateString()
	{
		string StrDate;
		cout << "Please enter Date dd/mm/yyyy : ";
		cin >> StrDate;
		return StrDate;
	}

	static clsDate CovertStringToDate(string strDate)
	{
		vector <string> vDate = clsString::SplitString(strDate, "/");
		clsDate Date;
		if (vDate.size() == 3)
		{
			Date.Day = stoi(vDate[0]);
			Date.Month = stoi(vDate[1]);
			Date.Year = stoi(vDate[2]);
		}
		return Date;
	}

	static string Covert_clsDateToString(clsDate Date)
	{
		return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year) + "\n";
	}
	string Covert_clsDateToString()
	{
		return Covert_clsDateToString(*this);
	}

	static void PrintDate3Line(clsDate Date)
	{
		cout << "Day : " << Date.Day << endl;
		cout << "Month : " << Date.Month << endl;
		cout << "Year : " << Date.Year << endl;
		cout << endl;
	}
	void PrintDate3Line()
	{
		PrintDate(*this);
	}

	static void PrintDate(clsDate Date)
	{
		cout << "Date : " << Covert_clsDateToString(Date) << endl;
	}
	void PrintDate()
	{
		PrintDate(*this);
	}

	static bool IsLeapYear(clsDate Date)
	{
		return  (Date.Year % 4 == 0 && Date.Year % 100 != 0) || (Date.Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(*this);
	}

	static short DaysInYear(clsDate Date)
	{
		return IsLeapYear(Date) ? 366 : 365;
	}
	short DaysInYear()
	{
		return DaysInYear(*this);
	}

	static int HoursInYear(clsDate Date)
	{
		return DaysInYear(Date) * 24;
	}
	int HoursInYear()
	{
		return HoursInYear(*this);
	}

	static int MinutesInYear(clsDate Date)
	{
		return HoursInYear(Date) * 60;
	}
	int MinutesInYear()
	{
		return MinutesInYear(*this);
	}

	static int SecondsInYear(clsDate Date)
	{
		return MinutesInYear(Date) * 60;
	}
	int SecondsInYear()
	{
		return SecondsInYear(*this);
	}

	static short DaysInMonth(clsDate Date)
	{
		int Arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return IsLeapYear(Date) ? (Date.Month == 2 ? 29 : 28) : Arr[Date.Month];
	}
	short DaysInMonth()
	{
		return DaysInMonth(*this);
	}

	static short HoursInMonth(clsDate Date)
	{
		return DaysInMonth(Date) * 24;
	}
	short HoursInMonth()
	{
		return HoursInMonth(*this);
	}

	static int MinutesInMonth(clsDate Date)
	{
		return HoursInMonth(Date) * 60;
	}
	int MinutesInMonth()
	{
		return MinutesInMonth(*this);
	}

	static int SecondsInMonth(clsDate Date)
	{
		return MinutesInMonth(Date) * 60;
	}
	int SecondsInMonth()
	{
		return SecondsInMonth(*this);
	}

	static int NumberOfDayInWeek(clsDate Date)
	{
		float a = (14 - Date.Month) / 12;
		float y = Date.Year - a;
		float m = Date.Month + 12 * a - 2;

		int R = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12));

		return R % 7;
	}
	int NumberOfDayInWeek()
	{
		NumberOfDayInWeek(*this);
	}

	static string DayName(int DayNumInWeek)
	{
		string Days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

		return Days[DayNumInWeek];
	}
	string DayName()
	{
		return DayName(NumberOfDayInWeek(*this));
	}

	static string MonthsName(clsDate Date)
	{
		string MonthsName[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return MonthsName[Date.Month];
	}
	string MonthsName()
	{
		return MonthsName(*this);
	}

	static void PrintMonthCalendar(clsDate Date)
	{
		printf("\n\n________________%s________________\n\n", MonthsName(Date).c_str());

		for (short i = 0; i < 7; i++)
			cout << setw(5) << DayName(i);
		cout << endl;

		short DaysMonth = DaysInMonth(Date);

		short NumberOfDay = NumberOfDayInWeek(Date);

		short j;
		for (j = 0; j < NumberOfDay; j++)
			printf("     ");

		for (short i = 0; i < DaysMonth;)
		{
			for (; j < 7 && i < DaysMonth; j++)
			{
				printf("%5d", i + 1);
				i++;
			}
			j = 0;
			printf("\n");
		}
		cout << "___________________________________\n";
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(*this);
	}

	static void PrintYearCalender(clsDate Date)
	{
		cout << "___________________________________\n";
		printf("\tCalendar - %i\n", Date.Year);
		cout << "___________________________________";
		for (int i = 1; i < 13; i++)
			PrintMonthCalendar(Date);
	}
	void PrintYearCalender()
	{
		PrintYearCalender(*this);
	}

	static short CountDaysFromDay1InYear(clsDate Date)
	{
		short Month = Date.Month;
		Date.Month = 1;
		short NumOfDays = 0;
		for (int i = 1; i < Month; i++)
			NumOfDays += DaysInMonth(Date);

		NumOfDays += Date.Day;

		return NumOfDays;
	}
	short CountDaysFromDay1InYear()
	{
		return CountDaysFromDay1InYear(*this);
	}

	static clsDate ConvertDaysToDate(short Days, short Year)
	{
		clsDate Date;
		Date.Year = Year;

		short Month = 0;

		for (Month = 1; Month <= 12; Month++)
		{
			short day = DaysInMonth(Date);

			if (Days - day > 0)
				Days -= day;

			else
				break;
		}
		Date.Month = Month;
		Date.Day = Days;

		return Date;
	}

	static void AddDaysToDate(clsDate &Date, short DaysToAdd)
	{
		short RemainingDays = DaysToAdd + CountDaysFromDay1InYear(Date);
		short MonthDays = 0;
		Date.Month = 1;

		while (true)
		{
			MonthDays = DaysInMonth(Date);

			if (MonthDays <= RemainingDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}		
	}
	void AddDaysToDate(short DaysToAdd)
	{
		AddDaysToDate(*this, DaysToAdd);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return Date1.Year < Date2.Year ? true : (Date1.Year > Date2.Year ? false :
			(Date1.Month < Date2.Month ? true : (Date1.Month > Date2.Month ? false :
				(Date1.Day < Date2.Day ? true : false))));
	}
	bool IsDate1BeforeDate2(clsDate Date)
	{
		return IsDate1BeforeDate2(*this, Date);
	}

	static bool IsDate1EqualsDate2(clsDate Date1, clsDate Date2)
	{
		return Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false;
	}
	bool IsDate1EqualsDate2(clsDate Date)
	{
		return IsDate1EqualsDate2(*this, Date);
	}

	static bool IsLastDay(clsDate Date)
	{
		return Date.Day == DaysInMonth(Date);
	}
	bool IsLastDay()
	{
		return  IsLastDay(*this);
	}

	static bool IsLastMonth(clsDate Date)
	{
		return Date.Month == 12;
	}
	bool IsLastMonth()
	{
		return IsLastMonth(*this);
	}

	static clsDate IncreseDateByOneDay(clsDate Date)
	{
		Date.Day++;
		if (Date.Day > DaysInMonth(Date))
		{
			Date.Month++;
			Date.Day = 1;
		}

		if (Date.Month > 12)
		{
			Date.Year++;
			Date.Month = 1;
		}		
		return Date;
	}
	void IncreseDateByOneDay()
	{
		*this = IncreseDateByOneDay(*this);
	}

	static short DaysBetweenDate1Date2(clsDate Date1, clsDate Date2, bool IncludEndDay = false)
	{
		short NumberOfDays = 0;
		if (IsDate1BeforeDate2(Date1, Date2))
		{
			while (IsDate1BeforeDate2(Date1, Date2))
			{
				NumberOfDays++;
				Date1 = IncreseDateByOneDay(Date1);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(Date2, Date1))
			{
				NumberOfDays++;
				Date2 = IncreseDateByOneDay(Date2);
			}
			NumberOfDays *= -1;
			return IncludEndDay ? --NumberOfDays : NumberOfDays;
		}
		return IncludEndDay ? ++NumberOfDays : NumberOfDays;
	}
	short DaysBetweenDate1Date2(clsDate Date, bool IncludEndDay = false)
	{
		return DaysBetweenDate1Date2(*this, Date, IncludEndDay);
	}

	static clsDate IncroseDateByXdays(clsDate Date, short HowManyDays)
	{
		for (short i = 0; i < HowManyDays; i++)
			Date = IncreseDateByOneDay(Date);

		return Date;
	}
	void IncroseDateByXdays(short HowManyDays)
	{
		*this = IncroseDateByXdays(*this, HowManyDays);
	}

	static clsDate IncroseDateByOneWeek(clsDate Date)
	{
		Date = IncroseDateByXdays(Date, 7);

		return Date;
	}
	void IncroseDateByOneWeek()
	{
		*this = IncroseDateByOneWeek(*this);
	}

	static clsDate IncroseDateByXWeek(clsDate Date, short HowManyWeeks)
	{
		for (short i = 0; i < HowManyWeeks; i++)
			Date = IncroseDateByOneWeek(Date);

		return Date;
	}
	void IncroseDateByXWeek(short HowManyWeeks)
	{
		*this = IncroseDateByXWeek(*this, HowManyWeeks);
	}

	static clsDate IncroseDateByOneMonth(clsDate Date)
	{
		if (IsLastMonth(Date))
		{
			Date.Year++;
			Date.Month = 1;
		}
		else
			Date.Month++;

		if (Date.Day > DaysInMonth(Date))
			Date.Day = DaysInMonth(Date);

		return Date;
	}
	void IncroseDateByOneMonth()
	{
		*this = IncroseDateByOneMonth(*this);
	}

	static clsDate IncroseDateByXmonth(clsDate Date, short HowManyMonth)
	{
		for (short i = 0; i < HowManyMonth; i++)
			Date = IncroseDateByOneMonth(Date);

		return Date;
	}
	void IncroseDateByXmonth(short HowManyMonth)
	{
		*this = IncroseDateByXmonth(*this, HowManyMonth);
	}

	static clsDate IncroseDateByOneYear(clsDate Date)
	{
		Date.Year++;

		return Date;
	}
	void IncroseDateByOneYear()
	{
		*this = IncroseDateByOneYear(*this);
	}

	static clsDate IncroseDateByXyear(clsDate Date, short HowManyYear)
	{
		for (int i = 0; i < HowManyYear; i++)
			Date = IncroseDateByOneYear(Date);

		return Date;
	}
	void IncroseDateByXyear(short HowManyYear)
	{
		*this = IncroseDateByXyear(*this, HowManyYear);
	}

	static clsDate IncroseDateByXyearFaster(clsDate Date, short HowManyYear)
	{
		Date.Year += HowManyYear;

		return Date;
	}
	void IncroseDateByXyearFaster(short HowManyYear)
	{
		*this = IncroseDateByXyearFaster(*this, HowManyYear);
	}

	static clsDate IncroseDateByOneDecade(clsDate Date)
	{
		Date = IncroseDateByXyearFaster(Date, 10);

		return Date;
	}
	void IncroseDateByOneDecade()
	{
		*this = IncroseDateByOneDecade(*this);
	}

	static clsDate IncroseDateByXdecade(clsDate Date, short HowManyDecade)
	{
		for (int i = 0; i < HowManyDecade; i++)
			Date = IncroseDateByXyearFaster(Date, 10);

		return Date;
	}
	void IncroseDateByXdecade(short HowManyDecade)
	{
		*this = IncroseDateByXdecade(*this, HowManyDecade);
	}

	static clsDate IncroseDateByXdecadeFaster(clsDate Date, short HowManyDecade)
	{
		Date = IncroseDateByXyearFaster(Date, (10 * HowManyDecade));
		return Date;
	}
	void IncroseDateByXdecadeFaster(short HowManyDecade)
	{
		*this = IncroseDateByXdecadeFaster(*this, HowManyDecade);
	}

	static clsDate IncroseDateByOneCentury(clsDate Date)
	{
		Date.Year += 100;
		return Date;
	}
	void IncroseDateByOneCentury()
	{
		*this = IncroseDateByOneCentury(*this);
	}

	static clsDate IncroseDateByOneMillennium(clsDate Date)
	{
		Date.Year += 1000;
		return Date;
	}
	void IncroseDateByOneMillennium()
	{
		*this = IncroseDateByOneMillennium(*this);
	}

	static bool IsWeekend(short DayInWeek)
	{
		return DayInWeek == 5 || DayInWeek == 6;
	}
	bool IsWeekend()
	{
		return IsWeekend(NumberOfDayInWeek(*this));
	}

	static bool IsEndOfWeek(short DayInWeek)
	{
		return DayInWeek == 6;
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(NumberOfDayInWeek(*this));
	}

	static bool IsBusinessDay(short DayInWeek)
	{
		return !IsWeekend(DayInWeek);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(NumberOfDayInWeek(*this));
	}

	static short DaysUntilEndOfWeek(short Day)
	{
		return 6 - Day;
	}
	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(NumberOfDayInWeek(*this));
	}

	static short DaysUntilEndOfMonth(clsDate Date)
	{
		return DaysInMonth(Date) - Date.Day + 1;
	}
	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate Date)
	{
		clsDate DateEndOfYear;
		DateEndOfYear.Day = 31;
		DateEndOfYear.Month = 12;
		DateEndOfYear.Year = Date.Year;
		return DaysBetweenDate1Date2(Date, DateEndOfYear);
	}
	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static short DaysOfVacation(clsDate Date1, clsDate Date2)
	{
		short NumberOfDays = 0;

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			if (!IsWeekend(NumberOfDayInWeek(Date1)))
				NumberOfDays++;

			Date1 = IncreseDateByOneDay(Date1);
		}
		return NumberOfDays;
	}
	short DaysOfVacation(clsDate Date)
	{
		return DaysOfVacation(*this, Date);
	}

	static clsDate DateOfEndVacation(clsDate DateVacStart, short VacationDays)
	{
		while (VacationDays > 0)
		{
			if (IsBusinessDay(NumberOfDayInWeek(DateVacStart)))
				VacationDays--;

			DateVacStart = IncreseDateByOneDay(DateVacStart);
		}

		while (!IsBusinessDay(NumberOfDayInWeek(DateVacStart)))
			DateVacStart = IncreseDateByOneDay(DateVacStart);

		return DateVacStart;
	}
	void DateOfEndVacation(short VacationDays)
	{
		*this = DateOfEndVacation(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualsDate2(Date1, Date2);
	}
	bool IsDate1AfterDate2(clsDate Date)
	{
		return IsDate1AfterDate2(*this, Date);
	}	

	static bool IsValidateDate(clsDate Date)
	{
		if (Date.Month > 12 || Date.Month < 1)
			return false;

		else if (Date.Day > DaysInMonth(Date) || Date.Day < 1)
			return false;

		return true;
	}
	bool IsValidateDate()
	{
		return IsValidateDate(*this);
	}

	enum enFormatDate {
		enDay, enMonth, enYear
	};

	static void PrintFormatDate(clsDate Date, enFormatDate Format1, enFormatDate Format2, enFormatDate Format3, string Sep)
	{
		string Date_String = "";

		if (Sep == "T")
		{
			switch (Format1)
			{
			case enDay: Date_String += "Day: " + to_string(Date.Day) + ", "; break;
			case enMonth: Date_String += "Month: " + to_string(Date.Month) + ", "; break;
			case enYear: Date_String += "Year: " + to_string(Date.Year) + ", "; break;
			}

			switch (Format2)
			{
			case enDay: Date_String += "Day: " + to_string(Date.Day) + ", "; break;
			case enMonth: Date_String += "Month: " + to_string(Date.Month) + ", "; break;
			case enYear: Date_String += "Year: " + to_string(Date.Year) + ", "; break;
			}

			switch (Format3)
			{
			case enDay: Date_String += "Day: " + to_string(Date.Day); break;
			case enMonth: Date_String += "Month: " + to_string(Date.Month); break;
			case enYear: Date_String += "Year: " + to_string(Date.Year); break;
			}
		}
		else
		{
			switch (Format1)
			{
			case enDay: Date_String += to_string(Date.Day) + Sep; break;
			case enMonth: Date_String += to_string(Date.Month) + Sep; break;
			case enYear: Date_String += to_string(Date.Year) + Sep; break;
			}

			switch (Format2)
			{
			case enDay: Date_String += to_string(Date.Day) + Sep; break;
			case enMonth: Date_String += to_string(Date.Month) + Sep; break;
			case enYear: Date_String += to_string(Date.Year) + Sep; break;
			}

			switch (Format3)
			{
			case enDay: Date_String += to_string(Date.Day); break;
			case enMonth: Date_String += to_string(Date.Month); break;
			case enYear: Date_String += to_string(Date.Year); break;
			}
		}
		cout << Date_String << "\n\n";
	}
	void PrintFormatDate(enFormatDate Format1, enFormatDate Format2, enFormatDate Format3, string Sep)
	{
		PrintFormatDate(*this, Format1, Format2, Format3, Sep);
	}
};



