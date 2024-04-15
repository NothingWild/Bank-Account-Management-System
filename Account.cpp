#include "Account.h"

int Account::nextAccountNumber = 1000;

Account::Account(const std::string& name, float initialDeposit) {
    accountNumber = new int(nextAccountNumber++);
    balances.push_back(initialDeposit); // initializes balance with initial deposit amount
    customerName = name; // set customer name
}

Account::~Account() {}

Account &Account::operator=(const Account &other) {
  if (this != &other) {
    this->accountNumber = other.accountNumber;
    this->customerName = other.customerName;
    this->balances = other.balances;
  }
  return *this;
}

int Account::getAccountNumber() const { 
    return *accountNumber; 
}

std::string Account::getCustomerName() const { 
    return customerName; 
}

std::vector<float> Account::getBalances() const {
    return balances;
}

void Account::setCustomerName(const std::string &name) { 
    customerName = name; 
}

void Account::deposit(float amount) { 
    balances[0] += amount; 
}

bool Account::withdraw(float amount) {
  if (balances[0] >= amount) {
    balances[0] -= amount;
    return true;
  } else {
    return false; // Insufficient funds
  }
}

// fast transfer using overloaded operator
Account &Account::operator+=(Account &other) {
  other.balances[0] += 40.0;
  this->balances[0] -= 40.0;
  return *this;
}