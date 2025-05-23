#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h";
using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(15) << Client.AccountNumber;
        cout << "| " << setw(20) << Client.FullName();
        cout << "| " << setw(20) << Client.Email;
        cout << "| " << setw(15) << Client.Phone;
        cout << "| " << setw(10) << Client.PinCode;
        cout << "| " << setw(10) << Client.AccountBalance;
    }


public:
	static void ShowClientsListScreen()
	{

        if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }


		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t  Clients List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

        cout << left;
        cout << setw(2) << "";
        cout << "| " << setw(15) << "Account Number";
        cout << "| " << setw(20) << "Client Name";
        cout << "| " << setw(20) << "Email";
        cout << "| " << setw(15) << "Phone Number";
        cout << "| " << setw(10) << "Pin Code";
        cout << "| " << setw(10) << "Balance";
        cout << "\n" << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Are Available In The System!\n";

        else
        {
            for (clsBankClient& C : vClients)
            {
                _PrintClientRecordLine(C);
                cout << "\n";
            }
        }

        cout << setw(2) << "";
        cout << "____________________________________________________________________________________________________\n\n";
	}
};

