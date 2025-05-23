#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferBalanceScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsMenuScreen : protected clsScreen
{
private:
	enum enTransactionsMenuOptions 
	{
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eTransferLog = 5, eMainMenu = 6
	};

	static short _ReadTransactionsMenuOption()
	{
		cout << setw(30) << "" << "Choose what do you want to do? [1 to 6]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Please enter a number between 1 to 6: ");
		return Choice;
	}

	static void _GoBackToTransactionsMenu()
	{
		cout << setw(30) << "" << "\nPress any key to go back to transactions menu...";

		system("pause > 0");
		ShowTransactionsMenuScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::_ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferBalanceScreen::ShowTransferBalanceScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}


	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
	{
		switch (TransactionsMenuOption)
		{
			case enTransactionsMenuOptions::eDeposit:
			{
				system("cls");
				_ShowDepositScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enTransactionsMenuOptions::eWithdraw:
			{
				system("cls");
				_ShowWithdrawScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enTransactionsMenuOptions::eTotalBalances:
			{
				system("cls");
				_ShowTotalBalancesScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enTransactionsMenuOptions::eTransfer:
			{
				system("cls");
				_ShowTransferScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enTransactionsMenuOptions::eTransferLog:
			{
				system("cls");
				_ShowTransferLogScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enTransactionsMenuOptions::eMainMenu:
			{
				//we don't do any thing here, the main screen will handle it.
			}
		}
	}


public:
	static void ShowTransactionsMenuScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;// this will exit the function and it will not continue
		}


		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(30) << "" << "=========================================\n";
		cout << setw(43) << "" << "Transactions Menu\n";
		cout << setw(30) << "" << "=========================================\n";
		cout << setw(30) << "" << "\t[1] Deposit.\n";
		cout << setw(30) << "" << "\t[2] Withdraw.\n";
		cout << setw(30) << "" << "\t[3] Total Balances.\n";
		cout << setw(30) << "" << "\t[4] Transfer.\n";
		cout << setw(30) << "" << "\t[5] Transfer Log.\n";
		cout << setw(30) << "" << "\t[6] Main Menu.\n";
		cout << setw(30) << "" << "=========================================\n";
		
		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}
};