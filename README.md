# Bank System  
### C++ Final Project using Object-Oriented Programming (OOP)

## Project Overview
The **Bank System** is a console-based application developed in **C++** as a final project to demonstrate the use of **Object-Oriented Programming (OOP)** concepts.  
The system simulates basic banking operations such as managing clients, accounts, users, and transactions.

---

## Objectives
- Apply OOP principles in a real-world scenario
- Practice clean code and modular design
- Build a simple but functional banking system

---

## Technologies Used
- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **IDE:** Visual Studio

---

## OOP Concepts Used
- Classes & Objects  
- Encapsulation  
- Inheritance  
- Polymorphism  
- Abstraction  
- Static members  
- File handling

---

## System Features
- Create new bank accounts
- Managing client
- View client details  
- Deposit money  
- Withdraw money  
- Transfer money between accounts  
- Display account balance
- Create new users 
- Admin / user roles
- Lock / unlock users
- View user details
- Managing User
- Currencies Exchange
- Actions Logs

---

## Project Structure
Bank-System/
│
├── main.cpp
├── Core
    ├── clsBankClient.h
    ├── clsCurrency.h
    ├── clsPerson.h
    ├── clsUser.h
├── Screens
    ├── Currency
        ├── clsCurrenciesListScreen.h
        ├── clsCurrencyCalculator.h
        ├── clsCurrencyMainScreen.h
        ├── clsFindCurrencyScreen.h
        ├── clsUpdateCurrencyScreen.h
    ├── MainMenu
        ├── clsAddNewClient.h
        ├── clsClientListScreen.h
        ├── clsDeleteClient.h
        ├── clsFindClient.h
        ├── clsMainScreen.h
        ├── clsUpdateClient.h
    ├── Mng Users
        ├── clsAddUserScreen.h
        ├── clsDeleteUserScreen.h
        ├── clsFindUserScreen.h
        ├── clsLoginRegister.h
        ├── clsManageUsersScreen.h
        ├── clsUpdateUserScreen.h
        ├── clsUsersListScreen.h
    ├── Transaction
        ├── clsDepositScreen.h
        ├── clsTotalBalancesScreen.h
        ├── clsTransactionScreen.h
        ├── clsTransfer.h
        ├── clsTransferLogs.h
        ├── clsWithdrawScreen.h
    ├── clsScreen.h
├── Util
    ├── clsDate.h
    ├── clsInputValidate.h
    ├── clsPeriod.h
    ├── clsString.h
    ├── clsUtil.h
    ├── Global.h
├── clsLogin.h

---

## How to Run the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/Yasminemahmod/Bank-System.git
2. Open the project in your C++ IDE
3. Build and run main.cpp

---

## Sample Output
_________________________________________
                Main Screen
_________________________________________

User: User2
Date: 4/1/2026

==============================================
                Main Menu
==============================================
[1] Show Client List.
[2] Add New Client.
[3] Delete Client.
[4] Update Client Info.
[5] Find Client.
[6] Transaction.
[7] Manage Users.
[8] Login Register.
[9] Currency Exchange.
[10] Logout.
==============================================
Choose what do you want to do? [1 to 10]?

---

## Author
Name: Yasmine Mahmoud
Course: C++ / OOP (Mohammed Abu-Hadhoud Diploma)

---

## License
This project is developed for educational purposes.



