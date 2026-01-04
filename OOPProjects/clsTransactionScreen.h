#pragma once
#include "clsScreen.h";
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";
#include "clsTransfer.h";
#include "clsTransferLogs.h";


class clsTransactionScreen : protected clsScreen
{
private:

	string _TranMenuArr[6] = { "Deposit", "Withdraw", "Total Balances", "Transfer", "Transfer Logs", "Main Menu"};
	short _len = sizeof(_TranMenuArr) / sizeof(_TranMenuArr[0]);
	enum enTransMenuOpt { DEPOSIT = 1, WITHDRAW = 2, TOTALBAL = 3, TRANSFER = 4, TRANSFERLOGS = 5, MAINMENU = 6 };



	static void _GoBackToTransactionMenu() {
		cout << "\n\nEnter any key to go back to main menu...";
		system("pause>0");
		ShowTransactionMenu();
	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen(){
		clsTransfer::ShowTransferScreen();
	}

	static void _ShowTransferLogsScreen() {
		clsTransferLogs::ShowTransferLogsScreen();
	}

	static void _PerformTransactionMenuOption(enTransMenuOpt option) {			
		switch (option)
		{
			case enTransMenuOpt::DEPOSIT:
				system("cls");
				_ShowDepositScreen();
				_GoBackToTransactionMenu();
				break;
			case enTransMenuOpt::WITHDRAW:
				system("cls");
				_ShowWithdrawScreen();
				_GoBackToTransactionMenu();				
				break;
			case enTransMenuOpt::TOTALBAL:
				system("cls");
				_ShowTotalBalancesScreen();
				_GoBackToTransactionMenu();
				break;
			case enTransMenuOpt::TRANSFER:
				system("cls");
				_ShowTransferScreen();
				_GoBackToTransactionMenu();
				break;
			case enTransMenuOpt::TRANSFERLOGS:
				system("cls");
				_ShowTransferLogsScreen();
				_GoBackToTransactionMenu();
				break;
			case enTransMenuOpt::MAINMENU:
				// Go Back To Main Menu
				break;
		}
	}


public:
	static void ShowTransactionMenu() {
		system("cls");

		if (!currUser.CheckAccessPermission(clsUser::pTransaction)) {
			clsScreen::_CheckAccessRights("  Transaction Screen");
			cout << "\n\n" << setw(10) << left << "" << "Enter any key to go back to main menu...";
			system("pause>0");
			return;
		}

		
		_DrawScreenHeader("  Transaction Screen");
		
		clsTransactionScreen TanScreen;
		short op = _DrawMenu("  Transaction Menu", TanScreen._TranMenuArr, TanScreen._len);
		_PerformTransactionMenuOption((enTransMenuOpt)op);
	}
};

