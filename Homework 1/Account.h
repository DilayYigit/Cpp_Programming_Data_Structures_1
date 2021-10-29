//
// Created by dilay on 6/20/21.
//
#include <iostream>
#ifndef DILAY_YIGIT_21602059_ACCOUNT_H
#define DILAY_YIGIT_21602059_ACCOUNT_H
using namespace std;

class Account {
public:
    Account(int = 0, int = 0, double = 0.0);
    int getABranchId();
    int getACustomerId();
    double getAmount();
    int getAccountId();
    void setAccountId(int);
    void setABranchId(int);
    void setACustomerId(int);
    void setAmount(double);
private:
    int aBranchId;
    int aCustomerId;
    double amount;
    int accountId;
};
#endif //DILAY_YIGIT_21602059_ACCOUNT_H
