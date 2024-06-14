#include <algorithm>
#include <arpa/inet.h>
#include <array>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <istream>
#include <iterator>
#include <string>
#include <vector>

std::vector<std::array<uint8_t, 4>> getIPAddresses(std::istream &stream) {
  std::vector<std::array<uint8_t, 4>> IPAddresses;

  for (std::string line; std::getline(stream, line);) {
    std::array<uint8_t, 4> ipAddress = {0, 0, 0, 0};
    int j = 0;
    uint8_t currentOctet = 0;

    for (char c : line) {
      if (c == '\t') {
        break;
      }
      if (c == '.') {
        ipAddress[j++] = currentOctet;
        currentOctet = 0;
      } else {
        currentOctet = currentOctet * 10 + (c - '0');
      }
    }
    ipAddress[j] = currentOctet;
    IPAddresses.push_back(ipAddress);
  }
  std::sort(IPAddresses.begin(),IPAddresses.end(),
            [](auto first, auto second) { return second < first; });
  return IPAddresses;
}

void printSelected(std::vector<std::array<uint8_t, 4>> &ip_addresses,
                   bool (*meetCondition)(std::array<uint8_t, 4>)) {
  for (auto ip_address : ip_addresses) {
    if (meetCondition(ip_address)) {
      std::cout << static_cast<int>(ip_address[0]) << "."
                << static_cast<int>(ip_address[1]) << "."
                << static_cast<int>(ip_address[2]) << "."
                << static_cast<int>(ip_address[3]) << "\n";
    }
  }
}
