#include <stan/math/prim/mat.hpp>
#include <gtest/gtest.h>
#include <limits>
#include <vector>

TEST(ErrorHandlingMatrix, isMatchingSizesMatrix) {
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> y;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x;

  y.resize(3, 3);
  x.resize(3, 3);
  EXPECT_TRUE(stan::math::is_matching_sizes(x, y));
  
  x.resize(0, 0);
  y.resize(0, 0);
  EXPECT_TRUE(stan::math::is_matching_sizes(x, y));

  y.resize(1, 2);

  EXPECT_FALSE(stan::math::is_matching_sizes(x, y));

  x.resize(2, 1);
  EXPECT_TRUE(stan::math::is_matching_sizes(x, y));

  std::vector<double> a;
  std::vector<double> b;
  x.resize(0, 0);

  EXPECT_TRUE(stan::math::is_matching_sizes(a, b));
  EXPECT_TRUE(stan::math::is_matching_sizes(x, b));
  EXPECT_TRUE(stan::math::is_matching_sizes(a, x));
  EXPECT_FALSE(stan::math::is_matching_sizes(a, y));

  a.push_back(3.0);
  a.push_back(3.0);

  EXPECT_FALSE(stan::math::is_matching_sizes(a, b));

  b.push_back(3.0);
  b.push_back(3.0);
  x.resize(2, 1);

  EXPECT_TRUE(stan::math::is_matching_sizes(a, b));
  EXPECT_TRUE(stan::math::is_matching_sizes(x, b));
}

TEST(ErrorHandlingMatrix, isMatchingSizesMatrix_nan) {
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> y;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x;
  double nan = std::numeric_limits<double>::quiet_NaN();

  y.resize(3, 3);
  x.resize(3, 3);
  y << nan, nan, nan, nan, nan, nan, nan, nan, nan;
  x << nan, nan, nan, nan, nan, nan, nan, nan, nan;
  EXPECT_TRUE(stan::math::is_matching_sizes(x, y));
  x.resize(0, 0);
  y.resize(0, 0);
  EXPECT_TRUE(stan::math::is_matching_sizes(x, y));

  y.resize(1, 2);
  y << nan, nan;
  EXPECT_FALSE(stan::math::is_matching_sizes(x, y));

  x.resize(2, 1);
  x << nan, nan;
  EXPECT_TRUE(stan::math::is_matching_sizes(x, y));

  std::vector<double> a;
  std::vector<double> b;
  x.resize(0, 0);
  EXPECT_TRUE(stan::math::is_matching_sizes(a, b));
  EXPECT_TRUE(stan::math::is_matching_sizes(x, b));
  EXPECT_TRUE(stan::math::is_matching_sizes(a, x));
  EXPECT_FALSE(stan::math::is_matching_sizes(a, y));

  a.push_back(nan);
  a.push_back(nan);
  EXPECT_FALSE(stan::math::is_matching_sizes(a, b));

  b.push_back(nan);
  b.push_back(nan);
  x.resize(2, 1);
  x << nan, nan;
  EXPECT_TRUE(stan::math::is_matching_sizes(a, b));
  EXPECT_TRUE(stan::math::is_matching_sizes(x, b));
}
