# User Management System

This repository contains an individual project focused on creating a simple user management system in C++. The goal of the project is to provide a command-line application that allows users to create accounts, validate login credentials, and securely store user information.

## Overview

### Features

1. **Create User**:
   - Users can create an account by providing a valid email address as the username and a password.
   - Passwords must meet the following criteria:
     - At least 8 characters long
     - At least one uppercase letter
     - At least one lowercase letter
     - At least one digit
     - At least one special character
   - Usernames and hashed passwords are stored in a file named `users.txt` in the format:
     ```
     username:hashed_password
     username:hashed_password
     ```
   - **MD5 Hashing** is used to store passwords securely.

2. **Test Login**:
   - Users can test their login credentials by providing their email and password.
   - The program verifies the credentials against the stored information in `users.txt`.
   - Provides appropriate feedback: either successful login or an error message indicating incorrect credentials.

## Requirements

- **Software**:
  - C++ Compiler (e.g., GCC)
  - Text editor or IDE for writing C++ code

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/aalexanderfc/individuellUppgift_dataIT-.git
   cd individuellUppgift_dataIT-
   ```

2. **Compile the Code**:
   - Use a C++ compiler to compile the program:
   ```bash
   g++ user_management.cpp -o user_management
   ```

3. **Run the Program**:
   - Execute the compiled program:
   ```bash
   ./user_management
   ```

## How It Works

- **User Creation**: The program prompts the user to enter a valid email and password. It checks if the username already exists and ensures that the password meets the security requirements. The hashed password is then stored in `users.txt`.
- **Login Verification**: The user is prompted to enter their credentials, which are then verified against the stored records in `users.txt`. If the credentials match, the user is successfully logged in; otherwise, an appropriate error message is displayed.

## Example Code

Here is an example snippet of the C++ code for creating a user:

```cpp
#include <iostream>
#include <regex>
#include <fstream>
#include <openssl/md5.h>

void createUser() {
    // Code for prompting user and storing hashed password
}
```

For detailed code, please refer to the `user_management.cpp` file in the repository.

## Limitations

- The program uses **MD5** for hashing, which is not recommended for highly secure applications due to vulnerabilities. Consider using a stronger hashing algorithm for production use.
- The project is designed as a simple exercise in user management and may lack advanced security features found in full-scale applications.


## Author

Developed by Alexander. Feel free to reach out for more information or collaboration opportunities.

