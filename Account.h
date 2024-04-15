#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
  int* accountNumber;
  std::string customerName;
  std::vector<float> balances;
  static int nextAccountNumber;

public:
  // Constructor
  Account(const std::string &name, float initialDeposit);

  // Destructor
  ~Account();

  // Copy assignment operator
  Account &operator=(const Account &other);

  // Accessor functions
  int getAccountNumber() const;
  std::string getCustomerName() const;
  std::vector<float> getBalances() const;

  // Mutator functions
  void setCustomerName(const std::string &name);
  void deposit(float amount);
  bool withdraw(float amount);

  // Overloaded operator for fast transfer
  Account &operator+=(Account &other);
};

#endif