#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"

class clsCurrency
{
private:
	enum enMode {EmptyMode = 0, UpdateMode = 1};
	enMode _mode;

	string _country;
	string _currencyCode;
	string _currencyName;
	float _Rate;

	static clsCurrency _GetEmptyCurrency() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static clsCurrency _GetCurrencyObject(string line, string sep = "#//#") {
		vector<string> vCurr = clsString::Split(line, sep);

		return clsCurrency(enMode::UpdateMode, vCurr[0], vCurr[1], vCurr[2], stof(vCurr[3]));
	}

	static vector<clsCurrency> _LoadCurrenciesInfoFromFile() {
		fstream file;
		file.open("Currencies.txt", ios::in);
		vector<clsCurrency> vCurr;

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				vCurr.push_back(_GetCurrencyObject(line));
			}
			file.close();
		}

		return vCurr;
	}

	static string _ConvertCurrencyToLine(clsCurrency curr, string sep = "#//#") {
		return (curr.Country() + sep + curr.CurrencyCode() + sep + curr.CurrencyName() + sep + to_string(curr.Rate()));
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> curr) {
		fstream file;
		file.open("Currencies.txt", ios::out);

		if (file.is_open()) {
			string line;
			for (clsCurrency& c : curr) {
				line = _ConvertCurrencyToLine(c);
				file << line << endl;
			}

			file.close();
		}

	}

	void _Update() {

		vector<clsCurrency> curr = _LoadCurrenciesInfoFromFile();

		for (clsCurrency& c : curr) {
			if (c.CurrencyCode() == CurrencyCode()) {
				c = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(curr);
	}

	static clsCurrency _FindByCountry(string country) {
		country = clsString::LowerString(clsString::RemovePunc(country));

		fstream file;
		file.open("Currencies.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsCurrency curr = _GetCurrencyObject(line);
				
				if (clsString::LowerString(clsString::RemovePunc(curr.Country())) == country) {

					file.close();
					return curr;

				}
			}
			file.close();
		}


		return _GetEmptyCurrency();
	}

	static clsCurrency _FindByCode(string code) {
		code = clsString::UpperString(code);

		fstream file;
		file.open("Currencies.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsCurrency curr = _GetCurrencyObject(line);
				if (curr.CurrencyCode() == code) {

					file.close();
					return curr;

				}
			}
			file.close();
		}

		return _GetEmptyCurrency();
	}

	static bool _IsCurrencyExistByCountry(string country) {
		clsCurrency curr = _FindByCountry(country);

		return (!curr.IsEmpty());
	}

	static bool _IsCurrencyExistByCode(string code) {
		clsCurrency curr = _FindByCode(code);

		return (!curr.IsEmpty());
	}



public:
	clsCurrency(enMode mode,string country, string currencyCode, string currencyName, float Rate) {
		_mode = mode;
		_country = country;
		_currencyCode = currencyCode;
		_currencyName = currencyName;
		_Rate = Rate;
	}

	bool IsEmpty() {
		return (_mode == enMode::EmptyMode);
	}

	string Country() {
		return _country;
	}

	string CurrencyCode() {
		return _currencyCode;
	}

	string CurrencyName() {
		return _currencyName;
	}

	void UpdateRate(float newRate) {
		_Rate = newRate;
		_Update();
	}

	float Rate() {
		return _Rate;
	}

	//__declspec(property(get = getCurrencyRate, put = setCurrencyRate)) float CurrRate;

	static clsCurrency Find(string findStr) {
		string type;

		if (!_FindByCode(findStr).IsEmpty()) {
			return _FindByCode(findStr);
		}
		else if (!_FindByCountry(findStr).IsEmpty()) {
			return _FindByCountry(findStr);
		}
		else {
			return _GetEmptyCurrency();
		}
	}

	static bool IsCurrencyExist(string co) {
		return (!_FindByCode(co).IsEmpty()? true : (!_FindByCountry(co).IsEmpty() ? true : false) );
	}

	static vector<clsCurrency> GetCurrenciesList() {
		return _LoadCurrenciesInfoFromFile();
	}

	float ConvertCurrToUSD(float amt) {
		return (amt / Rate());
	}

	float ConvertToOtherCurrency(clsCurrency curr2, float amt) {
		amt = ConvertCurrToUSD(amt);

		if (curr2.CurrencyCode() == "USD") {
			return amt;
		}

		return (amt * Rate());
	}
};

