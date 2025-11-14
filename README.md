# Bank Management System (C++)

A console-based Bank Management System written in C++ that allows users to create accounts, perform transactions, and manage customer records. The system includes secure login and saves all data permanently using binary files.

---

## ⭐ Features

### 🔐 Security
- Password-protected login (`password`)
- Validations for account number and sufficient balance

### 👤 Account Management
- Create new bank accounts  
- View all accounts  
- Update customer information  
- Delete accounts  
- Search by name or account number  

### 💰 Transaction Management
- Deposit money  
- Withdraw money (Max limit: Rs. 50,000)  
- Check account balance  
- Automatic data saving after every update  

### 💾 Data Storage
- Permanent binary storage in `bms.txt`
- Auto backup created in `bms1.txt`
- Fast and efficient binary file handling

---

## 📁 Project Structure

Bank-Management-System-Cpp/
├── main.cpp # Source code file
├── README.md # Documentation
├── bms.txt # Main database (auto-generated)
└── bms1.txt # Backup file (auto-generated)

yaml


---

## 🛠 Requirements
- Windows OS  
- C++ Compiler (G++, MSVC, or Clang)  
- Visual Studio Code / Code::Blocks / Any C++ IDE  
- Command Prompt / Terminal  

---

## ▶️ How to Compile and Run (Windows)

### **Using G++**
```bash
g++ -o bms main.cpp
bms.exe
Using MSVC
bash

cl main.cpp
main.exe
📘 How to Use
1. Run the program
2. Enter password: password
3. Choose an option from the main menu:
Option	Action
1	Open New Account
2	View All Accounts
3	Edit Account
4	Search Records
5	Transactions
6	Exit

Required Information for Creating a New Account
Account Number

Full Name

Father’s Name

Date of Birth

Age

Phone Number

CNIC / ID Number

Address

Initial Deposit

📄 Database Format
Each record stored inside bms.txt contains:


Account Number
Name
Father’s Name
Date of Birth
Age
Phone Number
CNIC / ID Card Number
Address
Current Balance

---


👥 TEAM MEMBERS

🟦 ALEENA ISHAQ
Lead Developer
🟪 ABISHA CHOUDHARY
Collaborator / Developer



