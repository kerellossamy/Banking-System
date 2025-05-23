#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h";
#include "clsScreen.h";
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n" << setw(32) << "" << "Client Card:";
		cout << "\n" << setw(32) << "" << "___________________";
		cout << "\n" << setw(32) << "" << "FirstName   : " << Client.FirstName;
		cout << "\n" << setw(32) << "" << "LastName    : " << Client.LastName;
		cout << "\n" << setw(32) << "" << "Full Name   : " << Client.FullName();
		cout << "\n" << setw(32) << "" << "Email       : " << Client.Email;
		cout << "\n" << setw(32) << "" << "Phone       : " << Client.Phone;
		cout << "\n" << setw(32) << "" << "Acc. Number : " << Client.AccountNumber;
		cout << "\n" << setw(32) << "" << "Password    : " << Client.PinCode;
		cout << "\n" << setw(32) << "" << "Balance     : " << Client.AccountBalance;
		cout << "\n" << setw(32) << "" << "___________________\n";
	}

public:
	static void ShowDeleteClientScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t  Delete Client Screen");

		cout << setw(32) << "";
		cout << "Enter an Account Number to delete: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(32) << "" << "The Account is not found.\n\n" 
				<< setw(32) << "" << "Please enter another account number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Choice = 'n';
		cout << setw(32) << "" << "Are you sure you want to delete this client (Y/N): ";
		cin >> Choice;

		if (Choice == 'y' || Choice == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\n" << setw(32) << "" << "Client Deleted Successfully :-)\n";
			}
			else {
				cout << setw(32) << "" << "Client Was NOT Deleted..\n";
			}
		}
	}
};

