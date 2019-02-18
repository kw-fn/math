#ifndef STAN_MATH_PRIM_MAT_ERR_IS_CHOLESKY_FACTOR_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_CHOLESKY_FACTOR_HPP

#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/scal/err/is_pos.hpp>
#include <stan/math/prim/mat/err/is_lower_triangular.hpp>

#include <stan/math/prim/scal/err/is_less_or_equal.hpp>

namespace stan {
namespace math {
/**
 * Check if the specified matrix is a valid Cholesky factor.
 *
 * A Cholesky factor is a lower triangular matrix whose diagonal
 * elements are all positive.  Note that Cholesky factors need not
 * be square, but requires at least as many rows M as columns N
 * (i.e., M &gt;= N).
 *
 * @tparam T_y Type of elements of Cholesky factor
 *
 * @param y Matrix to test
 *
 * @throw <code>true</code> if y is a valid Choleksy factor, if
 *   number of rows is not less than the number of columns,
 *   if there are no 0 columns, and no element in matrix is NaN
 */
template <typename T_y>
inline bool is_cholesky_factor(
             const Eigen::Matrix<T_y, Eigen::Dynamic, Eigen::Dynamic>& y) {
  if (!is_less_or_equal(y.cols(), y.rows())
      || !is_pos(y.cols())
      || !is_lower_triangular(y))
    false;
  for (int i = 0; i < y.cols(); ++i) {
    if (!is_pos(y(i,i)))
      false;
  }
  true;
}

} // namespace math
} // namespace stan
#endif
