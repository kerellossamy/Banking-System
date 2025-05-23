#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsTransferBalanceScreen: protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n" << setw(32) << "" << "Client Card:";
		cout << "\n" << setw(32) << "" << "___________________";
		cout << "\n" << setw(32) << "" << "Full Name   : " << Client.FullName();
		cout << "\n" << setw(32) << "" << "Acc. Number : " << Client.AccountNumber;
		cout << "\n" << setw(32) << "" << "Balance     : " << Client.AccountBalance;
		cout << "\n" << setw(32) << "" << "___________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(32) << "" << "The Account is not found.\n\n"
				<< setw(32) << "" << "Please enter another account number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static double _ReadTransferAmount(clsBankClient SenderClient)
	{
		double TransferAmount = 0;
		cout << "\n\n" << setw(32) << "" << "Enter transfer amount: ";
		TransferAmount = clsInputValidate::ReadDblNumberBetween(0, std::numeric_limits<double>::max(), "Please enter a positive number: ");

		double SenderClientBalance = SenderClient.AccountBalance;

		while (TransferAmount > SenderClientBalance)
		{
			cout << setw(32) << "" << "You can NOT Transfer, Insuffecient Balance!!\n\n"
				<< setw(32) << "" << "Enter tranfer amount until [" << SenderClientBalance << "]: ";

			TransferAmount = clsInputValidate::ReadDblNumberBetween(0, std::numeric_limits<double>::max(), "Please enter a positive number: ");
		}

		return TransferAmount;
	}
	

public:
	static void ShowTransferBalanceScreen()
	{
		_DrawScreenHeader("\tTransfer Balance Screen");

		cout << "\n" << setw(32) << "" << "Enter an account number to transfer balance from: ";
		clsBankClient SenderClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SenderClient);

		//=====  Check the accounts are not the same (me)  ========
		string ReceiverAccountNumber;
		bool isSameAccount = true;

		do 
		{
			cout << "\n" << setw(32) << "" << "Enter an account number to transfer balance to: ";
			ReceiverAccountNumber = _ReadAccountNumber();

			if (SenderClient.AccountNumber == ReceiverAccountNumber)
				cout << setw(32) << "" << "You can not transfer balance to the same bank account.\n";
			else
				isSameAccount = false;

		} while (isSameAccount);
		//=========================================================

		clsBankClient ReceiverClient = clsBankClient::Find(ReceiverAccountNumber);
		_PrintClient(ReceiverClient);

		double TransferAmount = _ReadTransferAmount(SenderClient);
		
		char Choice = 'n';
		cout << "\n" << setw(32) << "" << "Are you sure you want to perform this transaction (Y/N): ";
		cin >> Choice;

		if (Choice == 'Y' || Choice == 'y')
		{
			if (SenderClient.Transfer(TransferAmount, ReceiverClient, CurrentUser.UserName))
			{
				cout << "\n" << setw(32) << "" << "Amount Transfered Successfully :-)\n";

				_PrintClient(SenderClient);
				_PrintClient(ReceiverClient);
			}
			else 
			{
				cout << "\n" << setw(32) << "" << "Transaction Failed.\n";
			}
		}
		else {
			cout << "\n" << setw(32) << "" << "Transaction was cancelled.\n";
		}
	}
};

