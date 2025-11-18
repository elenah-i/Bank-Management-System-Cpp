#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits>
#include <windows.h>

using namespace std;
struct Bank
{
    int acc_no;
    int day, month, year;
    int age;
    float amt;
    char pnumber[15];
    char idnum[20];
    char name[20];
    char fathname[20];
    char address[50];
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
void loading();
void footer();

Bank b, t;
const string DB_FILE = "bms.dat";
const string TEMP_FILE = "bms_temp.dat";

// Utility function to clear input buffer
void clear_input_buffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clear_screen()
{
    system("cls");
}
// ....... TO SET COLORS
void setColor(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void pause_screen()
{
    setColor(14);
    cout << "\n\nPress Enter to continue...";
    setColor(7);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void logo()
{
    setColor(11);
    cout << "\t                      *%@%*                    \n"
            "\t                  +#@@#***#@@#+                \n"
            "\t               *%@@@+#@%=%@#+@@@%*             \n"
            "\t           +*@@@@@@*#@#*%%#@%*@@@@@@*+         \n"
            "\t             %%%%%%*%@%%%**@%*%%%%%%           \n"
            "\t              *%%%##+%%+=+%%=##%%%*            \n"
            "\t               #%#==##*****##==#%#             \n"
            "\t               %@%==#@%+=+@@#==%@#             \n"
            "\t               %@%==#@%+=+@@#==%@#             \n"
            "\t               %@%==#@%+=+@@#==%@#             \n"
            "\t               %@%==#@%+=+@@#==%@#             \n"
            "\t               #%#==*%#+=+#%*==#%#             \n"
            "\t              +###++*##*=*##*++###+            \n"
            "\t             %%%%%%%%%%%%%%%%%%%%%%%           \n"
            "\t           *#########################*         \n";

    setColor(14);
    cout << "\n\t\t==================================\n"
         << "\t\t       BANK MANAGEMENT SYSTEM        \n"
         << "\t\t==================================\n\n";
    setColor(7);
}
// ........LOADING ANIMATION
void loading()
{
    setColor(14);
    cout << "\nProcessing";
    setColor(7);
    for (int i = 0; i < 3; i++)
    {
        Sleep(300);
        cout << ".";
    }
    cout << "\n\n";
}

void footer()
{
    setColor(11);
    cout << "\n";
    cout << "\t==================================================\n";
    setColor(14);
    cout << "\t              THANK YOU FOR USING\n";
    cout << "\t            THE BANK MANAGEMENT SYSTEM\n";
    cout << "\t     © ABC Bank | All Rights Reserved (2025)\n";
    setColor(11);
    cout << "\t==================================================\n";
    setColor(7);
}

void login_menu()
{
    int choice;
    bool exit_loop = false;

    while (!exit_loop)
    {
        clear_screen();
        logo();

        setColor(11);
        cout << "\n\t\t************* LOGIN **************\n"
             << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|_________ ";
        setColor(14);
        cout << "1) Login";
        setColor(11);
        cout << " _____________|\n"
             << "\t\t|                                |\n"
             << "\t\t|_________ ";
        setColor(14);
        cout << "2) Exit";
        setColor(11);
        cout << " ______________|\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";
        setColor(14);
        cout << "\n\n\t\t\tYour choice: ";
        setColor(7);

        if (!(cin >> choice))
        {
            clear_input_buffer();
            setColor(12); // Red
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            setColor(7);
            pause_screen();
            continue;
        }
        clear_input_buffer();

        switch (choice)
        {
        case 1:
            setColor(10); // Green
            cout << "\n\n\t\tLogging in...\n\n";
            setColor(7);
            loading();
            login();
            break;

        case 2:
            footer();
            exit(0);

        default:
            setColor(12); // Red
            cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
            setColor(7);
            pause_screen();
        }
    }
}

void login()
{
    char pass[20];
    string password = "password";
    int attempts = 3;
    bool login_success = false;

    while (attempts > 0 && !login_success)
    {
        clear_screen();
        setColor(14);
        cout << "\n\n\t\t\tEnter the password to login: ";
        setColor(7);
        cin >> pass;
        clear_input_buffer();

        if (strcmp(pass, password.c_str()) == 0)
        {
            setColor(10); // Green
            cout << "\n\n\t\t\tLogin Successful!\n\n";
            setColor(7);
            loading();
            login_success = true;
            main_menu();
        }
        else
        {
            attempts--;
            setColor(12); // Red
            if (attempts > 0)
            {
                cout << "\n\n\t\t\tWrong password! " << attempts
                     << " attempt(s) remaining.\n\n";
                setColor(7);
                pause_screen();
            }
            else
            {
                cout << "\n\n\t\t\tMaximum login attempts exceeded!\n\n";
                setColor(7);
                pause_screen();
                login_menu();
            }
        }
    }
}

void main_menu()
{
    int choice;
    bool exit_loop = false;

    while (!exit_loop)
    {
        clear_screen();
        logo();

        setColor(14);
        cout << "\n\t\t*********** MAIN MENU ************\n";
        setColor(11);
        cout << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "1) Open New Account";
        setColor(11);
        cout << " _______|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "2) View Accounts";
        setColor(11);
        cout << " __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "3) Edit Accounts";
        setColor(11);
        cout << " __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "4) Search Records";
        setColor(11);
        cout << " _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "5) Transactions";
        setColor(11);
        cout << " ___________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "6) Exit";
        setColor(11);
        cout << " __________________ |\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";

        setColor(14);
        cout << "\n\n\t\t\tYour choice: ";
        setColor(7);

        if (!(cin >> choice))
        {
            clear_input_buffer();
            setColor(12);
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            setColor(7);
            pause_screen();
            continue;
        }
        clear_input_buffer();

        switch (choice)
        {
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
            setColor(12);
            cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
            setColor(7);
            pause_screen();
        }
    }
    footer();
    exit(0);
}

