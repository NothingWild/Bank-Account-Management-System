#include "Project3.h"
#include "Account.h"
#include <iomanip> // setw()
#include <iostream>
#include <limits>

void openNewAccount(std::vector<Account> &accounts) {
  std::string name;
  float initialDeposit;

  std::cout << "Enter customer account name: ";
  std::cin >> name;
  //std::getline(std::cin >>std::ws, name);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears input buffer

  std::cout << "Enter initial deposit amount: $";
  std::cin >> initialDeposit;
  std::cout << std::endl;

  accounts.emplace_back(name, initialDeposit);

  std::cout << "Account opened: " << accounts.back().getAccountNumber()
            << " --- " << accounts.back().getCustomerName() << " : $"
            << initialDeposit << std::endl;
}

void depositIntoAccount(std::vector<Account> &accounts) {
  int accountNumber;
  std::string name;
  float amount;

  std::cout << "Enter account number: ";
  std::cin >> accountNumber;

  std::cout << "Enter customer account name: ";
  std::cin >> name;

  bool found = false;
  for (size_t i = 0; i < accounts.size(); ++i) {
    if (accounts[i].getAccountNumber() == accountNumber &&
        accounts[i].getCustomerName() == name) {
      found = true;
      std::cout << "Enter deposit amount: $";
      std::cin >> amount;
      accounts[i].deposit(amount);
      std::cout << "Deposit successful. New balance: $"
                << accounts[i].getBalances()[0] << std::endl;
      break;
    }
  }

  if (!found)
    std::cout << "Account number " << accountNumber << " not found."
              << std::endl;
}

void withdrawFromAccount(std::vector<Account> &accounts) {
  int accountNumber;
  std::string name;
  float amount;

  std::cout << "Enter account number: ";
  std::cin >> accountNumber;

  std::cout << "Enter customer account name: ";
  std::cin >> name;

  bool found = false;
  for (size_t i = 0; i < accounts.size(); ++i) {
    if (accounts[i].getAccountNumber() == accountNumber &&
        accounts[i].getCustomerName() == name) {
      found = true;
      std::cout << "Enter withdrawal amount: $";
      std::cin >> amount;
      std::cout << std::endl;
      if (accounts[i].withdraw(amount))
        std::cout << "Withdrawal successful. New balance: $"
                  << accounts[i].getBalances()[0] << std::endl;
      else
        std::cout << "Insufficient funds or withdrawal failed." << std::endl;
      break;
    }
  }

  if (!found)
    std::cout << "Account number " << accountNumber << " not found."<< std::endl;
}

void fastTransfer(std::vector<Account> &accounts) {
  int srcAccountNumber, dstAccountNumber;

  std::cout << "Enter source account number: ";
  std::cin >> srcAccountNumber;

  std::cout << "Enter destination account number: ";
  std::cin >> dstAccountNumber;

  // assigns null
  Account *srcAccount = nullptr; 
  Account *dstAccount = nullptr;

  for (size_t i = 0; i < accounts.size(); ++i) {
    if (accounts[i].getAccountNumber() == srcAccountNumber) {
      srcAccount = &accounts[i];
    }
    if (accounts[i].getAccountNumber() == dstAccountNumber) {
      dstAccount = &accounts[i];
    }
  }

  if (srcAccount && dstAccount) {
    srcAccount->withdraw(40.0); // Withdraw $40 from source account
    dstAccount->deposit(40.0);  // Deposit $40 to destination account
    std::cout << "Transfer successful. $40 transferred from account "
              << srcAccountNumber << " to account " << dstAccountNumber
              << std::endl;
  } else {
    std::cout << "One or both accounts not found." << std::endl;
  }
}

void printAllAccounts(const std::vector<Account> &accounts) {
  if (accounts.empty()) {
    std::cout << "No accounts found." << std::endl;
  } else {
    std::cout << "+--------------------------------------------------------+"
              << std::endl;
    std::cout << "| Acct Number | Name              | Balance              |"
              << std::endl;
    std::cout << "+--------------------------------------------------------+"
              << std::endl;
    for (size_t i = 0; i < accounts.size(); ++i) {
      std::cout << "| " << std::setw(11) << accounts[i].getAccountNumber()
                << " | " << std::setw(17) << accounts[i].getCustomerName()
                << " | " << std::setw(13) << "$" << std::fixed
                << std::setprecision(2) << accounts[i].getBalances()[0] << " |"
                << std::endl;
    }
    std::cout << "+--------------------------------------------------------+"
              << std::endl;
  }
}

void displayMenu() {
  std::cout << "+-----------------------------------+" << std::endl;
  std::cout << "| Enter account selection           |" << std::endl;
  std::cout << "| 1 : Open new account              |" << std::endl;
  std::cout << "| 2 : Deposit into account          |" << std::endl;
  std::cout << "| 3 : Withdraw from account         |" << std::endl;
  std::cout << "| 4 : Print a list of all accounts  |" << std::endl;
  std::cout << "| 5 : Fast transfer $40 into account|" << std::endl;
  std::cout << "| 6 : End transaction (Exit)        |" << std::endl;
  std::cout << "+-----------------------------------+" << std::endl;
}

void clearInputBuffer() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
  std::vector<Account> accounts;
  int choice;

  std::cout<< "+--------------------------------------------------------------+"<< std::endl;
  std::cout<< "|              Computer Science and Engineering                |"<< std::endl;
  std::cout<< "|            CSCE 1040 - Computer Programming II               |"<< std::endl;
  std::cout<< "|      Victor Pacheco     vmp0056      vmp0056@my.unt.edu      |"<< std::endl;
  std::cout<< "+--------------------------------------------------------------+"<< std::endl;

  do {
    displayMenu();
    std::cout << "> ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      openNewAccount(accounts);
      break;
    case 2:
      depositIntoAccount(accounts);
      break;
    case 3:
      withdrawFromAccount(accounts);
      break;
    case 4:
      printAllAccounts(accounts);
      break;
    case 5:
      fastTransfer(accounts);
      break;
    case 6:
      std::cout << "Thank you for your business!" << std::endl;
      break;
    default:
      std::cout << "Invalid option. Please pick an option from the menu."
                << std::endl;
    }

    clearInputBuffer(); // Clearing input buffer to handle incorrect input

   } while (choice != 6);

  return 0;
}