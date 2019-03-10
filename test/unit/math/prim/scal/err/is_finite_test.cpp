#include <stan/math/prim/scal.hpp>
#include <gtest/gtest.h>
#include <limits>

using stan::math::is_finite;

TEST(ErrorHandlingScalar, isFinite) {
  double x = 0;
  EXPECT_TRUE(is_finite(x));
  
  x = std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_finite(x));
  
  x = -std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_finite(x));

  x = std::numeric_limits<double>::quiet_NaN();
  EXPECT_FALSE(is_finite(x));
}

TEST(ErrorHandlingScalar, isFinite_nan) {
  double nan = std::numeric_limits<double>::quiet_NaN();
  EXPECT_FALSE(is_finite(nan));
}
