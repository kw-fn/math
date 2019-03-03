#include <stan/math/prim/mat.hpp>
#include <gtest/gtest.h>
#include <limits>
#include <string>

using stan::math::is_positive_finite;

TEST(ErrorHandlingScalar, isPositiveFinite_Matrix) {
  Eigen::Matrix<double, Eigen::Dynamic, 1> x;

  x.resize(3);
  x << 3, 2, 1;
  ASSERT_TRUE(is_positive_finite(x));

  x.resize(3);
  x << 2, 1, std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_positive_finite(x)Inf";

  x.resize(3);
  x << 0, 1, std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_positive_finite(x));

  x.resize(3);
  x << -1, 1, std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_positive_finite(x));

  x.resize(3);
  x << 2, 1, -std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_positive_finite(x));

  x.resize(3);
  x << 1, 2, std::numeric_limits<double>::quiet_NaN();
  EXPECT_FALSE(is_positive_finite(x));
}

TEST(ErrorHandlingScalar, isPositiveFinite_Matrix_one_indexed_message) {
  Eigen::Matrix<double, Eigen::Dynamic, 1> x;

  x.resize(3);
  x << 1, 2, std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_positive_finite(x));
  
  x.resize(3);
  x << -1, 2, std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_positive_finite(x));
  
  x.resize(3);
  x << 1, 0, std::numeric_limits<double>::infinity();
  EXPECT_FALSE(is_positive_finite(x));
}

TEST(ErrorHandlingScalar, isPositiveFinite_nan) {
  double nan = std::numeric_limits<double>::quiet_NaN();

  Eigen::Matrix<double, Eigen::Dynamic, 1> x_mat(3);
  x_mat << 1, 2, 3;
  for (int i = 0; i < x_mat.size(); i++) {
    x_mat(i) = nan;
    EXPECT_FALSE(is_positive_finite(x_mat));
    x_mat(i) = i;
  }
}
