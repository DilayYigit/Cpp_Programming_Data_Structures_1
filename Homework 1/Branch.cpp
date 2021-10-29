//
// Created by dilay on 6/20/21.
//

#include "Branch.h"
Branch::Branch(string name, int id) {
    branchName = name;
    branchId = id;
    bNumOfAccount = 0;
}
int Branch::getBranchId() {
    return branchId;
}
string Branch::getBranchName() {
    return branchName;
}
void Branch::setBranchId(int id) {
    branchId = id;
}
void Branch::setBranchName(string name) {
    branchName = name;
}

int Branch::getBNumOfAccount() {
    return bNumOfAccount;
}

void Branch::setBNumOfAccount(int num) {
    bNumOfAccount = num;
}
