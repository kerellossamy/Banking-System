#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenuScreen.h"
#include "clsManageUsersMenuScreen.h"
#include "clsLoginRegisterListScreen.h"
#include "clsCurrencyExchangeMenuScreen.h"
using namespace std;

class clsMainMenuScreen : protected clsScreen
{
private:
	enum enMainMenuOptions {
		eListClients = 1, eAddClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eShowTransactionsMenu = 6, eShowManageUsersMenu = 7, 
		eListLoginRegister = 8, eCurrencyExchangeMenu = 9, eLogout = 10
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(30) << "" << "Choose what do you want to do? [1 to 10]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Please enter a number between 1 to 10: ");
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(30) << "" << "\nPress any key to go back to main menu...";

		system("pause > 0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientsListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenuScreen()
	{
		clsTransactionsMenuScreen::ShowTransactionsMenuScreen();
	}

	static void _ShowManageUsersMenuScreen()
	{
		clsManageUsersMenuScreen::ShowManageUsersMenuScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterListScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMenuScreen()
	{
		clsCurrencyExchangeMenuScreen::ShowCurrencyExchangeMenuScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}


	static void _PerformMainMenuOption(enMainMenuOptions enMainMenuOption)
	{
		switch (enMainMenuOption)
		{
		case enMainMenuOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eAddClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eShowTransactionsMenu:
		{
			system("cls");
			_ShowTransactionsMenuScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eShowManageUsersMenu:
		{
			system("cls");
			_ShowManageUsersMenuScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eListLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eCurrencyExchangeMenu:
		{
			system("cls");
			_ShowCurrencyExchangeMenuScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eLogout:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}


public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t       Main Screen");

		cout << setw(30) << "" << "=========================================\n";
		cout << setw(46) << "" << "Main Menu\n";
		cout << setw(30) << "" << "=========================================\n";
		cout << setw(30) << "" << "\t[1]  Show Clients List.\n";
		cout << setw(30) << "" << "\t[2]  Add New Client.\n";
		cout << setw(30) << "" << "\t[3]  Delete Client.\n";
		cout << setw(30) << "" << "\t[4]  Update Client Info.\n";
		cout << setw(30) << "" << "\t[5]  Find Client.\n";
		cout << setw(30) << "" << "\t[6]  Transactions.\n";
		cout << setw(30) << "" << "\t[7]  Manage Users.\n";
		cout << setw(30) << "" << "\t[8]  Login Register List.\n";
		cout << setw(30) << "" << "\t[9]  Currency Exchange.\n";
		cout << setw(30) << "" << "\t[10] Logout.\n";
		cout << setw(30) << "" << "=========================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}
};