void edit_menu()
{
    int choice;
    bool exit_loop = false;

    while (!exit_loop)
    {
        clear_screen();
        logo();

        setColor(14);
        cout << "\n\t\t*********** EDIT MENU ************\n";
        setColor(11);
        cout << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "1) Update Details";
        setColor(11);
        cout << " _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "2) Delete Records";
        setColor(11);
        cout << " _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "3) Main Menu";
        setColor(11);
        cout << " ______________|\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";

        setColor(14);
        cout << "\n\n\t\t\tYour choice: ";
        setColor(7);

        if (!(cin >> choice))
        {
            clear_input_buffer();
            setColor(12);
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            setColor(7);
            pause_screen();
            continue;
        }
        clear_input_buffer();

        switch (choice)
        {
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
            setColor(12);
            cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
            setColor(7);
            pause_screen();
        }
    }
}

void transaction_menu()
{
    int choice;
    bool exit_loop = false;

    while (!exit_loop)
    {
        clear_screen();
        logo();

        setColor(14);
        cout << "\n\t\t******* TRANSACTIONS MENU ********\n";
        setColor(11);
        cout << "\t\t ________________________________ \n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "1) Check Balance";
        setColor(11);
        cout << " __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "2) Deposit Money";
        setColor(11);
        cout << " __________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "3) Withdraw Money";
        setColor(11);
        cout << " _________|\n"
             << "\t\t|                                |\n"
             << "\t\t|____ ";
        setColor(14);
        cout << "4) Main Menu";
        setColor(11);
        cout << " ______________|\n"
             << "\t\t|                                |\n"
             << "\t\t|________________________________|\n";

        setColor(14);
        cout << "\n\n\t\t\tYour choice: ";
        setColor(7);

        if (!(cin >> choice))
        {
            clear_input_buffer();
            setColor(12);
            cout << "\n\n\t\t\tInvalid input! Please enter a number.\n\n";
            setColor(7);
            pause_screen();
            continue;
        }
        clear_input_buffer();

        switch (choice)
        {
        case 1:
            balance();
            break;
        case 2:
            loading();
            deposit();
            break;
        case 3:
            loading();
            withdraw();
            break;
        case 4:
            exit_loop = true;
            break;
        default:
            setColor(12);
            cout << "\n\n\t\t\tWrong Choice! Try Again.\n\n";
            setColor(7);
            pause_screen();
        }
    }
}

