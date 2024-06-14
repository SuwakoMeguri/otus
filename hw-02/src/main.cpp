#include <iostream>
#include "ip_filter.h"

auto main(int argc, char **argv) -> int {
  auto ip_addresses = getIPAddresses(std::cin);

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
