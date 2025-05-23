#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsMainMenuScreen.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFailed = false;
		string UserName, Password;
		short FailedLoginCounter = 0;
	
		do
		{
			cout << setw(32) << "";
			cout << "Enter User Name: ";
			UserName = clsInputValidate::ReadString();

			cout << setw(32) << "";
			cout << "Enter Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

			if (LoginFailed)
			{
				FailedLoginCounter++;
				
				if (FailedLoginCounter == 3)
				{
					cout << "\n" << setw(32) << "" << "The account is locked after 3 failed trials";
					cout << "\n" << setw(32) << "" << "Please Contact your admin!\n\n";
					return false;
				}

				cout << "\n" << setw(32) << "" << "Invalid Username or Password!";
				cout << "\n" << setw(32) << "" << "You have " << (3 - FailedLoginCounter) << " Trial(s) left.\n\n";
				system("pause > 0");
			}

		} while (LoginFailed);

		CurrentUser.RegisterLogin();

		clsMainMenuScreen::ShowMainMenu();
		return true;
	}

public:

	//if it returns false means that the account is locked
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t     Login Screen");
		return _Login();
	}
};