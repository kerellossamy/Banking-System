#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurreniesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMenuScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeMenuOptions
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
	};

	static short _ReadCurrencyExchangeMenuOption()
	{
		cout << setw(30) << "" << "Choose what do you want to do? [1 to 5]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Please enter a number between 1 to 5: ");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << setw(30) << "" << "\nPress any key to go back to currency exchange menu...";

		system("pause > 0");
		ShowCurrencyExchangeMenuScreen();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurreniesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOption)
	{
		switch (CurrencyExchangeMenuOption)
		{
		case enCurrencyExchangeMenuOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeMenuOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeMenuOptions::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeMenuOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeMenuOptions::eMainMenu:
		{
			//we don't do any thing here, the main screen will handle it.
		}
		}
	}


public:

	static void ShowCurrencyExchangeMenuScreen()
	{
		system("cls");
		_DrawScreenHeader("     Currency Exchange Main Screen");

		cout << setw(30) << "" << "=========================================\n";
		cout << setw(40) << "" << "Currency Exchange Menu\n";
		cout << setw(30) << "" << "=========================================\n";
		cout << setw(30) << "" << "\t[1] List Currencies.\n";
		cout << setw(30) << "" << "\t[2] Find Currency.\n";
		cout << setw(30) << "" << "\t[3] Update Currency Rate.\n";
		cout << setw(30) << "" << "\t[4] Currency Calculator.\n";
		cout << setw(30) << "" << "\t[5] Main Menu.\n";
		cout << setw(30) << "" << "=========================================\n";

		_PerformCurrencyExchangeMenuOption((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
	}

};

