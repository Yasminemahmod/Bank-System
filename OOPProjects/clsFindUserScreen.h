#pragma once
#include "clsScreen.h";

class clsFindUserScreen : protected clsScreen
{

public:
	static void ShowFindUserScreen() {
		clsScreen::_DrawScreenHeader("    Find User Screen");
		

		string userName = clsInputValidate::ReadString("\n\nPlease Enter User Name: ");
		if (userName == "q" || userName == "Q") return;

		while (!clsUser::IsUserExist(userName)) {
			userName = clsInputValidate::ReadString("\nUser is bot found, Choose another one: ");
			if (userName == "q" || userName == "Q") return;
		}

		clsUser user = clsUser::Find(userName);

		if (!user.IsEmpty()) {
			cout << "\nUser Found -:)\n";
			clsScreen::_PrintUser(user);
		}
		else {
			cout << "\nUser was not Found -:(\n";
		}
	}
};

