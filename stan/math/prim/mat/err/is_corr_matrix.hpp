#ifndef STAN_MATH_PRIM_MAT_ERR_IS_CORR_MATRIX_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_CORR_MATRIX_HPP

#include <stan/math/prim/scal/err/is_positive_size.hpp>
#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/mat/meta/index_type.hpp>
#include <stan/math/prim/scal/meta/error_index.hpp>
#include <stan/math/prim/mat/err/is_pos_definite.hpp>
#include <stan/math/prim/mat/err/is_symmetric.hpp>
#include <stan/math/prim/scal/err/is_size_match.hpp>
#include <stan/math/prim/mat/err/constraint_tolerance.hpp>

namespace stan {
namespace math {

/**
 * Check if the specified matrix is a valid correlation matrix.
 *
 * A valid correlation matrix is symmetric, has a unit diagonal
 * (all 1 values), and has all values between -1 and 1 (inclusive).
 *
 * This function throws exceptions if the variable is not a valid
 * correlation matrix.
 *
 * @tparam T_y Eigen::Matrix
 *
 * @param y Matrix to test
 *
 * @return <code>true</code> if the matrix is square and not 0x0,
 *   if the matrix is symmetric, diagonals are near 1, positive definite,
 *   and no elements are NaN.
 */
template <typename T_y>
inline bool is_corr_matrix(
             const Eigen::Matrix<T_y, Eigen::Dynamic, Eigen::Dynamic>& y) {
  using Eigen::Matrix;

  typedef
      typename index_type<Matrix<T_y, Eigen::Dynamic, Eigen::Dynamic> >::type
          size_t;

  if (is_size_match(y.rows(), y.cols())) {
      if (is_positive_size(y.rows()) {
          if (is_symmetric(y)) {
            for (size_t k = 0; k < y.rows(); ++k) {
              if (!(fabs(y(k, k) - 1.0) <= CONSTRAINT_TOLERANCE))
                return false;
            }
          }
        }
      }
  return check_pos_definite(y);
}

}  // namespace math
}  // namespace stan
#endif
