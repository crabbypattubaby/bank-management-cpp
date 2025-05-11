#include "bankAccount.h"
#include <ctime>

int main() {
  srand(time(NULL));
  bankAccount account1;
  account1.addAccountDetails();
  account1.showAccountDetails();
  return 0;
}
