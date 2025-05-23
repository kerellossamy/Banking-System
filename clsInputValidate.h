#pragma once

#include "clsDate.h"

class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		//My Code is more optimized than the incructor
		if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
			clsDate::SwapDates(DateFrom, DateTo);

		return !(
			(clsDate::IsDate1BeforeDate2(Date, DateFrom)) ||
			(clsDate::IsDate1AfterDate2(Date, DateTo))
			);
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again: ")
	{
		short Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Invalid Number, Enter agian: ")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}

		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again: ")
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Invalid Number, Enter again: ")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again: ")
	{
		float Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Invalid Number, Enter again: ")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again: ")
	{
		double Number;

		/*
		* (Number == 0.0 && signbit(Number)) ==> Check for the -0
		*/

		while (!(cin >> Number) || (Number == 0.0 && signbit(Number)))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}
	
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Invalid Number, Enter again: ")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S = "";
		getline(cin >> ws, S);

		return S;
	}

};

