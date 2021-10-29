//
// Created by dilay on 6/20/21.
//
#include <iostream>
#ifndef DILAY_YIGIT_21602059_CUSTOMER_H
#define DILAY_YIGIT_21602059_CUSTOMER_H
using namespace std;
class Customer {
public:
    Customer(string = " ", int = 0);
    int getCustomerId();
    string getCustomerName();
    int getCNumOfAccount();
    void setCNumOfAccount(int);
    void setCustomerId(int);
    void setCustomerName(string);
private:
    int customerId;
    string customerName;
    int cNumOfAccount;
};
#endif //DILAY_YIGIT_21602059_CUSTOMER_H
