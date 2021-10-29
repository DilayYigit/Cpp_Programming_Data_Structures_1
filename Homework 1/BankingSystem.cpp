//
// Created by dilay on 6/20/21.
//
#include <iostream>
#include "BankingSystem.h"
#include "Branch.h"
#include "Account.h"
using namespace std;
BankingSystem::BankingSystem() {
    branchSize = 0;
    branches = NULL;
    customerSize = 0;
    customers = NULL;
    accountSize = 0;
    accounts = NULL;
    accountNum = 1;
}
void BankingSystem::addBranch(const int branchId, const string branchName) {
    bool isExist = false;
    if(branchSize == 0){
        branches = new Branch[branchSize + 1];
        branches[0].setBranchId(branchId);
        branches[0].setBranchName(branchName);
        branchSize++;
        cout << "Branch " << branchId << " has been added." << endl;
    }
    else{
        for(int i = 0; i < branchSize ; i++){
            if(branches[i].getBranchId() == branchId){
                isExist = true;
                cout << "Branch " << branchId << " already exists." << endl;
                break;
            }
        }
        if (isExist == false) {
           Branch *temp = branches;
           branches =  new Branch[branchSize + 1];
           for (int i = 0; i < branchSize; i++) {
               branches[i].setBranchName(temp[i].getBranchName());
               branches[i].setBranchId(temp[i].getBranchId());
           }
           branches[branchSize].setBranchId(branchId);
           branches[branchSize].setBranchName(branchName);
           branchSize++;
           delete [] temp;
           cout << "Branch " << branchId << " has been added." << endl;
        }

    }

}
void BankingSystem::deleteBranch(const int branchId) {
    bool isExist = false;
    if(branchSize == 0) {
        cout << "There is no branch." << endl;
    }
    else {
        int i;
        for (i = 0; i < branchSize; i++) {
            if (branches[i].getBranchId() == branchId) {
                isExist = true;
                break;
            }
        }
        if (isExist == true) {
            Branch *temp = branches;
            branches = new Branch[branchSize - 1];
            for(int j = 0; j < i; j++) {
                branches[j].setBranchId(temp[j].getBranchId());
                branches[j].setBranchName(temp[j].getBranchName());
            }
            for(int j = i; j < branchSize-1; j++) {
                branches[j].setBranchId(temp[j+1].getBranchId());
                branches[j].setBranchName(temp[j+1].getBranchName());
            }
            branchSize--;
            delete [] temp;
            cout << "Branch " << branchId << " has been deleted." << endl;
            for (int j = 0; j < accountSize; j++) {
                if (branchId == accounts[j].getABranchId()) {
                    deleteAccount(accounts[j].getAccountId());
                }
            }
        }
        else
            cout << "Branch " << branchId << " does not exit." << endl;
    }
}
void BankingSystem::addCustomer(const int customerId, const string customerName) {
    bool isExist = false;
    if(customerSize == 0){
        customers = new Customer[customerSize + 1];
        customers[0].setCustomerId(customerId);
        customers[0].setCustomerName(customerName);
        customerSize++;
        cout << "Customer " << customerId << " has been added." << endl;
    }
    else {
        for(int i = 0; i < customerSize; i++) {
            if(customers[i].getCustomerId() == customerId) {
                cout << "Customer " << customerId << " already exists." << endl;
                isExist = true;
                break;
            }
        }
        if(isExist == false) {
            Customer *temp = customers;
            customers = new Customer[customerSize + 1];
            int i;
            for (i = 0; i < customerSize; i++) {
                customers[i].setCustomerId(temp[i].getCustomerId());
                customers[i].setCustomerName(temp[i].getCustomerName());
            }
            customers[customerSize].setCustomerId(customerId);
            customers[customerSize].setCustomerName(customerName);
            customerSize++;
            delete[] temp;
            cout << "Customer " << customerId << " has been added." << endl;
        }
    }
}
void BankingSystem::deleteCustomer(const int customerId) {
    bool isExist = false;
    if(customerSize == 0) {
        cout << "There is no customer." << endl;
    }
    else {
        int i;
        for (i = 0; i < customerSize; i++) {
            if (customers[i].getCustomerId() == customerId) {
                isExist = true;
                break;
            }
        }
        if (isExist == true) {
            Customer *temp = customers;
            customers =  new Customer[customerSize - 1];
            for(int j = 0; j < i; j++) {
                customers[j].setCustomerId(temp[j].getCustomerId());
                customers[j].setCustomerName(temp[j].getCustomerName());
            }
            for(int j = i; j < customerSize - 1; j++) {
                customers[j].setCustomerId(temp[j+1].getCustomerId());
                customers[j].setCustomerName(temp[j+1].getCustomerName());
            }
            customerSize--;
            delete [] temp;
            cout << "Customer " << customerId << " has been deleted." << endl;
            for (int j = 0; j < accountSize; j++){
                if (customerId == accounts[j].getACustomerId()) {
                    deleteAccount(accounts[j].getAccountId());
                }
            }
        }
        else
            cout << "Customer " << customerId << " does not exit." << endl;
    }
}
int BankingSystem::addAccount(const int branchId, const int customerId, const double amount) {
    bool branchExist = false;
    bool customerExist = false;
    int i;
    for (i = 0; i < branchSize; i++){
        if (branches[i].getBranchId() == branchId) {
            branchExist = true;
            break;
        }
    }
    int j;
    for (j = 0; j < customerSize; j++) {
        if (customers[j].getCustomerId() == customerId) {
            customerExist = true;
            break;
        }
    }
    if (branchExist == true && customerExist == true) {
        if (accountSize == 0) {
            accounts = new Account[accountSize + 1];
            accounts[0].setABranchId(branchId);
            accounts[0].setACustomerId(customerId);
            accounts[0].setAmount(amount);
            accounts[0].setAccountId(accountNum);
            accountSize++;
            cout << "Account " << accountNum << " added for customer " << customerId << " at branch " << branchId << endl;
            branches[i].setBNumOfAccount(branches[i].getBNumOfAccount()+1);
            customers[j].setCNumOfAccount(customers[j].getCNumOfAccount()+1);
            accountNum++;
            return accountNum - 1;
        }
        else {
            Account *temp = accounts;
            accounts = new Account[accountSize + 1];
            for (int count = 0; count < accountSize; count++) {
                accounts[count].setABranchId(temp[count].getABranchId());
                accounts[count].setACustomerId(temp[count].getACustomerId());
                accounts[count].setAmount(temp[count].getAmount());
                accounts[count].setAccountId(temp[count].getAccountId());
            }
            accounts[accountSize].setABranchId(branchId);
            accounts[accountSize].setACustomerId(customerId);
            accounts[accountSize].setAmount(amount);
            accounts[accountSize].setAccountId(accountNum);
            accountSize++;
            delete [] temp;
            cout << "Account " << accountNum << " added for customer " << customerId << " at branch " << branchId << endl;
            branches[i].setBNumOfAccount(branches[i].getBNumOfAccount()+1);
            customers[j].setCNumOfAccount(customers[j].getCNumOfAccount()+1);
            accountNum++;
            return accountNum - 1;
        }
    }
    else if (branchExist == false && customerExist == true) {
        cout << "Branch " << branchId << " does not exist." << endl;
        return -1;
    }
    else if (branchExist == true && customerExist == false) {
        cout << "Customer " << customerId << " does not exist." << endl;
        return -1;
    }
    else {
        cout << "Account -1 does not exist." << endl;
        return -1;
    }
}
void BankingSystem::deleteAccount(const int accountId) {
    bool isExist = false;
    if(accountSize == 0) {
        cout << "There is no account." << endl;
    }
    else {
        int i;
        for (i = 0; i < accountSize; i++) {
            if (accounts[i].getAccountId() == accountId) {
                isExist = true;
                break;
            }
        }
        if (isExist == true) {
            for (int count = 0; count < branchSize; count++) {
                if (branches[count].getBranchId() == accounts[i].getABranchId()) {
                    branches[count].setBNumOfAccount(branches[count].getBNumOfAccount()-1);
                }
            }
            for (int count = 0; count < customerSize; count++) {
                if (customers[count].getCustomerId() == accounts[i].getACustomerId()) {
                    customers[count].setCNumOfAccount(customers[count].getCNumOfAccount()-1);
                }
            }
            Account *temp = accounts;
            accounts =  new Account[accountSize - 1];
            for(int j = 0; j < i; j++) {
                accounts[j].setAccountId(temp[j].getAccountId());
                accounts[j].setAmount(temp[j].getAmount());
                accounts[j].setACustomerId(temp[j].getACustomerId());
                accounts[j].setABranchId(temp[j].getABranchId());
            }
            for(int j = i; j < accountSize - 1; j++) {
                accounts[j].setAccountId(temp[j+1].getAccountId());
                accounts[j].setAmount(temp[j+1].getAmount());
                accounts[j].setACustomerId(temp[j+1].getACustomerId());
                accounts[j].setABranchId(temp[j+1].getABranchId());
            }
            accountSize--;
            delete [] temp;
            cout << "Account " << accountId << " has been deleted." << endl;
        }
        else
            cout << "Account " << accountId << " does not exit." << endl;
    }

}
void BankingSystem::showAllAccounts() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Account id\tBranch id\tBranch name\tCustomer id\tCustomer name\tBalance\t" << endl;
    for (int i = 0; i < accountSize; i++) {
        cout << "\t" << accounts[i].getAccountId() << "\t" << accounts[i].getABranchId() << "\t";
        for (int j = 0; j < branchSize; j++) {
            if (branches[j].getBranchId() == accounts[i].getABranchId()) {
                cout << branches[j].getBranchName() << "\t";
            }
        }
        cout  << accounts[i].getACustomerId() << "\t";
        for (int j = 0; j < customerSize; j++) {
            if (customers[j].getCustomerId() == accounts[i].getACustomerId()){
                cout << customers[j].getCustomerName() << "\t";
                break;
            }
        }
        cout << accounts[i].getAmount() << "\t" << endl;
    }
}
void BankingSystem::showBranch(const int branchId) {
    cout << "-----------------------------------------------------------" << endl;
    bool isExist = false;
    int count;
    for(count = 0; count < branchSize ; count++){
        if(branches[count].getBranchId() == branchId){
            isExist = true;
            break;
        }
    }
    if (isExist == false) {
        cout << "Branch " << branchId << " does not exist." << endl;
    }
    else {
        cout << "Branch id: " << branches[count].getBranchId() << " Branch name: " <<
        branches[count].getBranchName() << " Number of accounts: " << branches[count].getBNumOfAccount() << endl;

        if ( branches[count].getBNumOfAccount() != 0) {
            cout << "Accounts at this branch: " << endl;
            cout << "Account id\tCustomer id\tCustomer name\tBalance\t" << endl;

            int i;
            for (i = 0; i < accountSize; i++) {
                if (accounts[i].getABranchId() == branchId) {
                    cout << "\t" << accounts[i].getAccountId() << "\t" << accounts[i].getACustomerId() << "\t";
                    for (int j = 0; j < customerSize; j++) {
                        if (accounts[i].getACustomerId() == customers[j].getCustomerId()) {
                            cout << customers[j].getCustomerName() << "\t";
                            cout << accounts[i].getAmount() << "\t" << endl;
                        }
                    }
                }
            }
        }
        else
            cout << "There is no account for this branch." << endl;
    }
}
void BankingSystem::showCustomer(const int customerId) {
    cout << "-----------------------------------------------------------" << endl;
    bool isExist = false;
    int count;
    for(count = 0; count < customerSize ; count++){
        if(customers[count].getCustomerId() == customerId){
            isExist = true;
            break;
        }
    }
    if (isExist == false) {
        cout << "Customer " << customerId << " does not exist." << endl;
    }
    else {
        cout << "Customer id: " << customers[count].getCustomerId() << " Customer name: " <<
             customers[count].getCustomerName() << " Number of accounts: "
             << customers[count].getCNumOfAccount() << endl;

        if ( customers[count].getCNumOfAccount() != 0){
            cout << "Accounts at this customer: " << endl;
            cout << "Account id\tBranch id\tBranch name\tBalance\t" << endl;
            int i;
            for (i = 0; i < accountSize; i++) {
                if (accounts[i].getACustomerId() == customerId) {
                    cout << "\t" << accounts[i].getAccountId() << "\t" << accounts[i].getABranchId() << "\t";
                    for (int j = 0; j < branchSize; j++) {
                        if (accounts[i].getABranchId() == branches[j].getBranchId()) {
                            cout << branches[j].getBranchName() << "\t";
                            cout << accounts[i].getAmount() << "\t" << endl;
                        }
                    }
                }
            }
        }
        else
            cout << "There is no account for this customer." << endl;
    }
}

BankingSystem::~BankingSystem() {

    delete [] branches;
    delete [] customers;
    delete [] accounts;

}
