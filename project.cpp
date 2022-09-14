#include <iostream>
using namespace std;
class info
{
public:
    double balance2 = 45000;

public:
    double getbalance()
    {
        return balance2;
    }
};
// here class info is inherited to use data member balance2
class deposit : public info
{
public:
    double amount_deposit()
    {
        double deposit;
        cout << "Enter the amount to deposit" << endl;
        cin >> deposit;
        cout << endl
             << endl;
        balance2 = deposit + balance2;
        cout << "Deposited amount: " << deposit << endl;
        cout << "Your current balance is " << balance2 << endl;
        cout << endl;
    }
};
// here composition is done to use balance
class withdraw : public info
{
    info i1;

public:
    double withdrawamount()
    {
        int option;
        cout << "Choose a withdrawl option (1-3)" << endl;
        cin >> option;
        if (option == 1)
        {
            if (balance2 < 5000)
            {
                cout << "You dont have enough amount" << endl;
            }
            else
            {
                balance2 = balance2 - 5000;
                cout << "You have withdrawn 5000PKR " << endl;
                cout << "Please take your withdrawl amount" << endl
                     << endl;
                cout << "Your new balance is " << i1.balance2 - 5000 << endl
                     << endl;
            }
        }
        else if (option == 2)
        {
            if (balance2 < 10000)
            {
                cout << "Your balance is less please re-enter amount" << endl;
            }
            else
            {
                balance2 = balance2 - 10000;
                cout << "You have withdrawn 10000PKR " << endl;
                cout << "Please take your withdrawl amount" << endl
                     << endl;
                cout << "Your new balance is " << i1.balance2 - 10000 << endl
                     << endl;
            }
        }
        else if (option == 3)
        {
            if (balance2 < 20000)
            {
                cout << "Your balance is less please re-enter amount" << endl;
            }
            else
            {
                balance2 = balance2 - 20000;
                cout << "You have withdrawn 20000PKR " << endl;
                cout << "Please take your withdrawl amount" << endl
                     << endl;
                cout << "Your new balance is " << i1.balance2 - 20000 << endl
                     << endl;
            }
        }
    }
};
// here class deposit, withdraw and info are inherited
class menu : public deposit, public withdraw, public info
{
public:
    info i1;
    long get_accno, get_accpin;

public:
    void welcome()
    {
        cout << "*************WELCOME***************" << endl;
    }
    void inputaccdetails()
    {
        cout << "Enter your 8-digits account number " << endl;
        cin >> get_accno;
        cout << "Enter your 5 digits account  pin" << endl;
        cin >> get_accpin;
    }
    void choice_selection()
    {
        cout << "Main Menu" << endl;
        cout << "1-View my balance" << endl;
        cout << "2-Withdraw cash" << endl;
        cout << "3-Deposit funds " << endl;
        cout << "4-Exit" << endl;
        transactionpass();
    }
    void transactionpass()
    {
        int choice;
        cout << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Your current balance is " << i1.balance2 << endl
                 << endl;
            choice_selection();
        }
        else if (choice == 2)
        {
            cout << "Withdrawl options:" << endl;
            cout << "   1-   5000PKR   " << endl;
            cout << "   2-   10000PKR   " << endl;
            cout << "   3-   20000PKR   " << endl;
            withdrawamount();
            cout << endl;
            choice_selection();
        }
        else if (choice == 3)
        {

            amount_deposit();
            choice_selection();
        }
        else if (choice == 4)
        {
            cout << "*****THANK YOU******" << endl;
        }
        else
        {
            cout << "Please enter the correct choice " << endl
                 << endl;
            choice_selection();
        }
    }
};
int main()
{
    menu m1;
    m1.inputaccdetails();
    m1.welcome();
    m1.choice_selection();
    return 0;
}