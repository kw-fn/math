#ifndef STAN_MATH_PRIM_SCAL_ERR_CHECK_IS_POSITIVE_SIZE_HPP
#define STAN_MATH_PRIM_SCAL_ERR_CHECK_IS_POSITIVE_SIZE_HPP

namespace stan {
namespace math {

/**
 * Check if <code>size</code> is positive.
 * @param function Function name (for error messages)
 * @param name Variable name (for error messages)
 * @param expr Expression for the dimension size (for error messages)
 * @param size Size value to check
 * @return <code>true</code> if <code>size</code> is not zero or negative.
 */
inline bool is_positive_size(int& size) {
  return size >= 0;
}

} // namespace math
} // namespace stan
#endif
