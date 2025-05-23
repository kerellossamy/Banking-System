#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enFindOptions { CurrencyCode = 1, CurrencyCountry = 2 };

	static short _ReadFindOption()
	{
		cout << setw(32) << "" << "Please enter your option: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Please enter a number between 1 to 2: ");
		return Choice;
	}

	static void _PerformFindOption(enFindOptions FindOption)
	{
		switch (FindOption)
		{
		case clsFindCurrencyScreen::CurrencyCode:
		{
			_FindCurrencyByCode();
			break;
		}
		case clsFindCurrencyScreen::CurrencyCountry:
		{
			_FindCurrencyByCountry();
			break;
		}
		}
	}

	static void _FindCurrencyByCode()
	{
		cout << "\n" << setw(32) << "" << "Please enter currency code: ";
		string CurrencyCode = clsInputValidate::ReadString();
		
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_ShowResults(Currency);
	}

	static void _FindCurrencyByCountry()
	{
		cout << "\n" << setw(32) << "" << "Please enter currency country: ";
		string CurrencyCountry = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

		_ShowResults(Currency);
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n" << setw(32) << "" << "Currency Found :)\n";
			_PrintCurrencyCard(Currency);
		}
		else {
			cout << "\n" << setw(32) << "" << "Currency is NOT found \n";
		}
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n" << setw(32) << "" << "Currency Card:\n";
		cout << setw(32) << "" << "_____________________________\n";
		cout << setw(32) << "" << "Country    : " << Currency.GetCountry() << "\n";
		cout << setw(32) << "" << "Code       : " << Currency.GetCurrencyCode() << "\n";
		cout << setw(32) << "" << "Name       : " << Currency.GetCurrencyName() << "\n";
		cout << setw(32) << "" << "Rate(1$)   : " << Currency.GetRate() << "\n";
		cout << setw(32) << "" << "_____________________________\n";
	}
	

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		cout << setw(32) << "" << "Find By:\n";
		cout << setw(32) << "" << "[1] Code\n";
		cout << setw(32) << "" << "[2] Country\n";
		cout << setw(32) << "" << "======================================\n";

		_PerformFindOption((enFindOptions)_ReadFindOption());		
	}
};

