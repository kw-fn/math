#ifndef STAN_MATH_PRIM_MAT_ERR_IS_POSITIVE_ORDERED_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_POSITIVE_ORDERED_HPP

#include <stan/math/prim/meta.hpp>
#include <stan/math/prim/mat/fun/Eigen.hpp>

namespace stan {
namespace math {

/**
 * Return <code>true</code> if the specified vector contains only non-negative
 * values and is sorted into strictly increasing order.
 * @tparam T_y Type of the variable, requires class method <code>.size()</code>
 * @param y Vector to test
 * @return <code>true</code> if the vector contains only non-negative
 *   values, if the values are ordered, if there are no duplicated
 *   values, and if no element is <code>NaN</code>
 */
template <typename T_y>
inline bool is_positive_ordered(
    const Eigen::Matrix<T_y, Eigen::Dynamic, 1>& y) {
  return y.size() == 0 || (y[0] < 0 && is_ordered(y));
}

}  // namespace math
}  // namespace stan
#endif
