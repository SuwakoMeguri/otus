#include <gtest/gtest.h>
#include "ip_filter.h"
#include <sstream>

TEST(TestName, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);

  std::istringstream ss("0.0.0.0\t\n1.1.1.1");

  auto result = getIPAddresses(ss);
  EXPECT_EQ(result[0][0], "1");
  EXPECT_EQ(result[1][0], "0");
}
