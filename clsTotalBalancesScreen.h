#pragma once
#include<iostream>
#include<iomanip>
#include"clsUtil.h";
#include"clsBankClient.h";
#include"clsScreen.h";
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << left;
        cout << setw(15) << "";
        cout << "| " << setw(20) << Client.AccountNumber;
        cout << "| " << setw(30) << Client.FullName();
        cout << "| " << setw(20) << Client.AccountBalance;

    }
public:
	static void _ShowTotalBalancesScreen()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t Balances List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(15) << "";
        cout << "__________________________________________________________________________\n\n";

        cout << left;
        cout << setw(15) << "";
        cout << "| " << setw(20) << "Account Number";
        cout << "| " << setw(30) << "Client Name";
        cout << "| " << setw(20) << "Balance";
        cout << "\n" << setw(15) << "";
        cout << "__________________________________________________________________________\n\n";

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Are Available In The System!\n";

        else
        {
            for (clsBankClient& C : vClients)
            {
                _PrintClientRecordBalanceLine(C);
                cout << "\n";
            }
        }

        cout << setw(15) << "";
        cout << "__________________________________________________________________________\n\n";
        
        cout << "\t\t\t\t\t" << "Total Balances = " << TotalBalances << "\n";
        cout << "\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ")\n";
    }
};

