#pragma once
#include<iostream>
#include<iomanip>
#include "clsInputValidate.h";
#include "clsUser.h";
#include "clsScreen.h";
using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:
	static int _ReadPermissionsToSet()
	{
		int TotalPermissions = 0;
		char Choice = 'n';

		cout << "\n" << setw(32) << "" << "Set Permissions For This New User\n";
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

	static void _ReadNewUserInfo(clsUser& User)
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

public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t Add New User Screen");

		cout << setw(32) << "" << "Please Enter User Name: ";
		string UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << setw(32) << "" << "This user name is already used.\n\n"
				<< setw(32) << "" << "Please enter another user name: ";

			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadNewUserInfo(NewUser);
		
		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svSucceeded:
		{
			cout << "\n" << setw(32) << "";
			cout << "User Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::svFailedEmptyObject:
		{
			cout << "\n" << setw(32) << "";
			cout << "\nFailed Save because the object is empty.\n";
			break;
		}
		case clsUser::svFailedUserExists:
		{
			cout << "\n" << setw(32) << "";
			cout << "\nFailed Save because the user name is used.\n";
			break;
		}
		}
	}

};

