#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Bank Account Structure with properly sized character arrays
struct Bank {
    int acc_no;
    int day, month, year;
    int age;
    float amt;
    char pnumber[15];      // Corrected: was char pnumber;
    char idnum[20];        // Corrected: was char idnum;
    char name[20];         // Corrected: was char name;
    char fathname[20];     // Corrected: was char fathname;
    char address[50];      // Corrected: was char address;
};

// Function Declarations
void logo();
void login_menu();
void login();
void main_menu();
void edit_menu();
void transaction_menu();
void new_acc();
void view_acc();
void update_acc();
void delete_acc();
void search_acc();
void balance();
void deposit();
void withdraw();

Bank b, t;
const string DB_FILE = "bms.dat";
const string TEMP_FILE = "bms_temp.dat";

// Utility function to clear input buffer
void clear_input_buffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Utility function to clear screen
void clear_screen() {
    system("cls");
}

// Utility function to pause screen
void pause_screen() {
    cout << "\n\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Display system logo
void logo() {
    cout << "\n\t\t==================================\n"
         << "\t\t   BANK MANAGEMENT SYSTEM v2.0    \n"
         << "\t\t==================================\n";
}

// Login menu display and handling
void login_menu() {
    int choice;
    bool exit_loop = false;
    
    while (!exit_loop) {
        clear_screen();
        logo();
        cout << "\n\t\t************* LOGIN **************\n"
             << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|_________ 1) Login _____________|\n"
             << "\t\t|                                |\n"
             << "\t\t|_________ 2) Exit ______________|\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";
        cout << "\n\n\t\t\tYour choice: ";
        
        if (!(cin >> choice)) {
            clear_input_buffer();
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            pause_screen();
            continue;
        }
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                cout << "\n\n\t\t\tThank you for using BMS. Goodbye!\n\n";
                exit(0);
            default:
                cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
                pause_screen();
        }
    }
}

// Login function with corrected password handling
void login() {
    char pass[20];  // Corrected: was char pass;
    string password = "aleena";
    int attempts = 3;
    bool login_success = false;
    
    while (attempts > 0 && !login_success) {
        clear_screen();
        cout << "\n\n\t\t\tEnter the password to login: ";
        cin >> pass;
        clear_input_buffer();
        
        // Corrected: proper string comparison using strcmp
        if (strcmp(pass, password.c_str()) == 0) {
            login_success = true;
            main_menu();
        } else {
            attempts--;
            if (attempts > 0) {
                cout << "\n\n\t\t\tWrong password! " << attempts << " attempt(s) remaining.\n\n";
                pause_screen();
            } else {
                cout << "\n\n\t\t\tMaximum login attempts exceeded!\n\n";
                pause_screen();
                login_menu();
            }
        }
    }
}

// Main menu display and navigation
void main_menu() {
    int choice;
    bool exit_loop = false;
    
    while (!exit_loop) {
        clear_screen();
        logo();
        cout << "\n\t\t*********** MAIN MENU ************\n"
             << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|____ 1) Open New Account _______|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 2) View Accounts __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 3) Edit Accounts __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 4) Search Records _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 5) Transactions ___________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 6) Exit __________________ |\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";
        cout << "\n\n\t\t\tYour choice: ";
        
        if (!(cin >> choice)) {
            clear_input_buffer();
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            pause_screen();
            continue;
        }
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                new_acc();
                break;
            case 2:
                view_acc();
                cout << "\n\n";
                pause_screen();
                break;
            case 3:
                edit_menu();
                break;
            case 4:
                search_acc();
                break;
            case 5:
                transaction_menu();
                break;
            case 6:
                exit_loop = true;
                break;
            default:
                cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
                pause_screen();
        }
    }
}

