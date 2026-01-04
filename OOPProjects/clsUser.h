#pragma once
#include <vector>
#include <fstream>
#include "clsPerson.h";
#include "clsString.h";
#include "clsDate.h";
#include "clsUtil.h";
//#include "Global.h";

class clsUser : public clsPerson 
{
private:
	enum enMode{ enEmptyMode = 0, enUpdateMode = 1, enAddNewMode = 2 };
	enMode _mode;
	string _userName;
	string _password;
	int _permission;
	struct stLogRegRec;


	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLineToUser(string line) {
		vector<string> user = clsString::Split(line, "#//#");

		return clsUser(enMode::enUpdateMode, user[0], user[1], user[2], user[3], user[4], user[5], stoi(user[6]));
	}

	static string _ConvertUserObjectToLine(clsUser user, string sep = "#//#") {
		return (user.FirstName + sep + user.LastName + sep + user.Email + sep + user.Phone + sep + user.UserName + sep + clsUtil::EncryptText(user.Password) + sep + to_string(user.Permission));
	}

	static vector<clsUser> _LoadUsersFromFile() {
		fstream file;
		file.open("Users.txt", ios::in);

		vector<clsUser> vUsers;

		if (file.is_open()) {
			string line;

			while (getline(file, line)) {
				vUsers.push_back(_ConvertLineToUser(line));
			}

			file.close();
		}

		return vUsers;

	}

	static void _LoadUsersToFile(vector<clsUser> users) {
		fstream file;
		file.open("Users.txt", ios::out);

		if (file.is_open()) {
			string line;

			for (clsUser& u : users) {
				if (!u.IsEmpty()) {
					line = _ConvertUserObjectToLine(u);
					file << line << endl;
				}
			}

			file.close();
		}
	}

	static stLogRegRec _ConvertLinesToLogRec(string line, string sep = "#//#") {
		vector<string> rec = clsString::Split(line, sep);
		stLogRegRec log;

		log.DateTime = rec[0];
		log.UserName = rec[1];
		log.Password = clsUtil::DecryptText(rec[2]);
		log.Permissions = stoi(rec[3]);

		return log;
	}

	static vector<stLogRegRec> _LoadLogsFromFile() {
		fstream file;
		file.open("LoginRegister.txt", ios::in);

		vector<stLogRegRec> logs;

		if (file.is_open()) {
			string line;

			while (getline(file, line)) {

				logs.push_back(_ConvertLinesToLogRec(line));
			}

			file.close();
		}

		return logs;

	}

	/*static void _LoadUsersToFile(vector<clsUser> users) {*/

	void _AddNewUsers() {
		fstream file;
		file.open("Users.txt", ios::app);

		if (file.is_open()) {
			if (_mode == enMode::enAddNewMode) {
				file << _ConvertUserObjectToLine(*this) << endl;
				file.close();
			}
		}
	}

	void _Update() {
		vector<clsUser> users = _LoadUsersFromFile();

		for (clsUser& u : users) {
			if (u.UserName == _userName) {
				u = *this;
				break;
			}
		}
		_LoadUsersToFile(users);

	}

	string _PrepareLogInRecord(string sep = "#//#") {
		return clsDate::GetSystemDateTimeString() + sep + _userName + sep + _password + sep + to_string(_permission);
	}

	

public:
	clsUser(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permission) :
		clsPerson(firstName, lastName, email, phone) {
		_mode = mode;
		_userName = userName;
		_password = password;
		_permission = permission;
	}

	void setUserName(string userName) {
		_userName = userName;
	}

	string getUserName() {
		return _userName;
	}

	__declspec (property(get = getUserName, put = setUserName)) string UserName;

	void setPassword(string password) {
		_password = password;
	}

	string getPassword() {
		return _password;
	}

	__declspec (property(get = getPassword, put = setPassword)) string Password;

	void setPermission(int permission) {
		_permission = permission;
	}

	int getPermission() {
		return _permission;
	}

	__declspec (property(get = getPermission, put = setPermission)) int Permission;


	bool IsEmpty() {
		return (_mode == enMode::enEmptyMode);
	}

	static clsUser Find(string userName) {
		fstream file;
		file.open("Users.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsUser client = _ConvertLineToUser(line);

				if (client.UserName == userName) {
					file.close();
					return client;
				}
			}

			file.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string userName, string password) {
		clsUser usr = Find(userName);

		if (clsUtil::DecryptText(usr.Password) == password) {
			return usr;
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string userName) {
		clsUser user = Find(userName);
		return (!user.IsEmpty());
	}

	void Delete() {
		vector<clsUser> users = _LoadUsersFromFile();

		for (clsUser& u : users) {
			if (u.UserName == _userName) {
				u = _GetEmptyUserObject();
				break;
			}
		}

		_LoadUsersToFile(users);
		*this = _GetEmptyUserObject();
	}

	enum enSaveResults { svSucceeded = 0, svFailedEmptyObject = 1, svFailedExist = 2};

	enSaveResults Save() {

		switch (_mode)
		{
		case enMode::enEmptyMode:
			if (IsEmpty()) return enSaveResults::svFailedEmptyObject;;
			break;
		case enMode::enUpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;
		case enMode::enAddNewMode:
			if (clsUser::IsUserExist(_userName)) {
				return enSaveResults::svFailedExist;
			}
			else {
				_AddNewUsers();
				return enSaveResults::svSucceeded;
			}
			
			break;
		}
	}

	static clsUser GetAddNewUserObject(string userName) {
		return clsUser(enMode::enAddNewMode, "", "", "", "", userName, "", 0);
	}

	static vector<clsUser> GetUsersList() {
		return _LoadUsersFromFile();
	}

	enum enPermissions {pAccessAll = -1, pNotAccess = 0, pListClients = 1, pAddNewClient = 2,
		 pDeleteClient = 4, pUpdateClient = 8, pFindClietn = 16, pTransaction = 32, pMngUsers = 64, pLogReg = 128, pCurrExch = 256};

	bool CheckAccessPermission(enPermissions per) {
		
		if (_permission == int(enPermissions::pAccessAll)) return true;

		if (_permission == int(enPermissions::pNotAccess)) return false;

		if ((_permission & int(per)) == per) return true;
		else return false;
	}



	struct stLogRegRec {
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	void SaveLoginLogs() {
		fstream file;
		file.open("LoginRegister.txt", ios::out | ios::app);

		if (file.is_open()) {
			string line = _PrepareLogInRecord();

			if (line != "") {
				file << line << endl;
			}

			file.close();
		}
	}

	static vector<stLogRegRec> GetLogsList() {
		return _LoadLogsFromFile();
	}


};

