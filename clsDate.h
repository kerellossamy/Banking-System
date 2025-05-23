#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include "clsString.h";

using namespace std;

class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;


public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string DateString) 
	{
		vector<string> vDate = clsString::Split(DateString, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year) 
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year) 
	{
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);

		_Day = Date1.Day;
		_Month = Date1.Month;
		_Year = Date1.Year;
	}


	void SetDay(short Day) 
	{
		_Day = Day;
	}

	short GetDay() 
	{
		return _Day;
	}
	
	__declspec(property(put = SetDay, get = GetDay)) short Day;


	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth() {
		return _Month;
	}
	
	__declspec(property(put = SetMonth, get = GetMonth)) short Month;


	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear() {
		return _Year;
	}
	
	__declspec(property(put = SetYear, get = GetYear)) short Year;


	void Print() 
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;

		return clsDate(Day, Month, Year);
	}

	static string GetSystemTimeString(bool is12HourFormat = false)
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		//Hours
		short hour = now->tm_hour;
		string Hours;
		bool isAM = true;

		if (is12HourFormat)
		{
			if (hour >= 0 && hour < 12)
			{
				if (hour == 0)
				{
					hour = 12;
				}

				isAM = true;
			}

			else if (hour >= 12)
			{
				if (hour > 12)
				{
					hour -= 12;
				}

				isAM = false;
			}
		}
		Hours = FormatNumbersLessThan10(hour);


		//Minutes
		//putting zero to make it looks good like -> 11:00 , 4:05
		short min = now->tm_min;
		string Minutes = FormatNumbersLessThan10(min);

		string Time = Hours + ":" + Minutes;
		return (is12HourFormat ? (isAM ? (Time + " AM") : (Time + " PM")) : Time);
	}

	//this for log files (ex: LoginRegister)
	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " 
			+ to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
	}

	static bool IsValidDate(clsDate Date)
	{
		return !(
			Date.Day < 1 || Date.Day > 31 ||
			Date.Month < 1 || Date.Month > 12 ||
			Date.Year < 1 ||
			(Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
			);
	}

	bool IsValid() 
	{
		return IsValidDate(*this);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsLeapYear(short Year) 
	{
		return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
	}

	bool IsLeapYear() 
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year) 
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear() 
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year) {
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear() {
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year) {
		return NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear() {
		return NumberOfSecondsInAYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Month, short Year) {

		if (Month < 1 || Month > 12)
			return 0;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}

	short NumberOfDaysInAMonth() {
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static short NumberOfHoursInAMonth(short Month, short Year) 
	{
		return NumberOfDaysInAMonth(Month, Year) * 24;
	}

	short NumberOfHoursInAMonth() 
	{
		return NumberOfHoursInAMonth(_Month, _Year);
	}

	static int NumberOfMinutesInAMonth(short Month, short Year) 
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInAMonth() 
	{
		return NumberOfMinutesInAMonth(_Month, _Year);
	}

	static int NumberOfSecondsInAMonth(short Month, short Year) 
	{
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInAMonth() 
	{
		return NumberOfSecondsInAMonth(_Month, _Year);
	}

	static short GetDayOfWeekOrder(short Day, short Month, short Year)
	{
		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short GetDayOfWeekOrder()
	{
		return GetDayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short DayOfWeekOrder) 
	{
		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	static string DayShortName(short Day, short Month, short Year)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[GetDayOfWeekOrder(Day, Month, Year)];
	}
	
	string DayShortName() 
	{
		return DayShortName(GetDayOfWeekOrder(_Day, _Month, _Year));
	}

	static string MonthShortName(short Month)
	{
		string arrMonthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return arrMonthNames[Month - 1];
	}

	string MonthShortName() 
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		short DayOrder = GetDayOfWeekOrder(1, Month, Year);
		short NumberOfDaysInMonth = NumberOfDaysInAMonth(Month, Year);

		//c_str() converts the string to array of char because printf can't used with strings
		printf("\n  _______________%s________________\n\n", MonthShortName(Month).c_str());
		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n";

		short i;
		for (i = 0; i < DayOrder; i++)
		{
			printf("     ");
		}

		for (short j = 1; j <= NumberOfDaysInMonth; j++)
		{
			printf("%5d", j);

			if (++i == 7) {
				i = 0;
				printf("\n");
			}
		}

		printf("\n  __________________________________\n");
	}

	void PrintMonthCalendar() 
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(short Year)
	{
		cout << "\n  __________________________________\n\n";
		cout << "           Calendar - " << Year;
		cout << "\n  __________________________________\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}

	void PrintYearCalendar() 
	{
		PrintYearCalendar(_Year);
	}

	static short NumberOfDaysFromYearBeginning(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		return TotalDays + Day;
	}

	short NumberOfDaysFromYearBeginning() 
	{
		return NumberOfDaysFromYearBeginning(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
	{
		clsDate Date;
		Date.Year = Year;
		Date.Month = 1;

		short RemainingDays = DayOrderInYear;
		short MonthDays = 0;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return ((Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)) : false));
	}

	bool IsDateBeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
			return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false);
	}

	bool IsDateEqualDate2(clsDate Date2) 
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	bool IsDateAfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}

	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month) 
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear() 
	{
		return IsLastMonthInYear(_Month);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int DifferenceDays = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DifferenceDays++;
			Date1 = AddOneDay(Date1);
		}

		return IncludeEndDay ? ++DifferenceDays * SwapFlagValue : DifferenceDays * SwapFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false) 
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static short CalculateMyAgeInDays(clsDate DateOfBirth) 
	{
		return GetDifferenceInDays(DateOfBirth, GetSystemDate(), true);
	}

	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month)) {
				Date.Year++;
				Date.Month = 1;
				Date.Day = 1;
			}
			else {
				Date.Month++;
				Date.Day = 1;
			}
		}
		else {
			Date.Day++;
		}

		return Date;
	}

	void AddOneDay() 
	{
		*this = AddOneDay(*this);
	}

	static clsDate AddDays(clsDate Date, short DaysToAdd)
	{
		short RemainingDays = DaysToAdd + NumberOfDaysFromYearBeginning(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;

		Date.Month = 1;
		Date.Day = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12) {
					Date.Year++;
					Date.Month = 1;
				}
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	void AddDays(short Days)
	{
		*this = AddDays(*this, Days);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 0; i < 7; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByOneWeek() 
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate Date, short Weeks)
	{
		for (short i = 0; i < Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks) 
	{
		*this = IncreaseDateByXWeeks(*this, Weeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		Date.Month++;

		if (Date.Month > 12)
		{
			Date.Month = 1;
			Date.Year++;
		}

		// example if date is 31/1/2022 increasing one month should
		//not be 31 / 2 / 2022, it should be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth() 
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate Date, short Months)
	{
		for (short i = 0; i < Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Months) 
	{
		*this = IncreaseDateByXMonths(*this, Months);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date.Year++;
		return Date;
	}

	void IncreaseDateByOneYear() 
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate Date, short Years)
	{
		Date.Year += Years;
		return Date;
	}

	void IncreaseDateByXYears(short Years) 
	{
		*this = IncreaseDateByXYears(*this, Years);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		Date.Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate Date, short Decades)
	{
		Date.Year += (Decades * 10);
		return Date;
	}

	void IncreaseDateByXDecades(short Decades) 
	{
		*this = IncreaseDateByXDecades(*this, Decades);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date.Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury() 
	{
		*this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year += 1000;
		return Date;
	}

	void IncreaseDateByOneMillennium() 
	{
		*this = IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay() 
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate Date, short Days)
	{
		for (short i = 0; i < Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByXDays(short Days) 
	{
		*this = DecreaseDateByXDays(*this, Days);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 0; i < 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek() 
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate Date, short Weeks)
	{
		for (short i = 0; i < Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks) {
		*this = DecreaseDateByXWeeks(*this, Weeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		Date.Month--;

		if (Date.Month < 1)
		{
			Date.Month = 12;
			Date.Year--;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/3/2022 decreasing one month 
		// should not be 31 / 2 / 2022, it should be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void DecreaseDateByOneMonth() {
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate Date, short Months)
	{
		for (short i = 0; i < Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months) {
		*this = DecreaseDateByXMonths(*this, Months);
	}
	
	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date.Year--;
		return Date;
	}

	void DecreaseDateByOneYear() {
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate Date, short Years)
	{
		Date.Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(short Years) 
	{
		*this = DecreaseDateByXYears(*this, Years);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade() {
		*this = DecreaseDateByOneDecade(*this);
	}
	
	static clsDate DecreaseDateByXDecades(clsDate Date, short Decades)
	{
		Date.Year -= (Decades * 10);
		return Date;
	}

	void DecreaseDateByXDecades(short Decades) 
	{
		*this = DecreaseDateByXDecades(*this, Decades);
	}
	
	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury() 
	{
		*this = DecreaseDateByOneCentury(*this);
	}
	
	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return (GetDayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6);
	}

	bool IsEndOfWeek() 
	{
		return IsEndOfWeek(*this);
	}
	
	static bool IsWeekEnd(clsDate Date)
	{
		short DayOfWeekOrder = GetDayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return (DayOfWeekOrder == 5 || DayOfWeekOrder == 6);
	}

	bool IsWeekEnd() 
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return (!IsWeekEnd(Date));
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return (6 - GetDayOfWeekOrder(Date.Day, Date.Month, Date.Year));
	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;

		EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;

		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}

	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short BusinessDays = 0;

		if (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			while (IsDate1BeforeDate2(DateFrom, DateTo))
			{
				if (IsBusinessDay(DateFrom))
					BusinessDays++;

				DateFrom = AddOneDay(DateFrom);
			}
		}
		else {
			cout << "\nDate From must be less than Date To\n";
			return 0;
		}

		return IsBusinessDay(DateTo) ? ++BusinessDays : BusinessDays;
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		//in case the data is weekend keep adding one day until you reach business day
		//we get rid of all weekends before the first business day
		//this while loop is like the while loop at the end of this function
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.
		//if you need the VacationEnd Date (before the ReturnDay with one day) subtract 1 from the for loop at the end
		for (short i = 0; i < VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(DateFrom)) {
				WeekEndCounter++;
			}

			DateFrom = AddOneDay(DateFrom);
		}

		//in case the return date is weekend keep adding one day until you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOneDay(DateFrom);
		}

		return DateFrom;
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static string FormatNumbersLessThan10(short Number)
	{
		return ((Number < 10) ? "0" + to_string(Number) : to_string(Number));
	}

	
	/*static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = clsString::ReplaceWord(DateFormat, "dd", FormatNumbersLessThan10(Date.Day));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "mm", FormatNumbersLessThan10(Date.Month));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "yyyy", FormatNumbersLessThan10(Date.Year));

		return FormattedDateString;
	}*/



	//New FormatDate Method, Made after making a Replace method which is replace the string as it is
	//and not have an isMatchCase feature
	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = clsString::Replace(DateFormat, "dd", FormatNumbersLessThan10(Date.Day));
		FormattedDateString = clsString::Replace(FormattedDateString, "yyyy", FormatNumbersLessThan10(Date.Year));

		if (DateFormat == "mm dd, yyyy")
		{
			FormattedDateString = clsString::Replace(FormattedDateString, "mm", MonthShortName(Date.Month));
		}
		else 
		{
			FormattedDateString = clsString::Replace(FormattedDateString, "mm", FormatNumbersLessThan10(Date.Month));
		}

		return FormattedDateString;
	}

	string FormatDate(string DateFormat = "dd/mm/yyyy") 
	{
		return FormatDate(*this, DateFormat);
	}
};