// Edit menu display
void edit_menu() {
    int choice;
    bool exit_loop = false;
    
    while (!exit_loop) {
        clear_screen();
        logo();
        cout << "\n\t\t*********** EDIT MENU ************\n"
             << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|____ 1) Update Details _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 2) Delete Records _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 3) Main Menu ______________|\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";
        cout << "\n\n\t\t\tYour choice: ";
        
        if (!(cin >> choice)) {
            clear_input_buffer();
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            pause_screen();
            continue;
        }
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                update_acc();
                break;
            case 2:
                delete_acc();
                break;
            case 3:
                exit_loop = true;
                break;
            default:
                cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
                pause_screen();
        }
    }
}

// Transaction menu display
void transaction_menu() {
    int choice;
    bool exit_loop = false;
    
    while (!exit_loop) {
        clear_screen();
        logo();
        cout << "\n\t\t******* TRANSACTIONS MENU ********\n"
             << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|____ 1) Check Balance __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 2) Deposit Money __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 3) Withdraw Money _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ 4) Main Menu ______________|\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";
        cout << "\n\n\t\t\tYour choice: ";
        
        if (!(cin >> choice)) {
            clear_input_buffer();
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            pause_screen();
            continue;
        }
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                balance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                exit_loop = true;
                break;
            default:
                cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
                pause_screen();
        }
    }
}

// Create new account with comprehensive input validation
void new_acc() {
    int acn;
    bool account_exists = false;
    
    while (true) {
        clear_screen();
        logo();
        cout << "\n\t\t*** Enter New Customer Details ***\n\n";
        cout << "\n\t\tAccount Number: ";
        
        if (!(cin >> acn)) {
            clear_input_buffer();
            cout << "\n\t\tInvalid input! Please enter a valid account number.\n\n";
            pause_screen();
            continue;
        }
        clear_input_buffer();
        
        // Check if account already exists
        ifstream check_file(DB_FILE, ios::binary);
        if (check_file.is_open()) {
            while (check_file.read((char*)&b, sizeof(b))) {
                if (acn == b.acc_no) {
                    account_exists = true;
                    break;
                }
            }
            check_file.close();
        }
        
        if (account_exists) {
            cout << "\n\t\tAccount no. already in use!\n\n";
            pause_screen();
            account_exists = false;
        } else {
            break;
        }
    }
    
    b.acc_no = acn;
    
    cout << "\n\t\tName: ";
    cin.getline(b.name, 20);
    
    cout << "\n\t\tFather's Name: ";
    cin.getline(b.fathname, 20);
    
    cout << "\n\t\tDate of Birth (dd-mm-yyyy): ";
    scanf("%d-%d-%d", &b.day, &b.month, &b.year);
    clear_input_buffer();
    
    cout << "\n\t\tAge: ";
    while (!(cin >> b.age) || b.age < 0 || b.age > 120) {
        clear_input_buffer();
        cout << "\n\t\tInvalid age! Please enter a valid age: ";
    }
    clear_input_buffer();
    
    cout << "\n\t\tPhone Number: ";
    cin.getline(b.pnumber, 15);
    
    cout << "\n\t\tID Card Number: ";
    cin.getline(b.idnum, 20);
    
    cout << "\n\t\tAddress: ";
    cin.getline(b.address, 50);
    
    cout << "\n\t\tEnter the amount to deposit (Rs.): ";
    while (!(cin >> b.amt) || b.amt < 0) {
        clear_input_buffer();
        cout << "\n\t\tInvalid amount! Please enter a valid amount: ";
    }
    clear_input_buffer();
    
    // Write account to file
    ofstream out_file(DB_FILE, ios::binary | ios::app);
    if (out_file.is_open()) {
        out_file.write((char*)&b, sizeof(b));
        out_file.close();
        cout << "\n\n\t\tAccount Created Successfully!!!\n\n";
    } else {
        cout << "\n\t\tError! Cannot open the file!!\n\n";
    }
    pause_screen();
}

