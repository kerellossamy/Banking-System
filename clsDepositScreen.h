#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h";
#include "clsBankClient.h";
#include "clsScreen.h";
using namespace std;

class clsDepositScreen : protected clsScreen
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
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t    Deposit Screen");

		cout << setw(32) << "";
		cout << "Enter an account number to deposit: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(32) << "" << "The Account is not found.\n\n" 
				<< setw(32) << "" << "Please enter another account number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double DepositAmount = 0;
		cout << "\n" << setw(32) << "" << "Enter deposit amount: ";
		DepositAmount = clsInputValidate::ReadDblNumberBetween(0, std::numeric_limits<double>::max(), "Please enter a positive number: ");

		char Choice = 'n';
		cout << "\n" << setw(32) << "" << "Are you sure you want to perform this transaction (Y/N): ";
		cin >> Choice;

		if (Choice == 'Y' || Choice == 'y')
		{
			Client.Deposit(DepositAmount);
			cout << "\n" << setw(32) << "" << "Amount Deposited Successfully :-)\n";
			cout << "\n" << setw(32) << "" << "New balance is: " << Client.AccountBalance << "\n";
		}
		else {
			cout << "\n" << setw(32) << "" << "Transaction was cancelled.\n";
		}
	}
};

