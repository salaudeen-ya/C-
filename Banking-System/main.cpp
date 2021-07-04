#include "banking.cpp"

int main(){

    Bank bank;
    Account account;

    int choice;
    string fname, lname;
    long actNum;
    double balance;
    double amount;

    cout << "\n\t******** Welcome to Our Banking System ***********" << endl;
    do {
        cout << "\n\t Select one option below";
        cout << "\n\t 1: Open an Account";
        cout << "\n\t 2: Balance Enquiry";
        cout << "\n\t 3: Deposit Money";
        cout << "\n\t 4: Withdraw Money";
        cout << "\n\t 5: Close an Account";
        cout << "\n\t 6: Show all Accounts";
        cout << "\n\t 7: Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:     // Open an account
            cout << "Enter first name: "; cin >> fname;
            cout << "Enter last name: "; cin >> lname;
            cout << "Enter initial balance: "; cin >> balance;
            account = bank.openAct(fname, lname, balance);
            cout << "\nCongratulations! Account opened successfully!\n";
            cout << account;
            break;
        case 2:     // Balance enquiry
            cout << "Enter the account number: "; cin >> actNum;
            account = bank.balanceEnquiry(actNum);
            cout << "Your balance enquiry is: " << account;
            break;
        case 3:     // Deposit money
            cout << "Enter the account number: "; cin >> actNum;
            cout << "Enter amount to deposit: "; cin >> amount;
            account = bank.deposit(actNum, amount);
            cout << "The sum of " << amount
                 << " has been deposited to the account associated with the account number " << actNum;
            break;
        case 4:     // Withdraw money
            cout << "Enter the account number: "; cin >> actNum;
            cout << "Enter amount to withdraw: "; cin >> amount;
            account = bank.withdraw(actNum, amount);
            cout << "The sum of " << amount
                 << " has been withdrawn from the account associated with the account number " << actNum;
            break;
        case 5:     // Close an account
            cout << "Enter the account number: "; cin >> actNum;
            bank.closeAccount(actNum);
            cout << "The account having the account number " << actNum << " was closed successfully";
            break;
        case 6:     // Show all accounts
            bank.showAllAccounts();
            break;
        case 7:     // Quit
            break;
        default:
            cout << "Enter a valid choice";
            exit(0);
        }
    } while (choice != 7);

    return 0;
}
