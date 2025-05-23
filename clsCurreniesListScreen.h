#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsCurreniesListScreen : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(30) << Currency.GetCountry();
        cout << "| " << setw(5) << Currency.GetCurrencyCode();
        cout << "| " << setw(42) << Currency.GetCurrencyName();
        cout << "| " << setw(10) << Currency.GetRate();
    }

public:
	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t  ( " + to_string(vCurrencies.size()) + " ) Currencies.";
		_DrawScreenHeader(Title, SubTitle);

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(30) << "Country";
        cout << "| " << setw(5) << "Code";
        cout << "| " << setw(42) << "Name";
        cout << "| " << setw(10) << "Rate/(1$)";
        cout << "\n" << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Are Available In The System!\n";

        for (clsCurrency& C : vCurrencies)
        {
            _PrintCurrencyRecordLine(C);
            cout << "\n";
        }

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";
	}
};

