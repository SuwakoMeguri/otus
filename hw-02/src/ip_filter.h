#include <array>
#include <cstdint>
#include <strstream>
#include <algorithm>
#include <arpa/inet.h>
#include <vector>

void printSelected(std::vector<std::array<uint8_t, 4>> &ip_addresses,
                   bool (*meetCondition)(std::array<uint8_t, 4>));
std::vector<std::array<uint8_t, 4>> getIPAddresses(std::istream &stream);
