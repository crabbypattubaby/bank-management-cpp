cmake_minimum_required(VERSION 3.10)

# Project name
project(BankManagement)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(
    bank-manager
    main.cpp
    bankAccount.cpp
)
