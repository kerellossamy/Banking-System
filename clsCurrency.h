#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdatedMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData = clsString::Split(Line, Seperator);
		
		return clsCurrency(
			enMode::UpdatedMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string CurrencyRecord = "";
		CurrencyRecord += Currency.GetCountry() + Seperator;
		CurrencyRecord += Currency.GetCurrencyCode() + Seperator;
		CurrencyRecord += Currency.GetCurrencyName() + Seperator;
		CurrencyRecord += to_string(Currency.GetRate());

		return CurrencyRecord;
	}

	static vector<clsCurrency> _LoadAllCurrenciesFromFile()
	{
		vector<clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrencies;
	}

	static void _SaveAllCurrenciesToFile(vector<clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;

			for (clsCurrency C : vCurrencies)
			{
				Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line << endl;
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies = _LoadAllCurrenciesFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this;
				_SaveAllCurrenciesToFile(vCurrencies);
				return;
			}
		}
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetCountry()
	{
		return _Country;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float GetRate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string CurrencyCountry)
	{
		CurrencyCountry = clsString::UpperAllString(CurrencyCountry);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.GetCountry()) == CurrencyCountry)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadAllCurrenciesFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / GetRate());
	}

	float ConvertToAnotherCurrency(clsCurrency Currency2, float Amount)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(Amount * Currency2.GetRate());
	}


};

