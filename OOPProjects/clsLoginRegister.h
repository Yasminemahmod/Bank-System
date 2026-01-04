#pragma once
#include "clsScreen.h";

class clsLoginRegister : protected clsScreen
{
private:
	static void _PrintLogsRecordLine(clsUser::stLogRegRec log) {
		cout << setw(10) << left << "" << "| " << setw(40) << left << log.DateTime <<
			"| " << setw(20) << log.UserName <<
			"| " << setw(15) << log.Password <<
			"| " << setw(25) << log.Permissions << endl;
	}

public:
	static void _ShowLoginRegisterScreen() {

		if (!currUser.CheckAccessPermission(clsUser::pLogReg)) {
			clsScreen::_CheckAccessRights("   Client List Screen");
			return;
		}


		vector<clsUser::stLogRegRec> logs = clsUser::GetLogsList();
		string subTitle = "\t    (" + to_string(logs.size()) + ") Record(s)";
		clsScreen::_DrawScreenHeader("Login Register List Screen", subTitle);

		cout << "\n" << setw(10) << left << "" << "_______________________________________________________________________________________________________\n\n";
		cout << setw(10) << left << "" << "| " << setw(40) << left << "Date/Time" <<
			"| " << setw(20) << "UserName" <<
			"| " << setw(15) << "Password" <<
			"| " << setw(25) << "Permissions";
		cout << "\n" << setw(10) << left << "" << "_______________________________________________________________________________________________________\n\n";

		if (logs.size() == 0) {
			cout << "\t\t\t\tNo Logs Records AvailableIn The System";
		}
		else {
			for (clsUser::stLogRegRec& log : logs) {
				_PrintLogsRecordLine(log);
			}
		}
		cout << setw(10) << left << "" << "_______________________________________________________________________________________________________\n";

	}
};

