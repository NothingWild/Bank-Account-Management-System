#ifndef PROJECT3_H
#define PROJECT3_H

#include "Account.h"
#include <vector>

// Function prototypes
void openNewAccount(std::vector<Account> &accounts);
void depositIntoAccount(std::vector<Account> &accounts);
void withdrawFromAccount(std::vector<Account> &accounts);
void fastTransfer(std::vector<Account> &accounts);
void printAllAccounts(const std::vector<Account> &accounts);
void displayMenu();
void clearInputBuffer();

#endif