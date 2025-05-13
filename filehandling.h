#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "bankAccount.h"

using namespace std;

string serialization(bankAccount acc);
bankAccount deserialization();
void WriteAccount();
void readAccount();
void deleteAccount();