// View all accounts with sorted display
void view_acc() {
    clear_screen();
    logo();
    
    Bank temp;
    vector<Bank> arr;
    ifstream in_file(DB_FILE, ios::binary);
    
    if (!in_file.is_open()) {
        cout << "\n\t\tError! Cannot open the File!!\n\n";
        pause_screen();
        return;
    }
    
    while (in_file.read((char*)&b, sizeof(b))) {
        arr.push_back(b);
    }
    in_file.close();
    
    if (arr.empty()) {
        cout << "\n\t\tNo accounts found in the system.\n\n";
        return;
    }
    
    // Bubble Sort by account number
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j].acc_no > arr[j + 1].acc_no) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Display header
    for (int w = 1; w <= 130; w++) cout << "=";
    cout << "\n";
    cout << left << setw(10) << "Acc No" 
         << setw(15) << "Name" 
         << setw(15) << "Father Name" 
         << setw(15) << "DOB" 
         << setw(8) << "Age" 
         << setw(15) << "Phone" 
         << setw(15) << "ID Card"
         << setw(20) << "Address"
         << setw(12) << "Balance\n";
    for (int w = 1; w <= 130; w++) cout << "=";
    cout << "\n";
    
    // Display account data
    for (int i = 0; i < arr.size(); i++) {
        cout << left << setw(10) << arr[i].acc_no
             << setw(15) << arr[i].name
             << setw(15) << arr[i].fathname
             << setw(15) << (string(to_string(arr[i].day) + "-" + to_string(arr[i].month) + "-" + to_string(arr[i].year)))
             << setw(8) << arr[i].age
             << setw(15) << arr[i].pnumber
             << setw(15) << arr[i].idnum
             << setw(20) << arr[i].address
             << fixed << setprecision(2) << arr[i].amt << "\n";
    }
    
    for (int w = 1; w <= 130; w++) cout << "=";
    cout << "\n";
}

// Update account details
void update_acc() {
    clear_screen();
    logo();
    view_acc();
    
    int acn;
    int flag = 0;
    
    cout << "\n\nEnter Account Number to Update: ";
    if (!(cin >> acn)) {
        clear_input_buffer();
        cout << "\n\t\tInvalid input!\n\n";
        pause_screen();
        return;
    }
    clear_input_buffer();
    
    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);
    
    if (!in_file.is_open()) {
        cout << "\n\t\tError! Cannot open the file!!\n\n";
        pause_screen();
        return;
    }
    
    while (in_file.read((char*)&b, sizeof(b))) {
        if (b.acc_no == acn) {
            flag = 1;
            clear_screen();
            logo();
            cout << "\n*** Previously Stored Details ***\n\n";
            cout << "Account No: " << b.acc_no 
                 << "\nName: " << b.name 
                 << "\nFather Name: " << b.fathname
                 << "\nDOB: " << b.day << "-" << b.month << "-" << b.year 
                 << "\nAge: " << b.age
                 << "\nPhone: " << b.pnumber 
                 << "\nID: " << b.idnum 
                 << "\nAddress: " << b.address
                 << "\nBalance: Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
            
            cout << "\n*** Enter New Details ***\n";
            b.acc_no = acn;
            
            cout << "\nName: ";
            cin.getline(b.name, 20);
            
            cout << "Father's Name: ";
            cin.getline(b.fathname, 20);
            
            cout << "Date of Birth (dd-mm-yyyy): ";
            scanf("%d-%d-%d", &b.day, &b.month, &b.year);
            clear_input_buffer();
            
            cout << "Age: ";
            while (!(cin >> b.age) || b.age < 0 || b.age > 120) {
                clear_input_buffer();
                cout << "Invalid age! Please enter a valid age: ";
            }
            clear_input_buffer();
            
            cout << "Phone Number: ";
            cin.getline(b.pnumber, 15);
            
            cout << "ID Number: ";
            cin.getline(b.idnum, 20);
            
            cout << "Address: ";
            cin.getline(b.address, 50);
            
            cout << "Enter the amount: Rs. ";
            while (!(cin >> b.amt) || b.amt < 0) {
                clear_input_buffer();
                cout << "Invalid amount! Please enter a valid amount: ";
            }
            clear_input_buffer();
            
            out_file.write((char*)&b, sizeof(b));
            cout << "\n\nRecord Updated Successfully!\n\n";
        } else {
            out_file.write((char*)&b, sizeof(b));
        }
    }
    
    in_file.close();
    out_file.close();
    
    if (flag == 0) {
        cout << "\n\t\tNo Record Found!!!\n\n";
    }
    
    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

