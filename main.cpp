#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// For AccountNumber Stuff
int getDigit(const int number);
int totalOdd(const std::string accNo);
int totalEven(const std::string accNo);
int accountNoChecker(std::string accNo);

// To Check the Phoen Number
bool isInteger(const string &str);

class bankAccount {
public:
  std::string name;
  std::string accountNumber;
  std::string phoneNumber;
  float balance;
  std::string email;
  std::string password;

  void accountDetails() {
    std::cout << "Your Account Number: " << accountNumber << endl;
    std::cout << "Your balance is: " << balance << endl;
    std::cout << "Your email is: " << email << endl;
    std::cout << "Your phone number is: " << phoneNumber << endl;
  } // To Show Acccount Details

  void addAccountDetails() {

    // For Name of the Account Creater
    cout << "Please enter your name:" << endl;
    bool check = true;
    do {
      cin >> name;
      if (name.empty()) {
        cout << "You can't leave this field empty." << endl;
        check = false;
      } else {
        check = true;
      }
    } while (!check);

    // For creating his account accountNumber

    do {
      accountNumber = to_string((rand() % 10) + 1); // Corrected syntax
    } while (accountNoChecker(accountNumber));

    cout << endl
         << "Here is your bank Account Number: " << accountNumber << endl;

    // For Phone Number

    cout << "Please enter you phone number: " << endl;
    do {
      cin >> phoneNumber;
      if (phoneNumber.empty()) {
        cout << "You can't leave this field empty." << endl;
        check = false;
      } else if (phoneNumber.length()) {
        cout << "Invalid Number length" << endl;
        check = false;
      } else if (isInteger(phoneNumber)) {
        cout << "Invalid Characters" << endl;
        check = false;
      } else {
        check = true;
      }
    } while (!check);

    // For email

    cout << endl << "Please enter you email id: " << endl;
  }
};

int main() {
  srand(time(NULL));
  bankAccount account1;

  cin >> account1.name;
  cin >> account1.accountNumber;
  cin >> account1.phoneNumber;
  cin >> account1.balance;
  cin >> account1.email;

  account1.accountDetails();

  return 0;
}

// Account Number Related Functions

int getDigit(const int number) { return number % 10 + ((number / 10) % 10); }

int totalOdd(const std::string accNum) {

  int sum = 0;

  for (int i = accNum.size() - 1; i >= 0; i -= 2) {
    sum += getDigit(accNum[i] - '0');
  }

  return sum;
}

int totalEven(const std::string accNum) {

  int sum = 0;

  for (int i = accNum.size() - 2; i >= 0; i -= 2) {
    sum += getDigit((accNum[i] - '0') * 2);
  }

  return sum;
}

int accountNoChecker(std::string accNo) {
  int result = totalEven(accNo) + totalOdd(accNo);

  if (result % 10 == 0) {
    return true;
  } else {
    return false;
  }
}

// To check phone Number

bool isInteger(const string &str) {
  return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}
