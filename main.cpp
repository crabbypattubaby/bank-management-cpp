#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <regex>
#include <string>

using namespace std;

// For AccountNumber Stuff
int getDigit(const int number);
int totalOdd(const std::string accNo);
int totalEven(const std::string accNo);
int accountNoChecker(std::string accNo);

// To Check the Phone Number
bool isInteger(const string &str);

// could you check if everything is at par

class bankAccount {
public:
  std::string name;
  std::string accountNumber;
  std::string phoneNumber;
  float balance;
  std::string email;
  std::string password;

  void showAccountDetails() {
    std::cout << "Your Account Number: " << accountNumber << endl;
    std::cout << "Your balance is: " << balance << endl;
    std::cout << "Your email is: " << email << endl;
    std::cout << "Your phone number is: " << phoneNumber << endl;
  } // To Show Acccount Details

  void addAccountDetails() {

    // For Name of the Account Creater
    cout << "Please enter your name:" << endl;
    bool check = true;

    std::regex pattern1(R"([^\w\s])");
    std::regex pattern2(R"(\d)");

    do {
      std::getline(std::cin, name);
      if (name.empty()) {
        cout << "You can't leave this field empty." << endl;
        check = false;
      } else if (std::regex_search(name, pattern1)) {
        std::cout << "Your name cannot contain special characters."
                  << std::endl;
        check = false;
      } else if (std::regex_search(name, pattern2)) {
        std::cout << "Your name cannot contain numbers." << std::endl;
        check = false;
      } else {
        check = true;
      }
    } while (!check);

    // For creating his account Number

    do {
      accountNumber = std::to_string((rand() % 1000000000) +
                                     100000000); // Generates a 9-digit number
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
      } else if (phoneNumber.length() != 10) {
        cout << "Invalid Number length" << endl;
        check = false;
      } else if (!isInteger(phoneNumber)) {
        cout << "Invalid Characters" << endl;
        check = false;
      } else {
        check = true;
      }
    } while (!check);

    // For email

    cout << endl << "Please enter you email id: " << endl;
    std::regex pattern(R"(\w+@\w+(\.\w+)+)");

    do {
      cin >> email;
      if (email.empty()) {
        cout << "You can't leave this field empty." << endl;
        check = false;
      } else if (!std::regex_search(email, pattern)) {
        cout << "Invalid Email Address." << endl;
        check = false;
      } else {
        check = true;
      }
    } while (!check);

    // For password

    cout << "Please enter your new password" << endl;

    do {
      do {
        cin >> password;

        if (!(password.length() >= 8)) {
          cout << "This is not a valid password length." << endl;
          check = false;
        } else if (!std::regex_search(password, pattern1) ||
                   !std::regex_search(password, pattern2)) {
          cout << "Your password must contain 1 special character and 1 digit."
               << endl;
          check = false;
        } else {
          check = true;
        }
      } while (!check);

      std::string tempPassword;
      int repetitions = 0;

      cout << "Please reenter you new password." << endl;

      do {

        cin >> tempPassword;

        if (password != tempPassword) {

          cout << "The password you have entered is not matching." << endl;
          check = false;
          repetitions += 1;
        } else {
          check = true;
        }
      } while (!check && repetitions <= 3);

    } while (!check);

    // To enter the balance

    do {

      cout << "Please enter your balance:" << endl;

      while (!(std::cin >> balance)) {
        std::cout << "Invalid input! Please enter a valid number: " << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }

      if (balance == 0) {
        cout << "You cannot leave this value as null. Please enter a valid "
                "balance."
             << endl;
        check = false;
      } else {
        check = true;
      } 
    } while (!check);

    cout << "Please check your inputted values once again:" << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number" << phoneNumber << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
    cout << "Do you accept these? y for yes and n for no" << endl;
    char answer;
    do {
      cin >> answer;
    } while (answer != 'y' && answer != 'n');

    if (answer == 'n') {
      addAccountDetails();
    } else if (answer == 'y') {
      cout << "Thank you for adding your details :)" << endl;
    }
  }
};

int main() {
  srand(time(NULL));
  bankAccount account1;

  account1.addAccountDetails();
  account1.showAccountDetails();

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
