#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "bankAccount.h"

using namespace std;

string serialization(bankAccount acc);
bankAccount deserialization(string data);
vector<bankAccount> loadAccounts();
void writeAccount(bankAccount& acc);
void writeAccount(const vector<bankAccount>& allAccounts);
optional<bankAccount> findAccount(string accNumber);
optional<size_t> findAccountIndex();
void deleteAccount();

#endif // FILEHANDLING_H