//
// Created by dilay on 6/20/21.
//
#include <iostream>
#include "Customer.h"
using namespace std;

Customer::Customer(string name, int id) {
    customerName = name;
    customerId = id;
    cNumOfAccount = 0;
}
int Customer::getCustomerId() {
    return customerId;
}
string Customer::getCustomerName() {
    return customerName;
}
void Customer::setCustomerId(int id) {
    customerId = id;
}
void Customer::setCustomerName(string name) {
    customerName = name;
}
int Customer::getCNumOfAccount() {
    return cNumOfAccount;
}
void Customer::setCNumOfAccount(int num) {
    cNumOfAccount = num;
}