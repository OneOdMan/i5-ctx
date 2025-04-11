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

  } else { // Decrypt the file first before checking the creds
  }
  return true;
}
