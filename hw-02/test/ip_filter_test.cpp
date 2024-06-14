#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ip_filter.h"
#include <sstream>

using ::testing::ElementsAre;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

TEST(ParsingTest, BasicAssertions) {
  std::string input = "200.235.23.35\tSJDFLKSDJLFKJSD\n192.168.0.1\tSJDFKSJD\n0.0.0.0\tTESTST\n";

  std::istringstream testStream(input);

  auto result = getIPAddresses(testStream);

  ASSERT_EQ(result.size(), 3);
  EXPECT_THAT(result[0], ElementsAre(200, 235, 23, 35));
  EXPECT_THAT(result[1], ElementsAre(192, 168, 0, 1));
  EXPECT_THAT(result[2], ElementsAre(0, 0, 0, 0));

}

TEST(SortTest, BasicAssertions) {
  std::string input = "0.0.0.0\tTESTST\n192.168.0.1\tSJDFKSJD\n";

  std::istringstream testStream(input);

  auto result = getIPAddresses(testStream);

  ASSERT_EQ(result.size(), 2);
  EXPECT_THAT(result[0], ElementsAre(192, 168, 0, 1));
  EXPECT_THAT(result[1], ElementsAre(0, 0, 0, 0));

}
