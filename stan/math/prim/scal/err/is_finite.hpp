#ifndef STAN_MATH_PRIM_SCAL_ERR_CHECK_FINITE_HPP
#define STAN_MATH_PRIM_SCAL_ERR_CHECK_FINITE_HPP

#include <stan/math/prim/scal/meta/length.hpp>
#include <stan/math/prim/scal/meta/is_vector_like.hpp>
#include <stan/math/prim/scal/fun/value_of_rec.hpp>
#include <boost/math/special_functions/fpclassify.hpp>

namespace stan {
namespace math {

namespace {
template <typename T_y, bool is_vec>
struct finite {
  static bool check(const T_y& y) {
    if (!(boost::math::isfinite)(value_of_rec(y)))
      return false;
    return true;
  }
};

template <typename T_y>
struct finite<T_y, true> {
  static bool check(const T_y& y) {
    using stan::length;
    for (size_t n = 0; n < length(y); ++n) {
      if (!(boost::math::isfinite)(value_of_rec(stan::get(y, n))))
        return false;
      return true;
    }
  }
};
}  // namespace

/**
 * Check if <code>y</code> is finite.
 *
 * This function is vectorized and will check each element of
 * <code>y</code>.
 *
 * @tparam T_y Type of y
 *
 * @param y Variable to check
 *
 * @throw <code>true</code> if y is not infinity, -infinity, or NaN
 */
template <typename T_y>
inline bool check_finite(const T_y& y) {
  return finite<T_y, is_vector_like<T_y>::value>::check(y);
}
}  // namespace math
}  // namespace stan
#endif
