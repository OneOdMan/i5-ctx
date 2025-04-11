#include "crypter.h"
#include <iostream>
#include <string>

std::string username_input;
std::string password_input;
void display(std::string msg);
void login_screen();

// Displays a string message based on the input string msg
void display(std::string msg) { std::cout << msg << std::endl; }

void login_screen() {
  std::string username_line = "Enter your username: ";
  std::string password_line = "Enter your password: ";

  // Asking for username and password to store into respective variables
  display(username_line);
  std::cin >> username_input;
  display(password_line);
  std::cin >> password_input;
}

int main() {
  Crypter crypter;

  login_screen();
  crypter.verify(username_input, password_input);
}
