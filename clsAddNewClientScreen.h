#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h";
#include "clsScreen.h";

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadNewClientInfo(clsBankClient& Client)
	{
		cout << setw(32) << "";
		cout << "Enter First Name  : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Last Name   : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Email       : ";
		Client.Email = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Phone Number: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Pin Code    : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Balance     : ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

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
	static void ShowAddNewClientScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t  Add Client Screen");

		cout << setw(32) << "";
		cout << "Please Enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(32) << "";
			cout << "Sorry, The Account Number is already used.\n\n" << setw(32) << "" << "Please Enter another Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadNewClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
		{
			cout << "\n" << setw(32) << "";
			cout << "Client Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::svFailedEmptyObject:
		{
			cout << "\n" << setw(32) << "";
			cout << "\nFailed Save because the object is empty.\n";
			break;
		}
		case clsBankClient::svFailedAccountNumberExists:
		{
			cout << "\n" << setw(32) << "";
			cout << "\nFailed Save because the account number is used.\n";
			break;
		}
		}
	}
};

