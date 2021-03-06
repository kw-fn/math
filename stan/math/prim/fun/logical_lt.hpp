#ifndef STAN_MATH_PRIM_FUN_LOGICAL_LT_HPP
#define STAN_MATH_PRIM_FUN_LOGICAL_LT_HPP

namespace stan {
namespace math {

/**
 * Return 1 if the first argument is strictly less than the second.
 * Equivalent to <code>x1 &lt; x2</code>.
 *
 * @tparam T1 type of first argument
 * @tparam T2 type of second argument
 * @param x1 first argument
 * @param x2 second argument
 * @return <code>true</code> if <code>x1 &lt; x2</code>
 */
template <typename T1, typename T2>
inline bool logical_lt(T1 x1, T2 x2) {
  return x1 < x2;
}

}  // namespace math
}  // namespace stan

#endif
