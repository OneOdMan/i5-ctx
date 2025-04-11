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
  ifs.close();

  if (status_line == "DECRYPTED") { // Read the rest of the file to verify creds
    // Reading user and pass lines
    ifs.open("creds.txt", std::ifstream::in);
    std::string temp_user, temp_pass;
    std::getline(ifs, temp_user);
    std::getline(ifs, temp_pass);
    ifs.close();
    // Checking the creds
    if (userIn != temp_user && passIn != temp_pass) {
      std::cout << "Creds don't match" << std::endl;
      encode();
      return false;
    }
  } else { // Decrypt the file first before checking the creds.
    decode();
    // Reading user and pass lines
    ifs.open("creds.txt", std::ifstream::in);
    std::getline(ifs, status_line);
    std::string temp_user, temp_pass;
    std::getline(ifs, temp_user);
    std::getline(ifs, temp_pass);
    ifs.close();
    // Checking the creds
    if (userIn != temp_user && passIn != temp_pass) {
      std::cout << "Creds don't match" << std::endl;
      encode();
      return false;
    }
  }
  std::cout << "Creds match!" << std::endl;
  encode();
  return true;
}

void Crypter::encode() {
  // Getting all the lines of text into a string vector
  std::fstream fs;
  fs.open("creds.txt", std::fstream::in);
  std::vector<std::string> fileLines;
  while (fs.good()) {
    std::string input;
    std::getline(fs, input);
    fileLines.push_back(input);
  }
  fs.close();
  fs.open("creds.txt", std::fstream::out);
  fs << "ENCRYPTED" << std::endl;

  for (int i = 1; i < 3; i++) {
    const std::string in = encrypt(fileLines.at(i));
    fs << in << std::endl;
  }
  fs.close();
  std::cout << "File is now encrypted!" << std::endl;
}
// Encrypting using ROT13
std::string Crypter::encrypt(std::string str) {
  std::string newStr;
  for (char &c : str) {
    c += 13;
    newStr += c;
  }
  return newStr;
}

void Crypter::decode() {
  // Getting all the lines of text into a string vector
  std::fstream fs;
  fs.open("creds.txt", std::fstream::in);
  std::vector<std::string> fileLines;
  while (fs.good()) {
    std::string input;
    std::getline(fs, input);
    fileLines.push_back(input);
  }
  fs.close();
  fs.open("creds.txt", std::fstream::out);
  fs << "DECRYPTED" << std::endl;

  for (int i = 1; i < 3; i++) {
    fs << decrypt(fileLines.at(i)) << std::endl;
  }
  fs.close();
  std::cout << "File is now decrypted!" << std::endl;
}
// Encrypting using ROT13
std::string Crypter::decrypt(std::string str) {
  std::string newStr;
  for (char &c : str) {
    c -= 13;
    newStr += c;
  }
  return newStr;
}
