#include <stan/math/prim/mat.hpp>
#include <gtest/gtest.h>
#include <limits>

TEST(ErrorHandlingScalar, isPositive) {
  using stan::math::is_positive;

  Eigen::Matrix<double, Eigen::Dynamic, 1> x_mat(3);
  x_mat << 1, 2, 3;
  for (int i = 0; i < x_mat.size(); i++) {
    EXPECT_TRUE(is_positive(x_mat));
  }

  x_mat(0) = 0;
  EXPECT_FALSE(is_positive(x_mat));
}

TEST(ErrorHandlingScalar, isPositive_nan) {
  using stan::math::is_positive;

  double nan = std::numeric_limits<double>::quiet_NaN();

  Eigen::Matrix<double, Eigen::Dynamic, 1> x_mat(3);
  x_mat << 1, 2, 3;
  for (int i = 0; i < x_mat.size(); i++) {
    x_mat(i) = nan;
    EXPECT_FALSE(is_positive(x_mat));
    x_mat(i) = i;
  }
}
