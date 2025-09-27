#include <iostream>
#include <vector>

using namespace std;

class NonWithdrawAccount
{
public:
    virtual void deposit(int amount) = 0;
};

class WithdrawAccount : public NonWithdrawAccount
{
public:
    virtual void withdraw(int amount) = 0;
};

class CurrentAccount : public WithdrawAccount
{
private:
    int balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
        cout << "Current Balance: " << balance << endl;
    }
    void withdraw(int amount)
    {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

class SavingAccount : public NonWithdrawAccount
{
private:
    int balance;

public:
    SavingAccount()
    {
        balance = 0;
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

class Client
{
private:
    vector<NonWithdrawAccount *> accounts;
    vector<WithdrawAccount *> wAccounts;

public:
    Client(vector<NonWithdrawAccount *> acc, vector<WithdrawAccount *> wAcc)
    {
        accounts = acc;
        wAccounts = wAcc;
    }
    void transaction()
    {
        for (NonWithdrawAccount *acc : accounts)
        {
            acc->deposit(100);
        }
        for (WithdrawAccount *wAcc : wAccounts)
        {
            wAcc->deposit(4000);
            wAcc->withdraw(30);
        }
    };
};
int main()
{

    vector<NonWithdrawAccount *> accounts;
    vector<WithdrawAccount *> wAccounts;
    CurrentAccount *ca1 = new CurrentAccount();
    wAccounts.push_back(ca1);
    SavingAccount *sa1 = new SavingAccount();
    accounts.push_back(sa1);
    Client *ca = new Client(accounts, wAccounts);
    ca->transaction();
    return 0;
}
