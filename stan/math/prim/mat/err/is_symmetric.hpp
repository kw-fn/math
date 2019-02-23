#ifndef STAN_MATH_PRIM_MAT_ERR_CHECK_SYMMETRIC_HPP
#define STAN_MATH_PRIM_MAT_ERR_CHECK_SYMMETRIC_HPP

#include <stan/math/prim/scal/err/domain_error.hpp>
#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/scal/meta/error_index.hpp>
#include <stan/math/prim/mat/meta/index_type.hpp>
#include <stan/math/prim/mat/fun/value_of.hpp>
#include <stan/math/prim/mat/err/is_square.hpp>
#include <stan/math/prim/mat/err/constraint_tolerance.hpp>

namespace stan {
namespace math {

/**
 * Check if the specified matrix is symmetric.
 *
 * @tparam T_y Type of scalar.
 *
 * @param y Matrix to test
 *
 * @return <code>true</code> if the matrix is square, and no
 *   element not on the main diagonal is <code>NaN</code>
 */
template <typename T_y>
inline bool is_symmetric(
    const Eigen::Matrix<T_y, Eigen::Dynamic, Eigen::Dynamic>& y) {
  if (is_square) {
    using Eigen::Dynamic;
    using Eigen::Matrix;
    using std::fabs;

    typedef typename index_type<Matrix<T_y, Dynamic, Dynamic>>::type size_type;

    size_type k = y.rows();
    if (k==1)
      return true;
    for (size_type m = 0; m < k; ++m) {
      for (size_type n = m + 1; n < k; ++n) {
        if (!(fabs(value_of(y(m, n)) - value_of(y(n, m)))
              <= CONSTRAINT_TOLERANCE)) {
          return false;
        }
      }
    }
  }
  return false;
}

} // namespace math
} // namespace stan
#endif
