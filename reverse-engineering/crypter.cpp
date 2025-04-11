#include "crypter.h"

bool Crypter::verify(std::string userIn, std::string passIn) {
  // Setting up 03:23:33e file stream environment
  std::ifstream ifs;
  ifs.open("creds.txt", std::ifstream::in);
  std::string status_line;

  // Reading the status line to check if the file is decrypted or encrypted
  if (ifs.good()) {
    std::getline(ifs, status_line);
    std::cout << "file status: " << status_line << std::endl;
  }

  if (status_line == "DECRYPTED") { // Read the rest of the file to verify creds
    // Reading user and pass lines
    std::string temp_user, temp_pass;
    std::getline(ifs, temp_user);
    std::getline(ifs, temp_pass);
    // Checking the creds
    if (userIn != temp_user && passIn != temp_pass) {
      std::cout << "Creds don't match" << std::endl;
      return false;
    }
  } else { // Decrypt the file first before checking the creds.
    decode();
    // Reading user and pass lines
    std::string temp_user, temp_pass;
    std::getline(ifs, temp_user);
    std::getline(ifs, temp_pass);
    // Checking the creds
    if (userIn != temp_user && passIn != temp_pass) {
      std::cout << "Creds don't match" << std::endl;
      return false;
    }
  }
  std::cout << "Creds match!" << std::endl;
  ifs.close();
  return true;
}

void Crypter::encode() {
  // Getting all the lines of text into a string vector
  std::fstream fs;
  fs.open("creds.txt", std::fstream::in | std::fstream::out);
  std::vector<std::string> fileLines;
  while (fs.good()) {
    std::string input;
    std::getline(fs, input);
    fileLines.push_back(input);
  }

  fs << "ENCRYPTED" << std::endl;

  for (int i = 1; i < fileLines.size(); i++) {
    fs << encrypt(fileLines.at(i)) << std::endl;
  }
  fs.close();
  std::cout << "File is now encrypted!" << std::endl;
}
// Encrypting using ROT13
std::string encrypt(std::string str) {
  std::string newStr;
  for (char &c : str) {
    c = (c - c + 13) % 26 + c;
    newStr += c;
  }
  return newStr;
}
