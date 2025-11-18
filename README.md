🏦 Bank Management System (C++)

A simple, efficient, and user-friendly console-based banking system built in C++.
This project demonstrates secure account handling, transaction management, and persistent binary file storage — all through a colorful and intuitive command-line interface.

✨ Core Features
🔐 Secure Access

Password-protected login (password)

Incorrect input handling

Strong validation for all string & numeric fields

👤 Account Management

Create customer accounts

View all accounts in a formatted table

Update customer details

Delete accounts

Search by name or account number

💰 Transaction Handling

Deposit (validated input)

Withdraw (limit: Rs. 50,000)

Balance inquiry

Auto-save after every transaction

💾 Reliable Data Storage

Data saved in bms.dat (binary file)

Update safety using bms_temp.dat

Crash-safe file handling

Fast binary I/O operations

🧰 Technologies Used
🔹 Programming Language

C++ (C++17 Standard)

🔹 Libraries & Headers

<iostream> — Input/Output handling

<fstream> — File handling (binary read/write)

<cstring> — String operations

<iomanip> — Output formatting

<cctype> — Character checks

<vector> & <algorithm> — Sorting & data structures

<limits> — Safe input buffer clearing

<windows.h> — Console colors, Sleep(), and UI enhancement

🔹 Concepts & Techniques

Struct-based data modelling

Binary file handling

Menu-driven console UI

Input validation loops

Sorting using Bubble Sort

Color-coded UI using Windows API

Error handling & safe file updates

🛠 System Requirements

Windows OS

C++ compiler (G++, MSVC, or Clang)

Any IDE (VS Code, Dev-C++, Code::Blocks)

Command Prompt / Terminal

▶️ How to Compile & Run
Using G++
g++ -o bms project.cpp
bms.exe

Using Visual Studio Code

Install the C/C++ extension

Open folder

Build using Ctrl + Shift + B

Run using:

./bms.exe

📂 Project Structure
├── project.cpp        # Main application
├── bms.dat            # Binary database file
├── bms_temp.dat       # Temporary safe-update file
└── README.md          # Documentation

🌟 Highlights

Fully validated inputs (no crashing on invalid data)

Clean UI with colors and ASCII branding

Smooth UX with loading animation

Easy to maintain and extend

👥 Team Members
🟦 ALEENA ISHAQ

Lead Developer
BSEF24A005

🟪 ABISHA CHAUDHARY

Collaborator / Developer
BSEF24M007

📜 License

This project is for academic and educational purposes.
Modification is allowed with proper credit.
