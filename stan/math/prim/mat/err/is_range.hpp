#ifndef STAN_MATH_PRIM_MAT_ERR_IS_RANGE_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_RANGE_HPP

#include <stan/math/prim/scal/err/is_out_of_range.hpp>
#include <stan/math/prim/mat/meta/index_type.hpp>
#include <stan/math/prim/scal/meta/error_index.hpp>

namespace stan {
namespace math {

/**
 * Return <code>true</code> if specified index is within range.
 *
 * This check is 1-indexed by default. This behavior can be
 * changed by setting <code>stan::error_index::value</code>.
 *
 * @param max Maximum size of the variable
 * @param index Index to check
 *
 * @true <code>true</code> if the index is in range
 */
inline bool is_range(int max, int index) {
  if ((index >= stan::error_index::value)
      && (index < max + stan::error_index::value))
    return true;
  return false;
}

/**
 * Return <code>true</code> if specified index is within range.
 *
 * This check is 1-indexed by default. This behavior can be
 * changed by setting <code>stan::error_index::value</code>.
 *
 * @param max Maximum size of the variable
 * @param index Index to check
 *
 * @return <code>true</code> if the index is in range
 */
inline bool is_range(int max, int index) {
  if ((index >= stan::error_index::value)
      && (index < max + stan::error_index::value))
    return true;
  return is_out_of_range(max, index);
}

/**
 * Return <code>true</code> if specified index is within range.
 *
 * This check is 1-indexed by default. This behavior can be
 * changed by setting <code>stan::error_index::value</code>.
 *
 * @param max Maximum size of the variable
 * @param index Index to check
 *
 * @return <code>true</code> if the index is in range
 */
inline bool is_range(int max, int index) {
  if ((index >= stan::error_index::value)
      && (index < max + stan::error_index::value))
    return true;
  return is_out_of_range(max, index);
}

}  // namespace math
}  // namespace stan
#endif