void new_acc()
{
    int acn;
    bool account_exists = false;

    while (true)
    {
        clear_screen();
        logo();

        setColor(14);
        cout << "\n\t\t*** Enter New Customer Details ***\n\n";
        setColor(7);


        setColor(14);
        cout << "\n\t\tAccount Number: ";        
        setColor(7);
        
        if (!(cin >> acn))
        {
            clear_input_buffer();
            setColor(12);
            cout << "\n\t\tInvalid input! Please enter a valid account number.\n\n";
            setColor(7);
            pause_screen();
            continue;
        }
        clear_input_buffer();

        // Check if account already exists
        ifstream check_file(DB_FILE, ios::binary);
        if (check_file.is_open())
        {
            while (check_file.read((char *)&b, sizeof(b)))
            {
                if (acn == b.acc_no)
                {
                    account_exists = true;
                    break;
                }
            }
            check_file.close();
        }

        if (account_exists)
        {
            setColor(12);
            cout << "\n\t\tAccount no. already in use!\n\n";
            setColor(7);
            pause_screen();
            account_exists = false;
        }
        else
        {
            break;
        }
    }

    b.acc_no = acn;

    setColor(14);
    cout << "\n\t\tName: ";
    setColor(7);
    cin.getline(b.name, 20);

    setColor(14);
    cout << "\n\t\tFather's Name: ";
    setColor(7);
    cin.getline(b.fathname, 20);

    setColor(14);
    cout << "\n\t\tDate of Birth (dd-mm-yyyy): ";
    setColor(7);
    scanf("%d-%d-%d", &b.day, &b.month, &b.year);
    clear_input_buffer();

    setColor(14);
    cout << "\n\t\tAge: ";
    setColor(7);
    while (!(cin >> b.age) || b.age < 0 || b.age > 120)
    {
        clear_input_buffer();
        setColor(12);
        cout << "\n\t\tInvalid age! Please enter a valid age: ";
        setColor(7);
    }
    clear_input_buffer();

    setColor(14);
    cout << "\n\t\tPhone Number: ";
    setColor(7);
    cin.getline(b.pnumber, 15);

    setColor(14);
    cout << "\n\t\tID Card Number: ";
    setColor(7);
    cin.getline(b.idnum, 20);

    setColor(14);
    cout << "\n\t\tAddress: ";
    setColor(7);
    cin.getline(b.address, 50);

    setColor(14);
    cout << "\n\t\tEnter the amount to deposit (Rs.): ";
    setColor(7);
    while (!(cin >> b.amt) || b.amt < 0)
    {
        clear_input_buffer();
        setColor(12);
        cout << "\n\t\tInvalid amount! Please enter a valid amount: ";
        setColor(7);
    }
    clear_input_buffer();

    // Write account to file
    ofstream out_file(DB_FILE, ios::binary | ios::app);
    if (out_file.is_open())
    {
        out_file.write((char *)&b, sizeof(b));
        out_file.close();
        setColor(10);
        cout << "\n\n\t\tAccount Created Successfully!!!\n\n";
        setColor(7);
    }
    else
    {
        setColor(12);
        cout << "\n\t\tError! Cannot open the file!!\n\n";
        setColor(7);
    }
    pause_screen();
}

void view_acc()
{
    clear_screen();
    logo();

    setColor(14);
    cout << "\n\n================== VIEW ACCOUNTS =================\n\n";
    setColor(7);

    Bank temp;
    vector<Bank> arr;
    ifstream in_file(DB_FILE, ios::binary);

    if (!in_file.is_open())
    {
        setColor(12);
        cout << "\n\t\tError! Cannot open the File!!\n\n";
        setColor(7);
        pause_screen();
        return;
    }

    while (in_file.read((char *)&b, sizeof(b)))
        arr.push_back(b);
    in_file.close();

    if (arr.empty())
    {
        setColor(12);
        cout << "\n\t\tNo accounts found in the system.\n\n";
        setColor(7);

        pause_screen();
        return;
    }

    // Bubble Sort by account number
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j].acc_no > arr[j + 1].acc_no)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display header
    setColor(11);
    for (int w = 1; w <= 130; w++)
        cout << "=";
    cout << "\n";
    setColor(14);
    cout << left << setw(10) << "Acc No"
         << setw(15) << "Name"
         << setw(15) << "Father Name"
         << setw(15) << "DOB"
         << setw(8) << "Age"
         << setw(15) << "Phone"
         << setw(15) << "ID Card"
         << setw(20) << "Address"
         << setw(12) << "Balance\n";
    setColor(11);
    for (int w = 1; w <= 130; w++)
        cout << "=";
    cout << "\n";
    setColor(7);

    // Display account data
    for (int i = 0; i < arr.size(); i++)
    {
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

    setColor(11);
    for (int w = 1; w <= 130; w++)
        cout << "=";
    cout << "\n";
    setColor(7);
}

