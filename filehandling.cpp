#include "filehandling.h"

string serialization(bankAccount acc){
    return acc.accountNumber + "," + to_string(acc.balance) + "," + acc.name + "," + acc.phoneNumber + "," + acc.email + "," + acc.password;
}

bankAccount deserialization(string data){
    stringstream ss(data);
    string part;
    vector<string> parts;

        while(getline(ss, part, ',')){
        parts.push_back(part);
    }

    if (parts.size() != 6){
        throw runtime_error("Invalid Serializaed Format");
    }

    bankAccount acc;

    acc.accountNumber = parts[0];

    acc.balance = stoi(parts[1]);

    acc.name = part[2];

    acc.phoneNumber = part[3];

    acc.email = part[4];

    acc.password = part[5];

    return acc;

}

vector<bankAccount> loadAccounts(){
    ifstream file("accounts.csv");
    string contents;
    vector<bankAccount> allAccounts;

    if (file.is_open()){
    while (getline(file, contents)){
        allAccounts.push_back(deserialization(contents));
    } } else {
        cerr << "error opening file: account.csv";
    }

    file.close();
    return allAccounts;
}


void writeAccount(bankAccount& acc){
    ofstream file("accounts.csv", ios::app);
    if (file.is_open()) {
        file << serialization(acc) << endl;
    } else {
        cerr << "Error opening file: accounts.csv";
    }
    file.close();
}

void writeAccount(const vector<bankAccount>& allAccounts){
    ofstream file("accounts.csv");
    if (file.is_open()){
        for (const auto& account : allAccounts) {
            file << serialization(account) << endl;
        }
    }
    file.close();
}

optional<bankAccount> findAccount(string accNumber) {
        vector<bankAccount> allAccounts = loadAccounts();
        bool found = false;
        for (const auto& account : allAccounts)
        {
            if (account.accountNumber == accNumber){
                return account;
            }
        }

        cout << "Account not found";
        return nullopt;
}

optional<size_t> findAccountIndex(){
    vector<bankAccount> allAccounts = loadAccounts();
}

void deleteAccount(bankAccount account){
    vector<bankAccount> allAccounts = loadAccounts();
    
}

