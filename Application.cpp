#pragma once

#include <iostream>
#include "Login&Register.cpp"
#include "AccountUser.cpp"
#include "DataInputValidation.cpp"
using namespace std;

enum
{                           // ID IS 6 NUMBERS WHICH MEAN AUTOMACTICALLY GENERATED AFTER CREATING NEW ACOUNT
    CREATE_NEW_ACCOUNT = 1, // 1. CREATE NEW ACCOUNT
    DEPOSIT_CASH,           // 2. DEPOSIT CASH
    WITHDRAW_CASH,          // 3. WITHDRAW CASH
    SEARCH_ACCOUNT,         // 4. SEARCH ACCOUNT NUMBER
    VIEW_ALL_ACCOUNTS,      // 5. VIEW ALL ACCOUNTS
    CLOSE_ACCOUNT,          // 6. CLOSE ACCOUNT
    EDIT_ACCOUNT_DETAILS,   // 7. EDIT ACCOUNT DETAILS
    SORT_ACCOUNT,           // 8. SORT ACCOUNT
    LOG_OUT,                // 9. LOG OUT

};

class Application
{
private:
    ////////////////////////////////////////////////// Login & Register //////////////////////////////////////////////////
    int getChoiceLoginAndRegister()
    {
        int choiceLoginAndRegister;
        cout << "         Enter Your Choice 1-3 : ";
        cin >> choiceLoginAndRegister;
        return choiceLoginAndRegister;
    }

    void authenticationMenu()
    {
        cout << "\n X=======================================X " << endl;
        cout << " |      USER BANK MANAGEMENT SYSTEM      | " << endl;
        cout << " X=======================================X " << endl;
        cout << " |  1. LOGIN  | 2. REGISTER  |  3. EXIT  | " << endl;
        cout << " X=======================================X " << endl;
    }
    ////////////////////////////////////////////////// Login & Register //////////////////////////////////////////////////

    int getChoice() // DONE
    {
        int choice;

        cout << "         Enter Your Choice 1-10 : ";
        cin >> choice;
        return choice;
    }
    void BankMenu()
    {
        cout << "\n X=======================================X " << endl;
        cout << " |                                       | " << endl;
        cout << " |       USER BANK MANAGEMENT MENU       | " << endl;
        cout << " |                                       | " << endl;
        cout << " X=======================================X " << endl;
        cout << " |         1. CREATE NEW ACCOUNT         | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         2. DEPOSIT CASH               | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         3. WITHDRAW CASH              | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         4. SEARCH ACCOUNT             | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         5. VIEW ALL ACCOUNTS          | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         6. CLOSE ACCOUNT              | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         7. EDIT ACCOUNT DETAILS       | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         8. SORT ACCOUNT               | " << endl; ///
        cout << " X=======================================X " << endl;
        cout << " |         9. LOG OUT                    | " << endl; ///
        cout << " X=======================================X " << endl;
    }

    //////////////////////////////////////////////////////////////////////////////////
public:
    void run()
    {
        int choice = 0;
        Login log;

        do
        {
            authenticationMenu();
            choice = getChoiceLoginAndRegister();
            switch (choice)
            {
            case 1:
                if (log.userLogin() == true)
                {
                    system("cls");
                    bankManagement();
                }
                else
                {
                    cout << " |    Login failed. Please try again.    | " << endl;
                    cout << " X=======================================X " << endl << endl;
                }
                break;
            case 2:
                log.userRegister();
                break;
            case 3:

                cout << " X=======================================X " << endl;
                cout << " |          3. EXIT [BYE BYE!!]          | " << endl;
                cout << " X=======================================X " << endl;
                exit(1);

            default:
                cout << " X=======================================X " << endl;
                cout << " |   Invalid choice. Please try again.   | " << endl;
                cout << " X=======================================X " << endl
                     << endl;
                break;
            }
        } while (choice != 0);
    }

    void bankManagement()
    {
        DataInputValidation inputValidator;
        int choice = 0;
        int num;

        do
        {
            BankMenu();
            
            choice = getChoice();

            switch (choice)
            {

            case CREATE_NEW_ACCOUNT:
            {
                try
                {
                    write_account();
                }
                catch (const BadInputException& ex)
                {
                    cerr << "Error: Bad input detected while creating account. Please try again." << endl;
                }
                break;
            }

            case DEPOSIT_CASH:
                try
                {
                    cout << " X=======================================X " << endl;
                    cout << "        Enter Account Number : ";
                    num = inputValidator.input_Accountnum();
                    deposit_withdraw(num, 1);
                }
                catch (const BadInputException& ex)
                {
                    cerr << "Error: Bad input detected while depositing cash. Please try again." << endl;
                }
                break;

            case WITHDRAW_CASH:
                try
                {
                    cout << " X=======================================X " << endl;
                    cout << "        Enter Account Number : ";
                    num = inputValidator.input_Accountnum();
                    deposit_withdraw(num, 2);
                }
                catch (const BadInputException& ex)
                {
                    cerr << "Error: Bad input detected while withdrawing cash. Please try again." << endl;
                }
                break;

            case SEARCH_ACCOUNT:
                cout << " X=======================================X " << endl;
                cout << "        Enter Account Number : ";
                cin >> num;
                display_sp(num);
                break;

            case VIEW_ALL_ACCOUNTS:
                display_all();
                break;

            case CLOSE_ACCOUNT:
                cout << " X=======================================X " << endl;
                cout << "        Enter Account Number : ";
                cin >> num;
                delete_account(num);
                break;

            case EDIT_ACCOUNT_DETAILS:
                cout << " X=======================================X " << endl;
                cout << "        Enter Account Number : ";
                cin >> num;
                rename_account(num);
                break;

            case SORT_ACCOUNT:
                sort_account_numbers();
                break;

            case LOG_OUT:
                cout << " X=======================================X " << endl;
                cout << " |     BACK TO LOGIN & REGISTER MENU     |" << endl;
                cout << " X=======================================X " << endl << endl;
                break;

            default:
            
                cout << " X=======================================X " << endl;
                cout << " |      Invalid Choice, Try again        |" << endl;
                cout << " X=======================================X " << endl;
                break;
            }

        } while (choice != 9);
    }
};
