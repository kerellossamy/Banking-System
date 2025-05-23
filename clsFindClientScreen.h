#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h";
#include "clsScreen.h";

class clsFindClientScreen : protected clsScreen
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
	static void ShowFindClientScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;// this will exit the function and it will not continue
		}


		_DrawScreenHeader("\t  Find Client Screen");

		cout << setw(32) << "" << "Enter an Account Number to find: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(32) << "" << "The Account is not found.\n\n"
				<< setw(32) << "" << "Please enter another account number : ";

			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\n" << setw(32) << "" << "Client Is Found.\n";
			_PrintClient(Client);
		}
		else {
			cout << "\n" << setw(32) << "" << "Client is NOT found.\n";
		}
	}
};

