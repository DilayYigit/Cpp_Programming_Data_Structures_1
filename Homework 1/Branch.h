//
// Created by dilay on 6/20/21.
//
#include <iostream>
#ifndef DILAY_YIGIT_21602059_BRANCH_H
#define DILAY_YIGIT_21602059_BRANCH_H
using namespace std;
class Branch {
public:
    Branch(string = " ", int = 0);
    int getBranchId();
    string getBranchName();
    void setBranchId(int);
    void setBranchName(string);
    int getBNumOfAccount();
    void setBNumOfAccount(int);
private:
    int branchId;
    string branchName;
    int bNumOfAccount;
};
#endif //DILAY_YIGIT_21602059_BRANCH_H