// Delete account
void delete_acc() {
    clear_screen();
    logo();
    view_acc();
    
    int acn;
    int flag = 0;
    
    cout << "\n\nEnter Account Number to Delete: ";
    if (!(cin >> acn)) {
        clear_input_buffer();
        cout << "\n\t\tInvalid input!\n\n";
        pause_screen();
        return;
    }
    clear_input_buffer();
    
    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);
    
    if (!in_file.is_open()) {
        cout << "\n\t\tError! Cannot open the file!!\n\n";
        pause_screen();
        return;
    }
    
    while (in_file.read((char*)&b, sizeof(b))) {
        if (b.acc_no != acn) {
            out_file.write((char*)&b, sizeof(b));
        } else {
            flag = 1;
        }
    }
    
    in_file.close();
    out_file.close();
    
    if (flag == 1) {
        cout << "\n\tDeletion Successful!!\n\n";
    } else {
        cout << "\n\n\t\tNo Such Record Found!!!\n\n";
    }
    
    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

// Search accounts by name
void search_acc() {
    clear_screen();
    logo();
    
    char key[20];  // Corrected: was char key; which could only store one character
    int flag = 0;
    
    cout << "Enter Name to Search Record: ";
    cin.getline(key, 20);
    
    ifstream in_file(DB_FILE, ios::binary);
    if (!in_file.is_open()) {
        cout << "\n\t\tError! Cannot open the file!!\n\n";
        pause_screen();
        return;
    }
    
    while (in_file.read((char*)&b, sizeof(b))) {
        if (strcmp(key, b.name) == 0) {
            flag = 1;
            cout << "\n\tAccount Number   :   " << b.acc_no
                 << "\n\tName             :   " << b.name
                 << "\n\tFather Name      :   " << b.fathname
                 << "\n\tDate of Birth    :   " << b.day << "-" << b.month << "-" << b.year
                 << "\n\tAge              :   " << b.age
                 << "\n\tPhone Number     :   " << b.pnumber
                 << "\n\tID Card Number   :   " << b.idnum
                 << "\n\tAddress          :   " << b.address
                 << "\n\tBalance          :   Rs. " << fixed << setprecision(2) << b.amt << "\n";
        }
    }
    
    if (flag == 0) {
        cout << "\n\n\t\tNo Such Record Found!!!\n\n";
    }
    
    in_file.close();
    pause_screen();
}

// Check account balance
void balance() {
    clear_screen();
    logo();
    
    int acn;
    int flag = 0;
    
    cout << "Enter Account Number: ";
    if (!(cin >> acn)) {
        clear_input_buffer();
        cout << "\n\t\tInvalid input!\n\n";
        pause_screen();
        return;
    }
    clear_input_buffer();
    
    ifstream in_file(DB_FILE, ios::binary);
    if (!in_file.is_open()) {
        cout << "\n\t\tError! Cannot open the file!!\n\n";
        pause_screen();
        return;
    }
    
    while (in_file.read((char*)&b, sizeof(b))) {
        if (b.acc_no == acn) {
            flag = 1;
            clear_screen();
            logo();
            cout << "*** Account Details ***\n\n";
            cout << "Account No  : " << b.acc_no 
                 << "\nName        : " << b.name
                 << "\nFather Name : " << b.fathname 
                 << "\nDOB         : " << b.day << "-" << b.month << "-" << b.year 
                 << "\nAge         : " << b.age
                 << "\nPhone       : " << b.pnumber 
                 << "\nID Card     : " << b.idnum
                 << "\nAddress     : " << b.address 
                 << "\nBalance     : Rs. " << fixed << setprecision(2) << b.amt << "\n";
        }
    }
    
    if (flag == 0) {
        cout << "\n\t\tNo Record Found!!!\n\n";
    }
    
    in_file.close();
    pause_screen();
}

