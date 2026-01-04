#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsClientListScreen.h";
#include "clsAddNewClient.h";
#include "clsDeleteClient.h";
#include "clsUpdateClient.h";
#include "clsFindClient.h";
#include "clsTransactionScreen.h";
#include "clsManageUsersScreen.h";
#include "clsLoginRegister.h";
#include "clsCurrencyMainScreen.h";
#include "Global.h";

class clsMainScreen : protected clsScreen
{
private:
	
	string _MainMenuArr[10] = { "Show Client List", "Add New Client", "Delete Client", "Update Client Info", "Find Client", "Transaction", "Manage Users", "Login Register", "Currency Exchange","Logout"};
	short _len = sizeof(_MainMenuArr) / sizeof(_MainMenuArr[0]);
	enum enMainMenuOpt { SHOW = 1, ADD = 2, DELETE = 3, UPDATE = 4, FIND = 5, TRANS = 6, MANAGE = 7, LOGREG = 8 ,CURREXCHANGE = 9, LOGOUT = 10 };



	static void _ShowAllClientsList() {

		clsClientListScreen::ShowClientsList();
		
	}

	static void _ShowAddNewClientsScreen() {
		
		clsAddNewClient::ShowAddNewClientsScreen();

	}

	static void _ShowDeleteClientScreen() {
		clsDeleteClient::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {
		clsUpdateClient::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {
		clsFindClient::ShowFindClientScreen();
	}

	static void _ShowTransactionScreen() {
		clsTransactionScreen::ShowTransactionMenu();
	}

	static void _ShowManageUsersScreen() {
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen() {
		clsLoginRegister::_ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyMainScreen() {
		clsCurrencyMainScreen::ShowCurrencyMainScreen();
	}

	static void _Logout() {
		currUser = clsUser::Find("", "");

		// Will go back to Login screen
	}



	static void _GoBackToMainMenu() {
		cout << "\n\nEnter any key to go back to main menu...";
		system("pause>0");
		ShowMainMenu();
	}

	static void _PerformMainMenuOption(enMainMenuOpt option) {
		switch (option)
		{
		case enMainMenuOpt::SHOW:
			system("cls");
			_ShowAllClientsList();
			_GoBackToMainMenu();
			break;
		case enMainMenuOpt::ADD:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOpt::DELETE:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOpt::UPDATE:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOpt::FIND:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOpt::TRANS:
			_ShowTransactionScreen();
			ShowMainMenu();
			break;
		case enMainMenuOpt::MANAGE:
			_ShowManageUsersScreen();
			ShowMainMenu();
			break;
		case enMainMenuOpt::LOGREG:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOpt::CURREXCHANGE:
			_ShowCurrencyMainScreen();
			ShowMainMenu();
			break;
		case enMainMenuOpt::LOGOUT:
			system("cls");
			_Logout();
			break;
		}
	}


public:

	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("\tMain Screen");
		
		clsMainScreen mainScreen;
		short op = _DrawMenu("\tMain Menu", mainScreen._MainMenuArr, mainScreen._len);
		_PerformMainMenuOption((enMainMenuOpt)op);
	}

};

