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

    

}
/*
//bankAccount deserialization(const std::string& data) {
    bankAccount acc;
    std::stringstream ss(data);
    std::string segment;
    std::vector<std::string> parts;

    while (std::getline(ss, segment, ',')) {
        parts.push_back(segment);
    }

    if (parts.size() != 6) {
        throw std::runtime_error("Invalid serialized data format");
    }

    acc.accountNumber = parts[0];
    try {
        acc.balance = std::stoi(parts[1]);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid balance format in serialized data");
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Balance value out of range");
    }
    acc.name = parts[2];
    acc.phoneNumber = parts[3];
    acc.email = parts[4];
    acc.password = parts[5];

    return acc;
}
*/