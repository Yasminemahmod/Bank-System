#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
//#include <limits>


/*class clsInputValidate {
public:
    static bool IsNumberBetween(short num, short from, short to) {
        return (num >= from && num <= to);
    }

    static bool IsNumberBetween(int num, int from, int to) {
        return (num >= from && num <= to);
    }

    static bool IsNumberBetween(float num, float from, float to) {
        return (num >= from && num <= to);
    }

    static bool IsNumberBetween(double num, double from, double to) {
        return (num >= from && num <= to);
    }

    static bool IsDateBetween(clsDate date, clsDate from, clsDate to) {
        return clsPeriod::IsDateWithinPeriod(clsPeriod(from, to), date);
    }

    static bool IsValidDate(clsDate date) {
        return clsDate::IsValidDate(date);
    }

    static int ReadIntNumber(string msg, string errorMsg = "Invalid Number") {
        int num;
        cout << msg;
        cin >> num;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMsg;
            cin >> num;
        }

        return num;
    }

    static int ReadIntNumberBetween(int from, int to, string msg) {
        int num = ReadIntNumber(msg, "Invalid Number");
        while (!IsNumberBetween(num, from, to)) {
            num = ReadIntNumber(msg, "Invalid Number");
        }
        return num;
    }

    static short ReadShortNumber(string msg, string errorMsg = "Invalid Number") {
        short num;
        cout << msg;
        cin >> num;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMsg;
            cin >> num;
        }

        return num;
    }

    static short ReadShortNumberBetween(short from, short to, string msg) {
        short num = ReadShortNumber(msg, "Invalid Number");
        while (!IsNumberBetween(num, from, to)) {
            num = ReadShortNumber(msg, "Invalid Number");
        }
        return num;
    }

    static float ReadFloatNumber(string msg, string errorMsg = "Invalid Number") {
        float num;
        cout << msg;
        cin >> num;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMsg;
            cin >> num;
        }

        return num;
    }

    static float ReadFloatNumberBetween(float from, float to, string msg) {
        float num = ReadFloatNumber(msg, "Invalid Number");
        while (!IsNumberBetween(num, from, to)) {
            num = ReadFloatNumber(msg, "Invalid Number");
        }
        return num;
    }

    static double ReadDblNumber(string msg, string errorMsg = "Invalid Number") {
        double num;
        cout << msg;
        cin >> num;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMsg;
            cin >> num;
        }

        return num;
    }

    static double ReadDblNumberBetween(double from, double to, string msg) {
        double num = ReadDblNumber(msg, "Invalid Number");
        while (!IsNumberBetween(num, from, to)) {
            num = ReadDblNumber(msg, "Invalid Number");
        }
        return num;
    }

    static string ReadString(string msg) {
        string str;
        cout << msg;
        getline(cin >> ws, str); // Ignore whitespace
        return str;
    }

};*/


class clsInputValidate {
public:
    template <typename T>
    static bool IsNumberBetween(T num, T from, T to) {
        return (num >= from && num <= to);
    }

    template <typename T>
    static T ReadNumber(string msg, string errorMsg = "Invalid") {
        T num;
        cout << msg;
        cin >> num;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMsg;
            cin >> num;
        }

        return num;
    }

    template <typename T>
    static T ReadNumberBetween(T from, T to, string msg) {
        T num = ReadNumber<T>(msg, "Invalid Number");
        while (!IsNumberBetween<T>(num, from, to)) {
            num = ReadNumber<T>(msg, "Invalid Number");
        }
        return num;
    }

    static string ReadString(string msg) {
        string str;
        cout << msg;
        getline(cin >> ws, str); // Ignore whitespace
        return str;
    }

    static bool IsDateBetween(clsDate date, clsDate from, clsDate to) {
        return clsPeriod::IsDateWithinPeriod(clsPeriod(from, to), date);
    }

    static bool IsValidDate(clsDate date) {
        return clsDate::IsValidDate(date);
    }
};
