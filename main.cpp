#include <iostream>
#include <fstream>
#include <regex>
#include <unistd.h>
#include <openssl/md5.h>




bool isValidEmail(std::string email) {
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");//regex pattern for email
    return std::regex_match(email, pattern);
}

bool isValidPassword(std::string password) {
    bool hasDigit = false, hasUpper = false, hasLower = false, hasSpecial = false;
    for (char c : password) {
        if (isdigit(c)) hasDigit = true;
        else if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (ispunct(c)) hasSpecial = true;
    }
    return password.size() >= 8 && hasDigit && hasUpper && hasLower && hasSpecial;
}

std::string md5(const std::string str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str.c_str(), str.size(), (unsigned char*)&digest);    
    char mdString[33];
    for (int i = 0; i < 16; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    return std::string(mdString);
}

bool userExists(std::string username) {
    std::ifstream file("users.txt");
    std::string line;
    while (std::getline(file, line)) {
        if (line.substr(0, line.find(":")) == username) {
            return true;
        }
    }
    return false;
}

void createUser() {
    std::string username, password;
    std::cout << "Enter email: ";
    std::cin >> username;
    if (!isValidEmail(username) || userExists(username)) {
        std::cout << "Invalid email or user already exists.\n";
        while(!isValidEmail(username) || userExists(username)){
            std::cout << "Enter email: ";
            std::cin >> username;
            if (!isValidEmail(username) || userExists(username)) {
                std::cout << "Invalid email or user already exists.\n";
            }
        }
    }
    do {
        std::cout << "Enter password: ";
        std::cin >> password;
        if (!isValidPassword(password)) {
            std::cout << "Password must be at least 8 characters and include at least one uppercase letter, one lowercase letter, one digit, and one special character.\n";
            
        }
    } while (!isValidPassword(password));
    std::ofstream file("users.txt", std::ios_base::app);
    file << username << ":" << md5(password) << std::endl;
    std::cout << "User created successfully." << std::endl;
    
}


void testLogin() {
    std::string username, password;
    std::cout << "Enter email: ";
    std::cin >> username;
    if (!isValidEmail(username)){
        std::cout << "Invalid email format, Try again!\n";
        while(!isValidEmail(username)){
            std::cout << "Enter email: ";
            std::cin >> username;
            if (!isValidEmail(username)) {
                std::cout << "Invalid email format, Try again!\n";
            }
        }
    }
    std::cout << "Enter password: ";
    std::cin >> password;
    std::ifstream file("users.txt");
    std::string line;
    while (std::getline(file, line)) {
        if (line.substr(0, line.find(":")) == username && line.substr(line.find(":") + 1) == md5(password)) {
            std::cout << "OK, login successful.\n";
            return;
        }
    }
    std::cout << "Login failed.\n";
}

void addUser(std::string username, std::string password) {
    std::ofstream file("users.txt", std::ios_base::app);
    file << username << ":" << md5(password) << "\n";
}

int main() {
    while (true) {
        std::cout << "1. Create user\n2. Test login\n0. Exit\nEnter choice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) createUser();
        else if (choice == 2) testLogin();
        else if (choice == 0) {
        std::cout << "Closing Program..." << std::endl;
        sleep(1);
        break;
        }else{
        std::cout << "Invalid choice.\n" << std::endl;
        }
    }
    
    return 0;
}