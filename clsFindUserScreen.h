#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h";
#include"clsUser.h";
#include"clsScreen.h";
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t    Find User Screen");

		cout << setw(32) << "" << "Please Enter User Name: ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << setw(32) << "" << "The user name is not found.\n\n"
				<< setw(32) << "" << "Please enter another user name : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
	
		if (!User.IsEmpty())
		{
			cout << "\n" << setw(32) << "" << "User Is Found.\n";
			_PrintUser(User);
		}
		else {
			cout << "\n" << setw(32) << "" << "User is NOT found.\n";
		}
	}
};

