#pragma once

#include "clsScreen.h";
#include "clsUser.h";

class clsUsersListScreen : protected clsScreen
{
private:
	static void _ShowUsersList(clsUser user) {
		cout << setw(5) << left << "" << "| " << setw(15) << left << user.UserName <<
			"| " << setw(25) << user.FullName() <<
			"| " << setw(15) << user.Phone <<
			"| " << setw(20) << user.Email <<
			"| " << setw(9) << user.Password <<
			"| " << user.Permission << "\n";
	}

public:
	static void ShowUsersListScreen() {
		vector<clsUser> users = clsUser::GetUsersList();
		string subTitle = "\t\t  (" + to_string(users.size()) + ") User(s)";
		clsScreen::_DrawScreenHeader("\tUser List Screen", subTitle);
		

		cout << "\n\n\n" << setw(5) << left << "" << "_____________________________________________________________________________________________________________\n\n";
		cout << setw(5) << left << "" << "| " << setw(15) << left << "UserName" <<
			"| " << setw(25) << "Full Name" <<
			"| " << setw(15) << "Phone" <<
			"| " << setw(20) << "Email" <<
			"| " << setw(9) << "Password" <<
			"| " << "Permission\n";
		cout << setw(5) << left << "" << "_____________________________________________________________________________________________________________\n\n";


		if (users.size() == 0) {
			cout << "\t\t\t\tNo Clients AvailableIn The System";
		}
		else {
			for (clsUser& u : users) {
				_ShowUsersList(u);
			}
		}
		cout << setw(5) << left << "" << "_____________________________________________________________________________________________________________\n\n";

	}

};

