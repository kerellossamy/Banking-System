#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsListUsersScreen.h";
#include "clsAddNewUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";
using namespace std;

class clsManageUsersMenuScreen : protected clsScreen
{
private:
	enum enManageUsersMenuOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
	};

	static short _ReadManageUsersMenuOption()
	{
		cout << setw(30) << "" << "Choose what do you want to do? [1 to 6]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Please enter a number between 1 to 6: ");
		return Choice;
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << setw(30) << "" << "\nPress any key to go back to manage users menu...";

		system("pause > 0");
		ShowManageUsersMenuScreen();
	}

	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOption)
	{
		switch (ManageUsersMenuOption)
		{
			case enManageUsersMenuOptions::eListUsers:
			{
				system("cls");
				_ShowListUsersScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::eAddNewUser:
			{
				system("cls");
				_ShowAddNewUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::eDeleteUser:
			{
				system("cls");
				_ShowDeleteUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::eUpdateUser:
			{
				system("cls");
				_ShowUpdateUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::eFindUser:
			{
				system("cls");
				_ShowFindUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::eMainMenu:
			{
				//Nothing here, the main screen will handle it..
			}
		}
	}


public:
	static void ShowManageUsersMenuScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}


		system("cls");
		_DrawScreenHeader("\t  Manage Users Screen");

		cout << setw(30) << "" << "=========================================\n";
		cout << setw(43) << "" << "Manage Users Menu\n";
		cout << setw(30) << "" << "=========================================\n";
		cout << setw(30) << "" << "\t[1] List Users.\n";
		cout << setw(30) << "" << "\t[2] Add New User.\n";
		cout << setw(30) << "" << "\t[3] Delete User.\n";
		cout << setw(30) << "" << "\t[4] Update User.\n";
		cout << setw(30) << "" << "\t[5] Find User.\n";
		cout << setw(30) << "" << "\t[6] Main Menu.\n";
		cout << setw(30) << "" << "=========================================\n";

		_PerformManageUsersMenuOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}
};

