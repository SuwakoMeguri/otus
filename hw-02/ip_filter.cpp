#include <algorithm>
#include <arpa/inet.h>
#include <array>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

std::array<std::array<uint8_t, 4>, 1000> getIPAddresses() {
  std::array<std::array<uint8_t, 4>, 1000> IPAddresses;

  int i = 0;
  for (std::string line; std::getline(std::cin, line); i++) {
    int j = 0;
    uint8_t currentOctet = 0;

    for (char c : line) {
      if (c == '\t') {
        break;
      }
      if (c == '.') {
        IPAddresses[i][j++] = currentOctet;
        currentOctet = 0;
      } else {
        currentOctet = currentOctet * 10 + (c - '0');
      }
    }
    IPAddresses[i][j] = currentOctet;
    currentOctet = 0;
  }
  std::sort(IPAddresses.begin(), IPAddresses.end(),
            [](auto first, auto second) { return second < first; });
  return IPAddresses;
}

void printSelected(std::array<std::array<uint8_t, 4>, 1000> &ip_addresses,
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

int main() {
  auto ip_addresses = getIPAddresses();

  auto withoutFilter = [](std::array<uint8_t, 4> val) { return true; };
  auto startsWith1 = [](std::array<uint8_t, 4> val) { return val[0] == 1; };
  auto startsWith4670 = [](std::array<uint8_t, 4> val) {
    return val[0] == 46 && val[1] == 70;
  };
  auto containing46 = [](std::array<uint8_t, 4> val) {
    return std::find(val.begin(), val.end(), 46) != std::end(val);
  };

  printSelected(ip_addresses, withoutFilter);
  printSelected(ip_addresses, startsWith1);
  printSelected(ip_addresses, startsWith4670);
  printSelected(ip_addresses, containing46);

  return 0;
}
