	#pragma once
	#include <iostream>
	#include <string>
	#include <fstream>
	#include <vector>
	#include "clsPerson.h";
	#include "clsString.h";
	#include "clsDate.h";
	#include "Global.h";

	using namespace std;

	class clsBankClient : public clsPerson
	{
	private:
		enum enMode { enEmptyMode = 0, enUpdateMode = 1, enAddNewMode = 2 };

		enMode _mode;
		string _accountNumber;
		string _pinCode;
		float _accountBalance;

		struct stTransLogRec;


		static clsBankClient _ConvertLineToClientObject(string line) {
			//vClient = clsString::Split(line, "#//#");
			vector<string> vClient = clsString::Split(line, "#//#");

			return clsBankClient(enMode::enUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stoi(vClient[6]));
		}

		static clsBankClient _GetEmptyClientObject() {
			return clsBankClient(enMode::enEmptyMode, "", "", "", "", "", "", 0);
		}

		static string _convertClientObjectToLine(clsBankClient client, string sep = "#//#") {
			string clientRecord = "";
			clientRecord += client.FirstName + sep;
			clientRecord += client.LastName + sep;
			clientRecord += client.Email + sep;
			clientRecord += client.Phone + sep;
			clientRecord += client.AccountNumber() + sep;
			clientRecord += client.PinCode + sep;
			clientRecord += to_string(client.AccountBalance);

			return clientRecord;
		}

		static vector<clsBankClient> _LoadClientsFromFile() {
			vector<clsBankClient> vClients;
			fstream file;
			file.open("Clients.txt", ios::in);

			if (file.is_open()) {
				string line;

				while (getline(file, line)) {
					clsBankClient client = _ConvertLineToClientObject(line);
					vClients.push_back(client);
				}

				file.close();
			}
			return vClients;

		}

		static void _LoadClientsToFile(vector<clsBankClient> vClients) {
			fstream file;
			file.open("Clients.txt", ios::out);

			if (file.is_open()) {
				string line;

				for (clsBankClient& cl : vClients) {
					if (cl._mode == enUpdateMode) {
						line = _convertClientObjectToLine(cl);
							file << line << endl;
					}
				}

				file.close();
			}
		}

		void _Update() {
			vector<clsBankClient> vClients = _LoadClientsFromFile();

			for (clsBankClient& cl : vClients) {
				if (cl.AccountNumber() == AccountNumber()) {
					cl = *this;
					break;
				}
			}

			_LoadClientsToFile(vClients);

		}

		void _AddNewClient() {
			fstream file;
			file.open("Clients.txt", ios::app);

			if (file.is_open()) {
				string line;

				if (_mode == enMode::enAddNewMode) {
					line = _convertClientObjectToLine(*this);
					file << line << endl;
				}

				file.close();
			}
		}


		/*
			static string GetSystemDateTimeString() {
			short hour, min, sec;
			time_t t = time(0);
			tm* now = localtime(&t);
			hour = now->tm_hour;
			min = now->tm_min;
			sec = now->tm_sec;
			return DateToString(GetSystemDate()) + " - " + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
		}
	*/

		string _PrepareTransLogInRecord(clsBankClient receiver, float amt, string sep = "#//#") {
			return clsDate::GetSystemDateTimeString() + sep + _accountNumber + sep + receiver.AccountNumber() + sep
				+ to_string(amt) + sep + to_string(_accountBalance) + sep + to_string(receiver.AccountBalance) + sep + currUser.UserName;
		}

		void _SaveTransferLogs(clsBankClient receiver, float amt) {
			fstream file;
			file.open("TransferLogs.txt", ios::out | ios::app);

			if (file.is_open()) {
				string line = _PrepareTransLogInRecord(receiver, amt);
				if (line != "")  file << line << endl;

				file.close();
			}
		}

		static stTransLogRec _ConvertLogsToRecord(string log, string sep = "#//#") {
			stTransLogRec rec;
			vector<string> vLog = clsString::Split(log, sep);

			rec.DateTime = vLog[0];
			rec.SenderUser = vLog[1];
			rec.ReceiverUser = vLog[2];
			rec.SenderBal = stof(vLog[3]);
			rec.ReceiverBal = stof(vLog[4]);
			rec.Amount = stof(vLog[5]);
			rec.UserName = vLog[6];

			return rec;
		}

		static vector< stTransLogRec> _LoadTransferLogsFromFile() {
			fstream file;
			file.open("TransferLogs.txt", ios::in);
			vector<stTransLogRec> vLogs;

			if (file.is_open()) {
				string line;

				while (getline(file, line)) {
					vLogs.push_back(_ConvertLogsToRecord(line));
				}
				file.close();
			}

			return vLogs;
		}

	public:
		struct stTransLogRec {
			string DateTime;
			string SenderUser;
			string ReceiverUser;
			float SenderBal;
			float ReceiverBal;
			float Amount;
			string UserName;
		};

		//clsBankClient() {	
		//	*this = _GetEmptyClientObject();
		//}

		clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance) :
			clsPerson(firstName, lastName, email, phone) {

			_mode = mode;
			_accountNumber = accountNumber;
			_pinCode = pinCode;
			_accountBalance = accountBalance;
		}

		string AccountNumber() {
			return _accountNumber;
		}

		void setPinCode(string pinCode) {
			_pinCode = pinCode;
		}

		string getPinCode() {
			return _pinCode;
		}

		__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

		void setAccountBalance(float accountBalance) {
			_accountBalance = accountBalance;
		}

		float getAccountBalance() {
			return _accountBalance;
		}

		__declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;

		bool IsEmpty() {
			return (_mode == enMode::enEmptyMode);
		}

		/*void Print() {
			cout << "\nClient Card: ";
			cout << "\n____________________________\n";
			cout << "FirstName   : " << FirstName;
			cout << "\nLastName    : " << LastName;
			cout << "\nFullName    : " << FullName();
			cout << "\nEmail       : " << Email; 
			cout << "\nPhone       : " << Phone;
			cout << "\nAcc. Number : " << _accountNumber;
			cout << "\nPassword    : " << _pinCode;
			cout << "\nBalance     : " << _accountBalance;
			cout << "\n____________________________\n";
		}*/

		static clsBankClient Find(string accountNumber) {
			fstream file;
			file.open("Clients.txt", ios::in);

			if (file.is_open()) {
				string line;
				while (getline(file, line)) {
					clsBankClient client = _ConvertLineToClientObject(line);

					if (client.AccountNumber() == accountNumber) {
						file.close();
						return client;
					}
				}

				file.close();
			}
			return _GetEmptyClientObject();
		}

		static clsBankClient Find(string accountNumber, string pinCode) {
			clsBankClient client = Find(accountNumber);

			if (client.PinCode == pinCode) {
				return client;
			}

			return _GetEmptyClientObject();
		}

		static bool IsClientExist(string accountNumber) {
			clsBankClient client = Find(accountNumber);

			return !(client.IsEmpty());
		}

		static clsBankClient GetAddNewClientObject(string accNum) {
			return clsBankClient(enMode::enAddNewMode, "", "", "", "", accNum, "", 0);
		}

		void Delete() {
			vector<clsBankClient> vClients = _LoadClientsFromFile();

			for (clsBankClient& cl : vClients) {
				if (cl.AccountNumber() == _accountNumber) {
					cl = _GetEmptyClientObject();
					break;
				}
			}

			*this = _GetEmptyClientObject();
			_LoadClientsToFile(vClients);

		}

		enum enSaveResults { svSucceeded = 0, svFailedEmptyObject = 1 };

		enSaveResults Save() {

			switch (_mode)
			{
			case clsBankClient::enEmptyMode:

				if(IsEmpty())
					return enSaveResults::svFailedEmptyObject;
				break;

			case clsBankClient::enUpdateMode:

				_Update();
				return enSaveResults::svSucceeded;
				break;

			case clsBankClient::enAddNewMode:

				if(clsBankClient::IsClientExist(_accountNumber))
					return enSaveResults::svFailedEmptyObject;
				else {
					_AddNewClient();
					/*_mode = enMode::enUpdateMode;*/
					return enSaveResults::svSucceeded;
				}
				break;
			}
		}

		static vector<clsBankClient> GetClientsList() {
			return _LoadClientsFromFile();
		}

		static float GetTotalBalances() {
			vector<clsBankClient> vClients = _LoadClientsFromFile();
			float Total = 0;
			for (clsBankClient& cl : vClients) {
				Total += cl.AccountBalance;
			}

			return Total;
		}

		bool Deposit(float Amt) {
			if (Amt < 0) {
				return false;
			}
			else {
				_accountBalance += Amt;
				Save();
				return true;
			}
		}

		bool Withdraw(float Amt) {
			if (Amt > _accountBalance || Amt < 0) {
				return false;
			}
			else {
				_accountBalance -= Amt;
				Save();
			}
		}

		bool TransferTo(float amt, clsBankClient& receiver) {
			if (_accountBalance < amt || amt < 0) {
				return false;
			}

			Withdraw(amt);
			receiver.Deposit(amt);
			_SaveTransferLogs(receiver, amt);
			return true;
		}

		static vector< stTransLogRec> GetTransferLogs() {
			return _LoadTransferLogsFromFile();
		}

	};

