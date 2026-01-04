#pragma once
#include "clsScreen.h";
#include "clsMainScreen.h";
#include "Global.h";

class clsLogin : protected clsScreen
{
private:
	static void _Login() {
		bool LoginFailed = false;
		string userName, pass;
		short tries = 3;

		do {
			if (LoginFailed) {
				cout << "\n\nInvalid Username/Password!\n";
				cout << "You have " << --tries << " to login.\n";
				if (tries == 0) {
					cout << "\nYou are locked after 3 failed trials.\n\n";
					IsLocked = true;
					return;
				}
			}

			cout << "\nEnter Username? ";
			cin >> userName;
			cout << "Enter Password? ";
			cin >> pass;

			currUser = clsUser::Find(userName, pass);

			LoginFailed = currUser.IsEmpty();

		} while (LoginFailed);

		currUser.SaveLoginLogs();
		clsMainScreen::ShowMainMenu();
	}

public:
	static void ShowLoginScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\tLogin Screen");
		
		_Login();
	}
};