// Update account details
void update_acc()
{
    clear_screen();
    logo();

    setColor(14); cout << "\n\n================== UPDATE ACCOUNT =================\n\n"; setColor(7);
    view_acc();

    int acn;
    int flag = 0;

    setColor(14); cout << "\n\nEnter Account Number to Update: "; setColor(7);
    if (!(cin >> acn))
    {
        clear_input_buffer();
        setColor(12); cout << "\n\t\tInvalid input!\n\n"; setColor(7);
        pause_screen();
        return;
    }
    clear_input_buffer();

    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);

    if (!in_file.is_open())
    {
        setColor(12); cout << "\n\t\tError! Cannot open the file!!\n\n"; setColor(7);
        pause_screen();
        return;
    }

    while (in_file.read((char *)&b, sizeof(b)))
    {
        if (b.acc_no == acn)
        {
            flag = 1;
            clear_screen();
            logo();
            setColor(11); cout << "\n*** Previously Stored Details ***\n\n"; setColor(7);
            setColor(14);
            cout << "Account No: " << b.acc_no
                 << "\nName: " << b.name
                 << "\nFather Name: " << b.fathname
                 << "\nDOB: " << b.day << "-" << b.month << "-" << b.year
                 << "\nAge: " << b.age
                 << "\nPhone: " << b.pnumber
                 << "\nID: " << b.idnum
                 << "\nAddress: " << b.address
                 << "\nBalance: Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
            setColor(7);

            setColor(11); cout << "\n*** Enter New Details ***\n"; setColor(7);
            b.acc_no = acn;

            setColor(14); cout << "\nName: "; setColor(7); cin.getline(b.name, 20);
            setColor(14); cout << "Father's Name: "; setColor(7); cin.getline(b.fathname, 20);
            setColor(14); cout << "Date of Birth (dd-mm-yyyy): "; setColor(7); scanf("%d-%d-%d", &b.day, &b.month, &b.year);
            clear_input_buffer();

            setColor(14); cout << "Age: "; setColor(7);
            while (!(cin >> b.age) || b.age < 0 || b.age > 120)
            {
                clear_input_buffer();
                setColor(12); cout << "Invalid age! Please enter a valid age: "; setColor(7);
            }
            clear_input_buffer();

            setColor(14); cout << "Phone Number: "; setColor(7); cin.getline(b.pnumber, 15);
            setColor(14); cout << "ID Number: "; setColor(7); cin.getline(b.idnum, 20);
            setColor(14); cout << "Address: "; setColor(7); cin.getline(b.address, 50);

            setColor(14); cout << "Enter the amount: Rs. "; setColor(7);
            while (!(cin >> b.amt) || b.amt < 0)
            {
                clear_input_buffer();
                setColor(12); cout << "Invalid amount! Please enter a valid amount: "; setColor(7);
            }
            clear_input_buffer();

            out_file.write((char *)&b, sizeof(b));
            setColor(10); cout << "\n\nRecord Updated Successfully!\n\n"; setColor(7);
        }
        else
        {
            out_file.write((char *)&b, sizeof(b));
        }
    }

    in_file.close();
    out_file.close();

    if (flag == 0)
    {
        setColor(12); cout << "\n\t\tNo Record Found!!!\n\n"; setColor(7);
    }

    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

void delete_acc()
{
    loading();
    clear_screen();
    logo();

    setColor(14); cout << "\n\n================== DELETE ACCOUNT =================\n\n"; setColor(7);
    view_acc();

    int acn;
    int flag = 0;

    setColor(14); cout << "\n\nEnter Account Number to Delete: "; setColor(7);
    if (!(cin >> acn))
    {
        clear_input_buffer();
        setColor(12); cout << "\n\t\tInvalid input!\n\n"; setColor(7);
        pause_screen();
        return;
    }
    clear_input_buffer();

    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);

    if (!in_file.is_open())
    {
        setColor(12); cout << "\n\t\tError! Cannot open the file!!\n\n"; setColor(7);
        pause_screen();
        return;
    }

    while (in_file.read((char *)&b, sizeof(b)))
    {
        if (b.acc_no != acn)
            out_file.write((char *)&b, sizeof(b));
        else
            flag = 1;
    }

    in_file.close();
    out_file.close();

    if (flag == 1)
    {
        setColor(10); cout << "\n\tDeletion Successful!!\n\n"; setColor(7);
    }
    else
    {
        setColor(12); cout << "\n\n\t\tNo Such Record Found!!!\n\n"; setColor(7);
    }

    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

