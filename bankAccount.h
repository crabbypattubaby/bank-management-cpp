#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <regex>
#include <string>

using namespace std;

// Function Prototypes (Declarations only)
int getDigit(const int number);
int totalOdd(const std::string accNo);
int totalEven(const std::string accNo);
int accountNoChecker(std::string accNo);
bool isInteger(const string &str);

class bankAccount {
public:
  std::string name;
  std::string accountNumber;
  std::string phoneNumber;
  float balance;
  std::string email;
  std::string password;

  void showAccountDetails(); // Declaration
  void addAccountDetails();  // Declaration
};

#endif // BANKACCOUNT_H
