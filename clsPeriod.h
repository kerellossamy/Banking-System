#pragma once
#include "clsDate.h";

class clsPeriod
{
	
private:
	clsDate _StartDate;
	clsDate _EndDate;
	
	
public:

	clsPeriod(clsDate StartDate, clsDate EndDate) 
	{
		_StartDate = StartDate;
		_EndDate = EndDate;
	}


	void Print()
	{
		cout << "Period Start: ";
		_StartDate.Print();


		cout << "Period End  : ";
		_EndDate.Print();
	}

	static bool IsOverlappedPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		return !(
			clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::clsDate::enDateCompare::Before ||
			clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::clsDate::enDateCompare::After
			);
	}

	bool IsOverlappedWith(clsPeriod Period2)
	{
		return IsOverlappedPeriods(*this, Period2);
	}

	static int GetPeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
	{
		if (clsDate::CompareDates(Period._StartDate, Period._EndDate) == clsDate::enDateCompare::Before)
		{
			return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate, IncludeEndDay);
		}
		else
		{
			cout << "The Start Date must be before the End Date.\n";
			exit(0);
		}
	}

	int GetPeriodLengthInDays(bool IncludeEndDay = false)
	{
		return GetPeriodLengthInDays(*this, IncludeEndDay);
	}

	static bool IsDateInPeriod(clsDate Date, clsPeriod Period)
	{
		return !(
			clsDate::CompareDates(Date, Period._StartDate) == clsDate::enDateCompare::Before ||
			clsDate::CompareDates(Date, Period._EndDate) == clsDate::enDateCompare::After
			);
	}

	bool IsDateInPeriod(clsDate Date) {
		return IsDateInPeriod(Date, *this);
	}

	static int CountOverlappedDays(clsPeriod Period1, clsPeriod Period2)
	{
		int OverlappedDay = 0;

		int Period1Length = GetPeriodLengthInDays(Period1, true);
		int Period2Length = GetPeriodLengthInDays(Period2, true);

		if (Period1Length < Period2Length)
		{
			while (!clsDate::IsDate1AfterDate2(Period1._StartDate, Period1._EndDate))
			{
				if (IsDateInPeriod(Period1._StartDate, Period2))
					OverlappedDay++;

				Period1._StartDate = clsDate::AddOneDay(Period1._StartDate);
			}
		}
		else
		{
			while (!clsDate::IsDate1AfterDate2(Period2._StartDate, Period2._EndDate))
			{
				if (IsDateInPeriod(Period2._StartDate, Period1))
					OverlappedDay++;

				Period2._StartDate = clsDate::AddOneDay(Period2._StartDate);
			}
		}

		return OverlappedDay;
	}

	int CountOverlappedDaysWith(clsPeriod Period2) 
	{
		return CountOverlappedDays(*this, Period2);
	}
};