void search_acc()
{
    clear_screen();
    logo();

    setColor(14); cout << "\n\n================== SEARCH RECORD =================\n\n"; setColor(7);
    char key[20];
    int flag = 0;

    setColor(14); cout << "Enter Name to Search Record: "; setColor(7);
    cin.getline(key, 20);

    ifstream in_file(DB_FILE, ios::binary);
    if (!in_file.is_open())
    {
        setColor(12); cout << "\n\t\tError! Cannot open the file!!\n\n"; setColor(7);
        pause_screen();
        return;
    }

    while (in_file.read((char *)&b, sizeof(b)))
    {
        if (strcmp(key, b.name) == 0)
        {
            flag = 1;
            setColor(11);
            cout << "\n\tAccount Number   :   " << b.acc_no
                 << "\n\tName             :   " << b.name
                 << "\n\tFather Name      :   " << b.fathname
                 << "\n\tDate of Birth    :   " << b.day << "-" << b.month << "-" << b.year
                 << "\n\tAge              :   " << b.age
                 << "\n\tPhone Number     :   " << b.pnumber
                 << "\n\tID Card Number   :   " << b.idnum
                 << "\n\tAddress          :   " << b.address
                 << "\n\tBalance          :   Rs. " << fixed << setprecision(2) << b.amt << "\n";
            setColor(7);
        }
    }

    if (flag == 0)
        { setColor(12); cout << "\n\n\t\tNo Such Record Found!!!\n\n"; setColor(7); }

    in_file.close();
    pause_screen();
}

void balance()
{
    clear_screen();
    logo();

    setColor(14); cout << "\n\n================== CHECK BALANCE =================\n\n"; setColor(7);
    int acn;
    int flag = 0;

    setColor(14); cout << "Enter Account Number: "; setColor(7);
    if (!(cin >> acn))
    {
        clear_input_buffer();
        setColor(12); cout << "\n\t\tInvalid input!\n\n"; setColor(7);
        pause_screen();
        return;
    }
    clear_input_buffer();

    ifstream in_file(DB_FILE, ios::binary);
    if (!in_file.is_open())
    {
        setColor(12); cout << "\n\t\tError! Cannot open the file!!\n\n"; setColor(7);
        pause_screen();
        return;
    }

    while (in_file.read((char *)&b, sizeof(b)))
    {
        if (b.acc_no == acn)
        {
            flag = 1;
            clear_screen();
            logo();
            setColor(11); cout << "*** Account Details ***\n\n"; setColor(7);
            setColor(14);
            cout << "Account No  : " << b.acc_no
                 << "\nName        : " << b.name
                 << "\nFather Name : " << b.fathname
                 << "\nDOB         : " << b.day << "-" << b.month << "-" << b.year
                 << "\nAge         : " << b.age
                 << "\nPhone       : " << b.pnumber
                 << "\nID Card     : " << b.idnum
                 << "\nAddress     : " << b.address
                 << "\nBalance     : Rs. " << fixed << setprecision(2) << b.amt << "\n";
            setColor(7);
        }
    }

    if (flag == 0)
        { setColor(12); cout << "\n\t\tNo Record Found!!!\n\n"; setColor(7); }

    in_file.close();
    pause_screen();
}

