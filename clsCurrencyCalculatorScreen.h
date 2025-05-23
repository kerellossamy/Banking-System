#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static clsCurrency _GetCurrency(string Message)
	{
		cout << "\n" << setw(32) << "" << Message;

		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << setw(32) << "" << "Currency Code is not found, enter another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static float _ReadAmountToExchange(string Message)
	{
		cout << "\n" << setw(32) << "" << Message;
		float Amount = clsInputValidate::ReadFloatNumberBetween(0, numeric_limits<float>::max(), "Enter a posivite number: ");
		
		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{
		cout << "\n\n" << setw(32) << "" << Title << "\n";
		cout << setw(32) << "" << "_____________________________\n";
		cout << setw(32) << "" << "Country    : " << Currency.GetCountry() << "\n";
		cout << setw(32) << "" << "Code       : " << Currency.GetCurrencyCode() << "\n";
		cout << setw(32) << "" << "Name       : " << Currency.GetCurrencyName() << "\n";
		cout << setw(32) << "" << "Rate(1$)   : " << Currency.GetRate() << "\n";
		cout << setw(32) << "" << "_____________________________\n";
	}
	
	static void _PrintConvertToUSDResults(clsCurrency Currency1, float AmountToExchange, float AmountAfterExchange)
	{
		_PrintCurrencyCard(Currency1, "Convert From:");
		
		cout << "\n" << setw(32) << "" << AmountToExchange << " " << Currency1.GetCurrencyCode() << " = " << AmountAfterExchange << " USD" << "\n";
	}
	
	static void _PrintConvertFromUSDResults(clsCurrency Currency1, clsCurrency Currency2, float AmountToExchange, float AmountAfterExchange)
	{
		_PrintCurrencyCard(Currency2, "Convert To:");
		
		cout << "\n" << setw(32) << "" << AmountToExchange << " USD = " << AmountAfterExchange << " " << Currency2.GetCurrencyCode() << "\n";
	}

	static void _ConvertCurrencies(clsCurrency Currency1, clsCurrency Currency2, float AmountToExchange)
	{
		
		float AmountAfterExchange = 0;

		if (Currency1.GetCurrencyCode() == "USD")
		{
			AmountAfterExchange = Currency1.ConvertToAnotherCurrency(Currency2, AmountToExchange);
			_PrintConvertFromUSDResults(Currency1, Currency2, AmountToExchange, AmountAfterExchange);
		}
		else if (Currency2.GetCurrencyCode() == "USD")
		{
			AmountAfterExchange = Currency1.ConvertToUSD(AmountToExchange);
			_PrintConvertToUSDResults(Currency1, AmountToExchange, AmountAfterExchange);
		}
		else 
		{
			float AmountInUSD = Currency1.ConvertToUSD(AmountToExchange);
			_PrintConvertToUSDResults(Currency1, AmountToExchange, AmountInUSD);

			AmountAfterExchange = Currency1.ConvertToAnotherCurrency(Currency2, AmountInUSD);
			_PrintConvertFromUSDResults(Currency1, Currency2, AmountInUSD, AmountAfterExchange);


			cout << "\n\n" << setw(32) << "" << AmountToExchange << " " << Currency1.GetCurrencyCode() << " = "
				<< AmountAfterExchange << " " << Currency2.GetCurrencyCode() << "\n";
		}
	}
	

public:
	static void ShowCurrencyCalculatorScreen()
	{

		char Answer = 'n';

		do {
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("Please Enter Currency 1 Code: ");
			clsCurrency Currency2 = _GetCurrency("Please Enter Currency 2 Code: ");
			
			if (Currency1.GetCurrencyCode() == Currency2.GetCurrencyCode())
			{
				cout << "\n" << setw(32) << "" << "You can't exchange to the same currency!!\n";
				return;
			}

			float AmountToExchange = _ReadAmountToExchange("Please Enter Amount To Exchange: ");

			_ConvertCurrencies(Currency1, Currency2, AmountToExchange);


			cout << "\n" << setw(32) << "" << "Do you want to perform another calculation (Y/N): ";
			cin >> Answer;

		} while (toupper(Answer) == 'Y');

	}
};

