#include <stan/math/prim/scal.hpp>
#include <gtest/gtest.h>
#include <test/unit/util.hpp>
#include <string>

TEST(ErrorHandlingScalar, isPositiveSize) {
  using stan::math::check_positive_size;

  EXPECT_TRUE(check_positive_size(10));

  EXPECT_FALSE(check_positive_size(0));

  EXPECT_FALSE(check_positive_size(-1));
}
