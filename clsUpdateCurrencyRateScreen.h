#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static float _ReadNewRate()
	{
		cout << "\n" << setw(32) << "" << "Enter the new currency rate: ";

		float NewRate = clsInputValidate::ReadFloatNumberBetween(1, numeric_limits<float>::max(), "Please enter a positive number: ");

		return NewRate;
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
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("      Update Currency Rate Screen");

		cout << setw(32) << "" << "Please enter currency code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << setw(32) << "" << "Currency is not found, choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);		
		_PrintCurrencyCard(Currency);


		char Answer = 'n';
		do {
			cout << "\n" << setw(32) << "" << "Are you sure you want to update the currency rate? (Y/N): ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				Currency.UpdateRate(_ReadNewRate());

				cout << "\n" << setw(32) << "" << "Currency Rate Updated Successfully.\n";
				_PrintCurrencyCard(Currency);
			}

			else if (toupper(Answer) != 'Y' && toupper(Answer) != 'N')
			{
				cout << setw(32) << "" << "Wrong Choice.\n";
			}

		} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');

	}
};

