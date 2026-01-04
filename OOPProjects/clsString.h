#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{
private:
	string _value;

	enum charCase { ALL = 0, CAPITAL = 1 , SMALL = 2 };

	static char LetterToUpper(char ch) {
		int diff = int('a') - int('A');
		if (ch >= int('a') && ch <= int('z')) {
			return char(ch - diff);
		}
	}

	static char LetterToLower(char ch) {
		int diff = int('a') - int('A');
		if (ch >= int('A') && ch <= int('Z')) {
			return char(ch + diff);
		}
	}

	static char InvertCharCase(char ch) {
		return (isupper(ch) ? tolower(ch) : toupper(ch));
	}

	static bool IsVowel(char ch) {
		char vowels[] = { 'a', 'o','u','e','i' };
		for (int i = 0; i < 5; i++) {
			if (tolower(ch) == tolower(vowels[i])) return true;
		}
		return false;
	}


public:
	clsString() {
		_value = "";
	}

	clsString(string value) {
		_value = value;
	}

	void setValue(string value) {
		_value = value;
	}

	string getValue() {
		return _value;
	}



	__declspec(property(get = getValue, put = setValue)) string value;


	// Methods
	static short Length(string s) {
		return s.length();
	}

	short Length() {
		return _value.length();
	}

	static int CountWords(string s) {
		string word, delim = " ";
		int count = 0, pos = 0;

		while ((pos = s.find(delim)) != string::npos) {
			word = s.substr(0, pos);
			if (word != "") count++;
			s.erase(0, pos + delim.length());
		}

		if (s != "") count++;

		return count;
	}

	int CountWords() {
		return CountWords(_value);
	}

	static string UpperFirstLetter(string s) {
		bool IsFirstLetter = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && IsFirstLetter) {
				s[i] = LetterToUpper(s[i]);
			}
			IsFirstLetter = (s[i] == ' ' ? true : false);
		}
		return s;
	}

	void UpperFirstLetter() {
		_value = UpperFirstLetter(_value);
	}

	static string LowerFirstLetter(string s) {
		bool IsFirstLetter = true;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && IsFirstLetter) {
				s[i] = LetterToLower(s[i]);
			}

			IsFirstLetter = (s[i] == ' ' ? true : false);
		}

		return s;
	}

	void LowerFirstLetter() {
		_value = LowerFirstLetter(_value);
	}


	static string UpperString(string s) {
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ') {
				s[i] = LetterToUpper(s[i]);
			}
		}
		return s;
	}

	void UpperString() {
		_value = UpperString(_value);
	}

	static string LowerString(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				s[i] = LetterToLower(s[i]);
			}
		}
		return s;
	}

	void LowerString() {
		_value = LowerString(_value);
	}

	static string InvertStringLetters(string s) {
		for (int i = 0; i < s.length(); i++) {
			s[i] = InvertCharCase(s[i]);
		}
		return s;
	}

	void InvertStringLetters() {
		_value = InvertStringLetters(_value);
	}


	static short countLetters(string s, charCase chCase = charCase::ALL) {
		short count = 0;
		if (chCase == charCase::ALL) return s.length();

		for (int i = 0; i < s.length(); i++) {
			if (chCase == charCase::SMALL && islower(s[i])) {
				count++;
			}
			if (chCase == charCase::CAPITAL && isupper(s[i])) {
				count++;
			}
		}

		return count;
	}

	short countLetters() {
		return countLetters(_value, charCase::ALL);
	}

	static int CountCapitalLetters(string s) {
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (isupper(s[i])) count++;
		}
		return count;
	}

	int CountCapitalLetters() {
		return CountCapitalLetters(_value);
	}

	static int CountSmallLetters(string s) {
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (islower(s[i])) count++;
		}
		return count;
	}

	int CountSmallLetters() {
		return CountSmallLetters(_value);
	}

	static short CountSpecificLetter(string s, char ch, bool match = true) {
		short count = 0;

		for (int i = 0; i < s.length(); i++) {
			if (match && s[i] == ch) count++;
			if (!match && tolower(s[i]) == tolower(ch)) count++;
		}
		return count;
	}

	short CountSpecificLetter(char ch, bool match = true) {
		return CountSpecificLetter(_value, ch , match);
	}

	static short CountVowels(string s) {
		short count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (IsVowel(s[i])) count++;
		}
		return count;
	}

	short CountVowels() {
		return CountVowels(_value);
	}

	static void PrintAllVowels(string s) {
		cout << "\nVowels in string are: ";
		for (int i = 0; i < s.length(); i++) {
			if (IsVowel(s[i])) {
				cout << s[i] << "   ";
			}
		}
	}

	void PrintAllVowels() {
		return PrintAllVowels(_value);
	}




	/*static void Split(string s) {
		string word, delim = " ";
		short pos = 0;

		while ((pos = s.find(delim)) != string::npos) {
			word = s.substr(0, pos);
			if (word != "") {
				cout << word << endl;
			}
			s.erase(0, pos + delim.length());
		}

		if (s != "") {
			cout << s << endl;
		}
	}*/

	//void Split() {
	//	return Split(_value);
	//}

	static vector<string> Split(string s, string delim = "#//#") {
		vector<string> vStr;
		string word;
		short pos = 0;

		while ((pos = s.find(delim)) != string::npos) {
			word = s.substr(0, pos);

			if (word != "") {
				vStr.push_back(word);
			}

			s.erase(0, pos + delim.length());

		}

		if (s != "") {
			vStr.push_back(s);
		}

		return vStr;
	}

	vector<string> Split(string delim = "#//#") {
		return Split(_value, delim);
	}

	static string TrimLeft(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				return s.substr(i);
			}
		}
	}

	string TrimLeft() {
		return TrimLeft(_value);
	}

	static string TrimRight(string s) {
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				return s.substr(0, i + 1);
			}
		}
	}

	string TrimRight() {
		return TrimRight(_value);
	}

	static string Trim(string s) {
		return TrimLeft(TrimRight(s));
	}

	string Trim() {
		return Trim(_value);
	}

	static string JoinString(vector<string> vStr , string delim) {
		string s = "";
		for (string& word : vStr) {
			s += word + delim;
		}

		return s.substr(0, s.length() - delim.length());
	}

	static string JoinString(string arr[], int len, string delim) {
		string s = "";

		for (int i = 0; i < len; i++) {
			s += arr[i] + delim;
		}

		return s.substr(0, s.length() - delim.length());
	}

	static string ReverseString(string s) {
		string delim = " ";
		vector<string> vStr = Split(s, delim);
		s = "";
		for (int i = vStr.size() - 1; i >= 0; i--) {
			s += vStr[i] + delim;
		}
		return s.substr(0, s.length() - 1);
	}

	void ReverseString() {
		_value = ReverseString(_value);
	}

	static string ReverseStringIter(string s) {
		string delim = " ";
		vector<string> vStr = Split(s, delim);
		vector<string>::iterator iter = vStr.end();
		s = "";

		while (iter != vStr.begin()) {
			s += *iter + delim;
			--iter;
		}
		return s.substr(0, s.length() - 1);
	}

	void ReverseStringIter() {
		_value = ReverseStringIter(_value);
	}

	static string ReplaceWordInString(string s, string original, string newWord, bool match = true) {
		vector<string> vStr = Split(s, " ");

		for (string& word : vStr) {
			if (match && word == original) {
				word = newWord;
			}
			else if (!match && LowerString(word) == LowerString(original)) {
				word = newWord;
			}
		}

		return JoinString(vStr, " ");
	}

	static string ReplaceWordInStringWithReplace(string s, string original, string newWord) {
		int pos = 0;

		while ((pos = s.find(original)) != string::npos) {
			s.replace(pos, original.length(), newWord);

		}

		return s;
	}

	static string RemovePunc(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (ispunct(s[i])) {
				s.replace(i, 1, "");
			}
		}

		return s;
	}

	void RemovePunc() {
		_value = RemovePunc(_value);
	}

};

