#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h";
#include"clsUser.h";
#include"clsScreen.h";
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:
	static int _ReadPermissionsToSet()
	{
		int TotalPermissions = 0;
		char Choice = 'n';

		cout << "\n" << setw(32) << "" << "Set Permissions For This User\n";
		cout << setw(32) << "" << "__________________________________\n";

		cout << setw(32) << "" << "Do you want to give this user all the permissions (Y/N): ";
		cin >> Choice;

		if (Choice == 'Y' || Choice == 'y')
		{
			return clsUser::enPermissions::pAll;
		}
		else
		{
			cout << "\n" << setw(32) << "" << "Has permission to Client List (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pListClients;

			cout << "\n" << setw(32) << "" << "Has permission to Add New Client (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pAddNewClient;

			cout << "\n" << setw(32) << "" << "Has permission to Delete Client (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pDeleteClient;

			cout << "\n" << setw(32) << "" << "Has permission to Update Client (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pUpdateClient;

			cout << "\n" << setw(32) << "" << "Has permission to Find Client (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pFindClient;

			cout << "\n" << setw(32) << "" << "Has permission to Transactions (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pTransactions;

			cout << "\n" << setw(32) << "" << "Has permission to Manage Users (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pManageUsers;

			cout << "\n" << setw(32) << "" << "Has permission to Login Register List (Y/N): ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
				TotalPermissions += clsUser::enPermissions::pListLoginRegister;
		}

		return TotalPermissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << setw(32) << "";
		cout << "Enter First Name  : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Last Name   : ";
		User.LastName = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Email       : ";
		User.Email = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Phone Number: ";
		User.Phone = clsInputValidate::ReadString();

		cout << setw(32) << "";
		cout << "Enter Password    : ";
		User.Password = clsInputValidate::ReadString();

		User.Permissions = _ReadPermissionsToSet();
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\n" << setw(32) << "" << "User Card:";
		cout << "\n" << setw(32) << "" << "___________________";
		cout << "\n" << setw(32) << "" << "FirstName  : " << User.FirstName;
		cout << "\n" << setw(32) << "" << "LastName   : " << User.LastName;
		cout << "\n" << setw(32) << "" << "Full Name  : " << User.FullName();
		cout << "\n" << setw(32) << "" << "Email      : " << User.Email;
		cout << "\n" << setw(32) << "" << "Phone      : " << User.Phone;
		cout << "\n" << setw(32) << "" << "User Name  : " << User.UserName;
		cout << "\n" << setw(32) << "" << "Password   : " << User.Password;
		cout << "\n" << setw(32) << "" << "Permissions: " << User.Permissions;
		cout << "\n" << setw(32) << "" << "___________________\n";
	}

	//================================= From Me ================================
	enum enWhatToUpdate
	{
		UpdateAll = 1, UpdateFirstName = 2, UpdateLastName = 3, UpdateEmail = 4,
		UpdatePhone = 5, UpdatePassword = 6, UpdatePermissions = 7
	};

	static void _ReadUserFirstName(clsUser& User)
	{
		cout << "\n" << setw(32) << "" << "Enter First Name : ";
		User.FirstName = clsInputValidate::ReadString();
	}

	static void _ReadUserLastName(clsUser& User)
	{
		cout << "\n" << setw(32) << "" << "Enter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
	}

	static void _ReadUserEmail(clsUser& User)
	{
		cout << "\n" << setw(32) << "" << "Enter Email: ";
		User.Email = clsInputValidate::ReadString();
	}

	static void _ReadUserPhone(clsUser& User)
	{
		cout << "\n" << setw(32) << "" << "Enter Phone Number: ";
		User.Phone = clsInputValidate::ReadString();
	}
	
	static void _ReadUserPassword(clsUser& User)
	{
		cout << "\n" << setw(32) << "" << "Enter Password: ";
		User.Password = clsInputValidate::ReadString();
	}

	static void _ReadUserPermissions(clsUser& User)
	{
		User.Permissions = _ReadPermissionsToSet();
	}

	static void _ChooseWhatToUpdate(enWhatToUpdate WhatToUpdate, clsUser& User)
	{
		switch (WhatToUpdate)
		{
		case UpdateAll:
			_ReadUserInfo(User);
			break;

		case UpdateFirstName:
			_ReadUserFirstName(User);
			break;

		case UpdateLastName:
			_ReadUserLastName(User);
			break;

		case UpdateEmail:
			_ReadUserEmail(User);
			break;

		case UpdatePhone:
			_ReadUserPhone(User);
			break;

		case UpdatePassword:
			_ReadUserPassword(User);
			break;

		case UpdatePermissions:
			_ReadUserPermissions(User);
			break;
		}
	}

	static enWhatToUpdate _ShowWhatToUpdateMenu()
	{
		cout << "\n\n" << setw(32) << "" << "Update Menu: \n";
		cout << setw(32) << "" << "____________________\n\n";
		cout << setw(32) << "" << "1) All\n";
		cout << setw(32) << "" << "2) First Name\n";
		cout << setw(32) << "" << "3) Last Name\n";
		cout << setw(32) << "" << "4) Email\n";
		cout << setw(32) << "" << "5) Phone Number\n";
		cout << setw(32) << "" << "6) Password\n";
		cout << setw(32) << "" << "7) Permissions\n";
		cout << setw(32) << "" << "____________________\n";
		cout << setw(32) << "" << "Choose what to update: ";

		return (enWhatToUpdate)clsInputValidate::ReadIntNumberBetween(1, 7);
	}

	//==========================================================================


public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t   Update User Screen");

		cout << setw(32) << "" << "Please Enter User Name: ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << setw(32) << "" << "This user name is not found.\n\n"
				<< setw(32) << "" << "Please enter another user name: ";

			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char Choice = 'n';
		cout << setw(32) << "" << "Are you sure you want to update this user (Y/N): ";
		cin >> Choice;

		if (Choice == 'Y' || Choice == 'y')
		{
			_ChooseWhatToUpdate(_ShowWhatToUpdateMenu(), User);

			clsUser::enSaveResults SaveResult;
			SaveResult = User.Save();

			switch (SaveResult)
			{
				case clsUser::svSucceeded:
				{
					cout << "\n" << setw(32) << "" << "User Updated Successfully :-)\n";
					_PrintUser(User);
					break;
				}
				case clsUser::svFailedEmptyObject:
				{
					cout << "\n" << setw(32) << "" << "User was Not updated because the object is empty.\n";
					break;
				}
			}
		}
		else
		{
			cout << "\n" << setw(32) << "" << "Operation was cancelled.\n";
		}
	}
};

