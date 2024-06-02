#include <array>
#include <cstdint>
#include <strstream>

std::array<std::array<uint8_t, 4>, 1000> getIPAddresses(std::istream &stream);
void printSelected(std::array<std::array<uint8_t, 4>, 1000> &ip_addresses,
                   bool (*meetCondition)(std::array<uint8_t, 4>));