// Deposit money into account
void deposit() {
    clear_screen();
    logo();
    
    int acn;
    int flag = 0;
    float deposit_amount;
    
    cout << "Enter Account Number: ";
    if (!(cin >> acn)) {
        clear_input_buffer();
        cout << "\n\t\tInvalid input!\n\n";
        pause_screen();
        return;
    }
    clear_input_buffer();
    
    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);
    
    if (!in_file.is_open()) {
        cout << "\n\t\tError! Cannot open the file!!\n\n";
        pause_screen();
        return;
    }
    
    while (in_file.read((char*)&b, sizeof(b))) {
        if (b.acc_no == acn) {
            flag = 1;
            clear_screen();
            logo();
            cout << "*** Account Details ***\n\n";
            cout << "Account No  : " << b.acc_no 
                 << "\nName        : " << b.name
                 << "\nBalance     : Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
            
            cout << "Enter the amount you want to deposit: Rs. ";
            if (!(cin >> deposit_amount) || deposit_amount <= 0) {
                clear_input_buffer();
                cout << "\n\n\t\tInvalid amount!\n\n";
                out_file.write((char*)&b, sizeof(b));
                in_file.close();
                out_file.close();
                remove(DB_FILE.c_str());
                rename(TEMP_FILE.c_str(), DB_FILE.c_str());
                pause_screen();
                return;
            }
            clear_input_buffer();
            
            b.amt += deposit_amount;
            out_file.write((char*)&b, sizeof(b));
            cout << "\n\nDeposited Successfully!\n";
            cout << "New Balance: Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
        } else {
            out_file.write((char*)&b, sizeof(b));
        }
    }
    
    if (flag == 0) {
        cout << "\n\t\tNo Record Found!!!\n\n";
    }
    
    in_file.close();
    out_file.close();
    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

// Withdraw money from account
void withdraw() {
    clear_screen();
    logo();
    
    int acn;
    int flag = 0;
    float withdraw_amount;
    const float WITHDRAW_LIMIT = 50000.0;
    
    cout << "Enter Account Number: ";
    if (!(cin >> acn)) {
        clear_input_buffer();
        cout << "\n\t\tInvalid input!\n\n";
        pause_screen();
        return;
    }
    clear_input_buffer();
    
    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);
    
    if (!in_file.is_open()) {
        cout << "\n\t\tError! Cannot open the file!!\n\n";
        pause_screen();
        return;
    }
    
    while (in_file.read((char*)&b, sizeof(b))) {
        if (b.acc_no == acn) {
            bool valid_withdrawal = false;
            
            while (!valid_withdrawal) {
                clear_screen();
                logo();
                cout << "*** Account Details ***\n\n";
                cout << "Account No  : " << b.acc_no 
                     << "\nName        : " << b.name
                     << "\nBalance     : Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
                
                cout << "Enter the amount you want to withdraw: Rs. ";
                if (!(cin >> withdraw_amount)) {
                    clear_input_buffer();
                    cout << "\n\nInvalid input!\n\n";
                    continue;
                }
                clear_input_buffer();
                
                if (withdraw_amount <= 0) {
                    cout << "\n\nAmount must be greater than zero!\n\n";
                    pause_screen();
                } else if (withdraw_amount > WITHDRAW_LIMIT) {
                    cout << "\n\nWithdraw Limit of Rs. 50,000 Exceeded!\n\n";
                    pause_screen();
                } else if (withdraw_amount > b.amt) {
                    cout << "\n\nInsufficient Balance!\n\n";
                    pause_screen();
                } else {
                    b.amt -= withdraw_amount;
                    out_file.write((char*)&b, sizeof(b));
                    flag = 1;
                    valid_withdrawal = true;
                    cout << "\n\nWithdrawn Successfully!\n";
                    cout << "Remaining Balance: Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
                }
            }
        } else {
            out_file.write((char*)&b, sizeof(b));
        }
    }
    
    if (flag == 0) {
        cout << "\n\t\tNo Record Found!!!\n\n";
    }
    
    in_file.close();
    out_file.close();
    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

// Main program entry point
int main() {
    login_menu();
    return 0;
}