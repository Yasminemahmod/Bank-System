#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "clsPeriod.h";

using namespace std;
class clsUtil
{

public:
	enum enCharType {
		SamllLetter = 1, CapitalLetter = 2, Digits = 3, MixChar = 4, SpecialChar = 5
	};

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int from, int to) {
		int randNum = rand() % (to - from + 1) + from;
		return randNum;
	}

	static char GetRandomCharacter(enCharType type) {
		if (type == enCharType::MixChar) {
			type = (enCharType)RandomNumber(1, 3);
		}

		if (type == enCharType::CapitalLetter) {
			return (char)RandomNumber(65, 90);
		}
		else if (type == enCharType::SamllLetter) {
			return (char)RandomNumber(97, 122);
		}
		else if (type == enCharType::SpecialChar) {
			return (char)RandomNumber(21, 47);
		}
	}

	static string GenerateWord(enCharType type, short len) {
		string word = "";

		for (short i = 0; i < len; i++) {
			word += GetRandomCharacter(type);
		}
		return word;
	}

	static string GenerateKey(enCharType type) {
		string key = "";

		for (short i = 0; i < 4; i++) {
			key += GenerateWord(type, 4) + "-";
		}
		return key.substr(0, key.length() - 1);
	}

	static void GenerateKeys(short count, enCharType type) {
		for (short i = 1; i <= count; i++) {
			cout << "key [" << i << "] : " << GenerateKey(type) << "\n";
		}
	}

	static void Swap(int& num1, int& num2) {
		int temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void Swap(double& num1, double& num2) {
		double temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void Swap(bool& num1, bool& num2) {
		bool temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void Swap(char& num1, char& num2) {
		char temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	static void Swap(string& str1, string& str2) {
		string temp;
		temp = str1;
		str1 = str2;
		str2 = temp;
	}

	static void Swap(clsDate& date1, clsDate& date2) {
		clsDate::SwapDates(date1, date2);
	}

/*
	//static void ShuffleArray(int arr[100], short len) {
	//	int arr2[100], ind[100], i = 0, num;
	//	bool exist = false;
	//	while (i != len) {
	//		num = RandomNumber(0, 4);
	//		for (int j = 0; j < len; j++) {
	//			if (ind[j] == num) {
	//				exist = true;
	//				break;
	//			}
	//			else exist = false;
	//		}

	//		if (!exist) {
	//			ind[i] = num;
	//			arr2[i] = arr[num];
	//			i++;
	//		}
	//	}

	//	for (short i = 0; i < len; i++) {
	//		arr[i] = arr2[i];
	//	}
	//}*/

	static void ShuffleArray(int arr[100], short len) {
		Swap(arr[RandomNumber(1, len) - 1], arr[RandomNumber(1, len) - 1]);
	}

	static void ShuffleArray(string arr[100], short len) {
		Swap(arr[RandomNumber(1, len) - 1], arr[RandomNumber(1, len) - 1]);
	}

	static void FillArrayWithRandomNumber(int arr[100], int len, int start, int end) {
		for (int i = 0; i < len; i++) {
			arr[i] = RandomNumber(start, end);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int len, enCharType type, int wordLen) {
		for (int i = 0; i < len; i++) {
			arr[i] = GenerateWord(type, wordLen);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int len, enCharType type) {
		for (int i = 0; i < len; i++) {
			arr[i] = GenerateKey(type);
		}
	}

	static string Tabs(int count) {
		string tabs = "";
		for (int i = 0; i < count; i++) {
			tabs += "\t";
		}
		return tabs;
	}

	static string EncryptText(string text, short encKey = 2) {
		for (int i = 0; i < text.length(); i++) {
			text[i] = (char)((int)text[i] + encKey);
		}

		return text;
	}

	static string DecryptText(string text, short encKey = 2) {
		for (int i = 0; i < text.length(); i++) {
			text[i] = (char)((int)text[i] - encKey);
		}

		return text;
	}


	static string ConvertNumberToString(long long num) {
		string numStr = "";
		int ind = 0;
		string numbers[] = { "", "One", "Two", "Three",  "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twilve",
				"Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		string second[] = { "","", "Twenty", "Thirty","Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty" };
		string orders[] = { "hundreds" , "Thousands", "Millions", "Billions" };


		//if (num >= 100-000-000-000 && num <= 990000000000) {
		//	//ind = num / 100000000000;
		//	numStr += numbers[num / 100000000000] + " " + orders[0] + " ";
		//	num = num % 100000000000;
		//}
		if (num >= 1000000 && num < 100000000) {
			if (num >= 20000000000 && num < 100000000000) {
				ind = num / 10000000000;
				numStr += second[ind] + " " + orders[3] + " ";
				num = num % 10000000000;
			}
			if (num >= 1 - 000 - 000 - 000 && num < 20 - 000 - 000 - 000) {
				ind = num / 1000000000;
				numStr += numbers[ind] + " " + orders[3] + " ";
				num = num % 1000000000;
			}
			numStr += orders[3] + " ";
		}

		if (num >= 100-000-000 && num < 1-000-000-000) {
			ind = num / 100000000;
			numStr += numbers[ind] + " " + orders[0] + " ";
			num = num % 100000000;
		}
		if (num >= 1000000 && num < 100000000) {
			if (num >= 20000000 && num < 100000000) {
				ind = num / 10000000;
				numStr += second[ind] + " " + orders[2] + " ";
				num = num % 10000000;
			}
			if (num >= 1000000 && num < 20000000) {
				ind = num / 1000000;
				numStr += numbers[ind] + " " + orders[2] + " ";
				num = num % 1000000;
			}
			numStr += orders[2] + " ";
		}


		if (num >= 100000 && num < 1000000) {
			numStr += numbers[num / 100000] + " " + orders[0] + " ";
			num = num % 100000;
		}
		if (num >= 1000 && num < 100000) {
			if (num >= 20000 && num < 100000) {
				numStr += second[num / 10000] + " ";
				num = num % 10000;
			}
			if (num >= 1000 && num < 20000) {
				numStr += numbers[num / 1000] + " ";
				num = num % 1000;
			}
			numStr += orders[1] + " ";
		}


		if (num >= 100 && num < 1000) {
			numStr += numbers[num / 100] + " " + orders[0] + " ";
			num = num % 100;
		}
		if (num >= 20 && num < 100) {
			numStr += second[num / 10] + " ";
			num = num % 10;
		}
		if (num > 0 && num < 20) {
			numStr += numbers[num];
		}

		return numStr;
	}
};

