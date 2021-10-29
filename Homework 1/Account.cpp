//
// Created by dilay on 6/20/21.
//
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(int bId, int cId, double money) {
    aBranchId = bId;
    aCustomerId = cId;
    amount = money;
    accountId = 0;
}
int Account::getAccountId() {
    return accountId;
}
int Account::getABranchId() {
    return aBranchId;
}
int Account::getACustomerId() {
    return aCustomerId;
}
double Account::getAmount() {
    return amount;
}
void Account::setAccountId(int id) {
    accountId = id;
}
void Account::setABranchId(int bId) {
    aBranchId = bId;
}
void Account::setACustomerId(int cId) {
    aCustomerId = cId;
}
void Account::setAmount(double money) {
    amount = money;
}