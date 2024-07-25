#include <iostream>
using namespace std;

class BankAccount {

private:

    double balance;

public:

    BankAccount(double initial_balance = 0.0) {
        balance = initial_balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " rupees " <<"New balance is " << balance << " rupees." << endl;
        }else {
            cout << "Enter a valid amount" << endl;
        }
    }

    void withdraw(double amount){
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrew " << amount<< " rupees" << ". New balance is "<< balance << " rupees." << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Enter a valid amount." << endl;
        }
    }

    void getBalance(){
        std::cout << "Current balance: " << balance << std::endl;
    }

};

int main() {

    BankAccount account(100.0);
    account.deposit(50.0);
    account.withdraw(20.0);
    account.getBalance();

    return 0;
}
