#ifndef CRYPTER_H
#define CRYPTER_H
#include <fstream>
#include <iostream>
#include <string>

class Crypter {
public:
  bool verify(std::string userIn, std::string passIn);

private:
  bool encode();
  bool decode();
};

#endif
