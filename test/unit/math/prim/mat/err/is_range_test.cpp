#include <stan/math/prim/mat.hpp>
#include <gtest/gtest.h>
#include <test/unit/util.hpp>
#include <string>
#include <vector>

TEST(ErrorHandlingMatrix, isRange_6_arg_std_vector) {
  using stan::math::is_range;
  std::vector<double> x;

  x.resize(4);

  EXPECT_TRUE(is_range(4, 1, 4));
  EXPECT_TRUE(is_range(4, 2, 4));
  EXPECT_TRUE(is_range(4, 3, 4));
  EXPECT_TRUE(is_range(4, 4, 4));
  EXPECT_FALSE(is_range(4, 12, 4));
}

TEST(ErrorHandlingMatrix, isRange_4_arg_std_vector) {
  using stan::math::is_range;
  std::vector<double> x;

  x.resize(4);

  EXPECT_TRUE(is_range(4, 1));
  EXPECT_TRUE(is_range(4, 2));
  EXPECT_TRUE(is_range(4, 3));
  EXPECT_TRUE(is_range(4, 4));
  EXPECT_FALSE(is_range(4, 12);
}
