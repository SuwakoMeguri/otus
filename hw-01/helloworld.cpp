#include <iostream>
#include <sstream>
#include <ctype.h>

int main (int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Should be only 1 arg`";
    return -1;
  }

  std::istringstream ss(argv[1]);
  int x;
  if (!(ss >> x)) {
    std::cerr << "Invalid number: " << argv[1] << '\n';
  } else if (!ss.eof()) {
    std::cerr << "Trailing characters after number: " << argv[1] << '\n';
  }
  std::cout << "Version: " << x << '\n';
  std::cout << "Hello, World!";
  return 0;
}
