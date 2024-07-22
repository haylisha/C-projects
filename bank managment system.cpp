#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    float draw = 0, dep = 0, transfer = 0;
    string name;
    float balance = 5000;
    int account, account1, account2;
    int type;
    int transaction = 1;

    cout << "\n\t\t\t\tBANKING SYSTEM\n\n";
    cout << "\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4\n";
    cout << "\t\t\4\t\t\t\t\t\t\4\n";
    cout << "\t\t\4\t\t\t\t\t\t\4\n";
    cout << "\t\t\4\tWELCOME TO OUR HAYLISHA BANKING SYSTEM\t\4\n";
    cout << "\t\t\4\t\t\t\t\t\t\4\n";
    cout << "\t\t\4\t\t\t\t\t\t\4\n";
    cout << "\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4\n";

    cout << "Enter your name: ";
    cin >> name;
    cout << "\nPlease enter your account no.: ";
    cin >> type;

    while (transaction == 1) {
        int option;
        cout << "\nChoose what you want to do\n";
        cout << "1 - Balance Enquiry\n";
        cout << "2 - Deposit\n";
        cout << "3 - Withdraw\n";
        cout << "4 - Transfer\n";
        cin >> option;

        switch (option) {
            case 1:
                cout << "\t\t\t*BALANCE ENQUIRY*\n\n";
                cout << "Your current balance is: $" << fixed << setprecision(2) << balance << "\n";
                break;
            case 2:
                cout << "\n\t\t\t*DEPOSIT AMOUNT*\n\n";
                cout << "How much money do you want to deposit: ";
                cin >> dep;
                if (dep > 0 && dep <= 20000) {
                    cout << "\nYour $" << fixed << setprecision(2) << dep << " deposited in your account.\n\n";
                    balance += dep;
                } else if (dep > 20000) {
                    cout << "\nYou can't deposit that much amount in one time.\n\n";
                } else {
                    cout << "\nInvalid deposit amount\n";
                }
                break;
            case 3:
                cout << "\n\t\t*WITHDRAW AMOUNT*\n\n";
                cout << "How much money do you want to withdraw: ";
                cin >> draw;
                if (draw <= balance && draw <= 20000) {
                    cout << "\nYou just withdrew $" << fixed << setprecision(2) << draw << "\n\n";
                    balance -= draw;
                } else if (draw > 20000) {
                    cout << "\nYou can't withdraw that much amount in one time.\n\n";
                } else {
                    cout << "\nYou don't have enough money\n\n";
                }
                break;
            case 4:
                cout << "\t\t\tTRANSFER AMOUNT \n\n";
                cout << "\n\t\tAccount You Want To Transfer: ";
                cin >> account2;
                cout << "\nHow much amount?: ";
                cin >> transfer;
                if (balance >= transfer) {
                    cout << "\nYour $" << fixed << setprecision(2) << transfer << " successfully transferred\n\n";
                    balance -= transfer;
                } else {
                    cout << "\nYou do not have sufficient balance\n\n";
                }
                break;
            default:
                cout << "Invalid transaction\n";
        }

        transaction = 0;
        while (transaction != 1 && transaction != 2) {
            cout << "Do you want to do another transaction?\n";
            cout << "1. Yes 2. No\n";
            cin >> transaction;
            if (transaction != 1 && transaction != 2) {
                cout << "Invalid number.\nChoose between 1 and 2 only\n";
            }
        }
    }

    cout << "\n\t\t\t    -----------------------";
    cout << "\n\t\t\t\tHAYLISHA BANK LIMITED\n";
    cout << "\t\t\t    -----------------------\n\n";
    cout << "\t\t\tDate:3/5/16\t   Time:10:20 Am\n";
    cout << "\n\t\t\t\4 Your name: " << name << "\n\n";
    cout << "\t\t\t\4 Your account no: " << type << "\n\n";

    if (dep > 0 && dep <= 20000) {
        cout << "\t\t\t\4 You've deposited $" << fixed << setprecision(2) << dep << "\n";
    } else {
        cout << "\t\t\t\4 You've deposited $0\n";
    }

    if (draw > 0 && draw <= 20000 && draw <= balance) {
        cout << "\t\t\t\4 You've withdrawn $" << fixed << setprecision(2) << draw << "\n";
    } else {
        cout << "\t\t\t\4 You've withdrawn $0\n";
    }

    if (transfer > 0 && transfer <= 20000 && transfer <= balance) {
        cout << "\t\t\t\4 You've transferred $" << fixed << setprecision(2) << transfer << "\n";
    } else {
        cout << "You've transferred $0\n ";
    }

    cout << "\n\t\t\t\t    Thank you! \n";
    cout << "\t\t\t   Welcome to HAYLISHA Banking System\n";
    cout << "\t\t\t      www.HAYLISHABANKINGSYSTEM.com\n";

    return 0;
}