void deposit()
{
    clear_screen();
    logo();

    setColor(14); cout << "\n\n================== DEPOSIT MONEY ==================\n\n"; setColor(7);

    int acn;
    int flag = 0;
    float deposit_amount;

    setColor(14); cout << "Enter Account Number: "; setColor(7);
    if (!(cin >> acn))
    {
        clear_input_buffer();
        setColor(12); cout << "\n\t\tInvalid input!\n\n"; setColor(7);
        pause_screen();
        return;
    }
    clear_input_buffer();

    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);

    if (!in_file.is_open())
    {
        setColor(12); cout << "\n\t\tError! Cannot open the file!!\n\n"; setColor(7);
        pause_screen();
        return;
    }

    while (in_file.read((char *)&b, sizeof(b)))
    {
        if (b.acc_no == acn)
        {
            flag = 1;
            clear_screen();
            logo();

            setColor(11); cout << "*** Account Details ***\n\n"; setColor(7);
            setColor(14);
            cout << "Account No  : " << b.acc_no
                 << "\nName        : " << b.name
                 << "\nBalance     : Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
            setColor(7);

            setColor(14); cout << "Enter the amount you want to deposit: Rs. "; setColor(7);
            if (!(cin >> deposit_amount) || deposit_amount <= 0)
            {
                clear_input_buffer();
                setColor(12); cout << "\n\n\t\tInvalid amount!\n\n"; setColor(7);
                out_file.write((char *)&b, sizeof(b));
                in_file.close();
                out_file.close();
                remove(DB_FILE.c_str());
                rename(TEMP_FILE.c_str(), DB_FILE.c_str());
                pause_screen();
                return;
            }
            clear_input_buffer();

            b.amt += deposit_amount;
            out_file.write((char *)&b, sizeof(b));
            setColor(10); cout << "\n\nDeposited Successfully!\n"; 
            cout << "New Balance: Rs. " << fixed << setprecision(2) << b.amt << "\n\n"; setColor(7);
        }
        else
        {
            out_file.write((char *)&b, sizeof(b));
        }
    }

    if (flag == 0)
        { setColor(12); cout << "\n\t\tNo Record Found!!!\n\n"; setColor(7); }

    in_file.close();
    out_file.close();
    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

void withdraw()
{
    clear_screen();
    logo();

    setColor(14); cout << "\n\n================== WITHDRAW MONEY =================\n\n"; setColor(7);

    int acn;
    int flag = 0;
    float withdraw_amount;
    const float WITHDRAW_LIMIT = 50000.0;

    setColor(14); cout << "Enter Account Number: "; setColor(7);
    if (!(cin >> acn))
    {
        clear_input_buffer();
        setColor(12); cout << "\n\t\tInvalid input!\n\n"; setColor(7);
        pause_screen();
        return;
    }
    clear_input_buffer();

    ifstream in_file(DB_FILE, ios::binary);
    ofstream out_file(TEMP_FILE, ios::binary);

    if (!in_file.is_open())
    {
        setColor(12); cout << "\n\t\tError! Cannot open the file!!\n\n"; setColor(7);
        pause_screen();
        return;
    }

    while (in_file.read((char *)&b, sizeof(b)))
    {
        if (b.acc_no == acn)
        {
            bool valid_withdrawal = false;
            while (!valid_withdrawal)
            {
                clear_screen();
                logo();

                setColor(11); cout << "*** Account Details ***\n\n"; setColor(7);
                setColor(14);
                cout << "Account No  : " << b.acc_no
                     << "\nName        : " << b.name
                     << "\nBalance     : Rs. " << fixed << setprecision(2) << b.amt << "\n\n";
                setColor(7);

                setColor(14); cout << "Enter the amount you want to withdraw: Rs. "; setColor(7);
                if (!(cin >> withdraw_amount))
                {
                    clear_input_buffer();
                    setColor(12); cout << "\n\nInvalid input!\n\n"; setColor(7);
                    continue;
                }
                clear_input_buffer();

                if (withdraw_amount <= 0)
                {
                    setColor(12); cout << "\n\nAmount must be greater than zero!\n\n"; setColor(7);
                    pause_screen();
                }
                else if (withdraw_amount > WITHDRAW_LIMIT)
                {
                    setColor(12); cout << "\n\nWithdraw Limit of Rs. 50,000 Exceeded!\n\n"; setColor(7);
                    pause_screen();
                }
                else if (withdraw_amount > b.amt)
                {
                    setColor(12); cout << "\n\nInsufficient Balance!\n\n"; setColor(7);
                    pause_screen();
                }
                else
                {
                    b.amt -= withdraw_amount;
                    out_file.write((char *)&b, sizeof(b));
                    flag = 1;
                    valid_withdrawal = true;
                    setColor(10); cout << "\n\nWithdrawn Successfully!\n"; 
                    cout << "Remaining Balance: Rs. " << fixed << setprecision(2) << b.amt << "\n\n"; setColor(7);
                }
            }
        }
        else
        {
            out_file.write((char *)&b, sizeof(b));
        }
    }

    if (flag == 0)
        { setColor(12); cout << "\n\t\tNo Record Found!!!\n\n"; setColor(7); }

    in_file.close();
    out_file.close();
    remove(DB_FILE.c_str());
    rename(TEMP_FILE.c_str(), DB_FILE.c_str());
    pause_screen();
}

int main()
{
    login_menu();

    return 0;
}
