#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h";
#include "clsScreen.h";
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
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

    //================================= From Me ================================
    enum enWhatToUpdate
    {
        UpdateAll = 1, UpdateFirstName = 2, UpdateLastName = 3,
        UpdateEmail = 4, UpdatePhone = 5, UpdatePinCode = 6, UpdateBalance = 7
    };

    static void _ReadClientFirstName(clsBankClient& Client)
    {
        cout << "\n" << setw(32) << "" << "Enter First Name : ";
        Client.FirstName = clsInputValidate::ReadString();
    }

    static void _ReadClientLastName(clsBankClient& Client)
    {
        cout << "\n" << setw(32) << "" << "Enter Last Name: ";
        Client.LastName = clsInputValidate::ReadString();
    }

    static void _ReadClientEmail(clsBankClient& Client)
    {
        cout << "\n" << setw(32) << "" << "Enter Email: ";
        Client.Email = clsInputValidate::ReadString();
    }

    static void _ReadClientPhone(clsBankClient& Client)
    {
        cout << "\n" << setw(32) << "" << "Enter Phone Number: ";
        Client.Phone = clsInputValidate::ReadString();
    }

    static void _ReadClientPinCode(clsBankClient& Client)
    {
        cout << "\n" << setw(32) << "" << "Enter Pin Code: ";
        Client.PinCode = clsInputValidate::ReadString();
    }

    static void _ReadClientAccountBalance(clsBankClient& Client)
    {
        cout << "\n" << setw(32) << "" << "Enter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    static enWhatToUpdate _ShowWhatToUpdateMenu()
    {
        cout << "\n\n" << setw(32) << "" << "Choose What To Update : \n";
        cout << setw(32) << "" << "1) All\n";
        cout << setw(32) << "" << "2) First Name\n";
        cout << setw(32) << "" << "3) Last Name\n";
        cout << setw(32) << "" << "4) Email\n";
        cout << setw(32) << "" << "5) Phone Number\n";
        cout << setw(32) << "" << "6) Pin Code\n";
        cout << setw(32) << "" << "7) Balance\n";
        cout << setw(32) << "" << "____________________\n";
        cout << setw(32) << "" << "Choose what to update: ";

        return (enWhatToUpdate)clsInputValidate::ReadIntNumberBetween(1, 7);
    }

    static void _ChooseWhatToUpdate(enWhatToUpdate WhatToUpdate, clsBankClient& Client)
    {
        switch (WhatToUpdate)
        {
        case UpdateAll:
            _ReadClientInfo(Client);
            break;

        case UpdateFirstName:
            _ReadClientFirstName(Client);
            break;

        case UpdateLastName:
            _ReadClientLastName(Client);
            break;

        case UpdateEmail:
            _ReadClientEmail(Client);
            break;

        case UpdatePhone:
            _ReadClientPhone(Client);
            break;

        case UpdatePinCode:
            _ReadClientPinCode(Client);
            break;

        case UpdateBalance:
            _ReadClientAccountBalance(Client);
            break;
        }
    }
    //==========================================================================

public:
	static void ShowUpdateClientScreen()
	{
        if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClient))
        {
            return;// this will exit the function and it will not continue
        }


		_DrawScreenHeader("\t  Update Client Screen");

		cout << setw(32) << "";
		cout << "Enter an Account Number to update: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(32) << "" << "The Account is not found.\n\n" 
				<< setw(32) << "" << "Please enter another account number: ";

			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

        char Choice = 'n';
        cout << setw(32) << "" << "Are you sure you want to update this client (Y/N): ";
        cin >> Choice;

        if (Choice == 'y' || Choice == 'Y')
        {
            _ChooseWhatToUpdate(_ShowWhatToUpdateMenu(), Client);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client.Save();

            switch (SaveResult)
            {
                case clsBankClient::svSucceeded:
                {
                    cout << "\n" << setw(32) << "" << "Client Updated Successfully :-)\n";
                    _PrintClient(Client);
                    break;
                }
                case clsBankClient::svFailedEmptyObject:
                {
                    cout << "\n" << setw(32) << "" << "Client was Not updated because the object is empty.\n";
                    break;
                }
           }
        }        
	}
};

