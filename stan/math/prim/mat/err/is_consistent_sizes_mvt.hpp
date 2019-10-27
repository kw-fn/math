#ifndef STAN_MATH_PRIM_MAT_ERR_IS_CONSISTENT_SIZES_MVT_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_CONSISTENT_SIZES_MVT_HPP

#include <stan/math/prim/meta.hpp>
#include <algorithm>

namespace stan {
namespace math {

/**
 * Check if the dimension of `x1` is consistent with `x2`.
 * Consistent size is defined as having the same size if vector of
 * vectors or being a single vector.
 * @tparam T1 Type of `x1`
 * @tparam T2 Type of `x2`
 * @param x1 Variable to check for consistent size
 * @param x2 Variable to check for consistent size
 * @return <code>true</code> if sizes are consistent
 */
template <typename T1, typename T2>
inline bool is_consistent_sizes_mvt(const T1& x1, const T2& x2) {
  return length_mvt(x1) > length_mvt(x2)
             ? is_consistent_size_mvt(x2, length_mvt(x1))
             : is_consistent_size_mvt(x1, length_mvt(x2));
}

}  // namespace math
}  // namespace stan
#endif
