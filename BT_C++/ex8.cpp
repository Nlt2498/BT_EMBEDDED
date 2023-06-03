#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

class Account_Bank{
    private :
        char Num[20];
        char Name[20];
        long long Balance;


    public :
        Account_Bank(char Num[] = "\0",char Name[] = "\0", long long Balance = 0);

        char *Get_Num_Account() { return Account_Bank::Num; }
        char *Get_Name_Account() { return Account_Bank::Name; }
        long long Get_Balance_Account() { return Account_Bank::Balance; }

        void Withdraw_Money(long long take_money);
        void Deposit(long long add_money);
        void Check_Balance();
};

Account_Bank::Account_Bank(char Num[],char Name[], long long Balance)
{
    strcpy(Account_Bank::Num, Num);
    strcpy(Account_Bank::Name, Name);
    Account_Bank::Balance = Balance;
}

void Account_Bank::Withdraw_Money(long long take_money)
{
    long long check_money = Balance - take_money;

    if(check_money <= 50000)
    {
        printf("Can not implement, please recheck again\n");
    }
    else
    {
        Balance = Balance - take_money;
        printf("Amount to be withdrawn : %ld\n",take_money);
        //printf("Balance Account : %lf",Balance);
    }
}

void Account_Bank::Deposit(long long add_money)
{
    printf("Amount added : %ld\n", add_money);
    Balance = Balance + add_money;
    //printf("Balance Account : %lf",Balance);
}

void Account_Bank::Check_Balance()
{
    printf("Number Account : %s\n", Get_Num_Account());
    printf("Name Account : %s\n", Get_Name_Account());
    printf("Balance Account : %ld\n", Get_Balance_Account());
}

int main(int argc, char const *argv[])
{
    Account_Bank new_account("0123","Nguyen A", 100000);
    new_account.Withdraw_Money(120000);
    new_account.Deposit(80000);
    new_account.Withdraw_Money(120000);
    new_account.Check_Balance();

    printf("\n");

    Account_Bank new_account2("0124","Tran B", 300000);
    new_account2.Deposit(50000);
    new_account2.Withdraw_Money(250000);
    new_account2.Check_Balance();


    return 0;
}
