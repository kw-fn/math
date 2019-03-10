#include <stan/math/prim/scal.hpp>
#include <gtest/gtest.h>
#include <limits>

TEST(ErrorHandlingScalar, isPositive) {
  using stan::math::check_positive;
  EXPECT_TRUE(check_positive(3.0));
}

TEST(ErrorHandlingScalar, isPositive_nan) {
  using stan::math::check_positive;
  double nan = std::numeric_limits<double>::quiet_NaN();
  EXPECT_FALSE(check_positive(nan));
}
