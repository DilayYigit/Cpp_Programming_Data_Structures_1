//
// Created by dilay on 6/20/21.
//
#include <iostream>
#include "Branch.h"
#include "Customer.h"
#include "Account.h"
#ifndef DILAY_YIGIT_21602059_BANKINGSYSTEM_H
#define DILAY_YIGIT_21602059_BANKINGSYSTEM_H
using namespace std;
class BankingSystem {
public :
    BankingSystem () ;
    ~ BankingSystem () ;
    void addBranch ( const int branchId , const string branchName ) ;
    void deleteBranch ( const int branchId ) ;
    void addCustomer ( const int customerId , const string customerName ) ;
    void deleteCustomer ( const int customerId ) ;
    int addAccount ( const int branchId , const int customerId , const double
    amount ) ;
    void deleteAccount ( const int accountId ) ;
    void showAllAccounts () ;
    void showBranch ( const int branchId ) ;
    void showCustomer ( const int customerId ) ;

private:
    Branch *branches;
    int branchSize;
    Customer *customers;
    int customerSize;
    Account *accounts;
    int accountSize;
    int accountNum;
};
#endif //DILAY_YIGIT_21602059_BANKINGSYSTEM_H
