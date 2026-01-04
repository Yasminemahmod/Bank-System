#pragma once
#include "clsScreen.h";
#include "clsUsersListScreen.h";
#include "clsAddUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";



class clsManageUsersScreen : protected clsScreen
{
private:
	string _MngUsrsMenuArr[6] = { "List Users", "Add New User", "Delete User", "Update User", "Find User", "Main Menu" };
	short _len = sizeof(_MngUsrsMenuArr) / sizeof(_MngUsrsMenuArr[0]);
	enum enMngUsrsMenuOpt { SHOW = 1, ADD = 2, DELETE = 3, UPDATE = 4, FIND = 5, MAINMENU = 6 };


	static void _ShowUsersListScreen() {
		//cout << "\nUsers List will be here\n";
		clsUsersListScreen::ShowUsersListScreen();
	}

	static void _ShowAddUserScreen() {
		//cout << "\nAdd User will be here\n";
		clsAddUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen() {
		//cout << "\nDelete User will be here\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen() {
		//cout << "\nUpdate User will be here\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen() {
		//cout << "\nFind User will be here\n";
		clsFindUserScreen::ShowFindUserScreen();
	}


	static void _GoBackToManageUsersMenuScreen() {
		cout << "\n\nEnter any key to go back to main menu...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _PerformManageUsersMenuOptions(enMngUsrsMenuOpt op) {
		switch (op)
		{
		case enMngUsrsMenuOpt::SHOW:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enMngUsrsMenuOpt::ADD:
			system("cls");
			_ShowAddUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enMngUsrsMenuOpt::DELETE:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enMngUsrsMenuOpt::UPDATE:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enMngUsrsMenuOpt::FIND:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enMngUsrsMenuOpt::MAINMENU:
			// Go Back To Main Menu Screen
			break;
		}
	}

public:

	static void ShowManageUsersScreen() {
		system("cls");

		if (!currUser.CheckAccessPermission(clsUser::pMngUsers)) {
			clsScreen::_CheckAccessRights("Manage Users Screen");
			cout << "\n\n" << setw(10) << left << "" << "Enter any key to go back to main menu...";
			system("pause>0");
			return;
		}

		clsScreen::_DrawScreenHeader("Manage Users Screen");
		
		clsManageUsersScreen Mngsers;
		short op = clsScreen::_DrawMenu("Manage Users Menu", Mngsers._MngUsrsMenuArr, Mngsers._len);
		_PerformManageUsersMenuOptions((enMngUsrsMenuOpt)op);
	}

};

