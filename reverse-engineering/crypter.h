#ifndef CRYPTER_H
#define CRYPTER_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Crypter {
public:
  bool verify(std::string userIn, std::string passIn);

private:
  void encode();
  void decode();
  std::string encrypt(std::string str);
  std::string decrypt(std::string str);
};

#endif
