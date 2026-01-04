#pragma once
#include "clsScreen.h";

class clsDeleteUserScreen : protected clsScreen
{

public:
	static void ShowDeleteUserScreen() {
		clsScreen::_DrawScreenHeader("    Delete User Screen");
		

		string userName = clsInputValidate::ReadString("\n\nPlease Enter UserName: ");
		if (userName == "q" || userName == "Q") return;

		while (!clsUser::IsUserExist(userName)) {
			userName = clsInputValidate::ReadString("\nUser is bot found, Choose another one: ");
			if (userName == "q" || userName == "Q") return;
		}

		clsUser user = clsUser::Find(userName);

		clsScreen::_PrintUser(user);

		char answer = 'n';
		cout << "\nAre you sure you want to delete this user? (y/n)? ";
		cin >> answer;

		if (tolower(answer) == 'y') {
			user.Delete();
			cout << "\nUser Deleted Successfully :-)\n";
			clsScreen::_PrintUser(user);
		}
	}
};

