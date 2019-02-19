#ifndef STAN_MATH_PRIM_MAT_ERR_IS_COL_INDEX_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_COL_INDEX_HPP

#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/scal/meta/error_index.hpp>

namespace stan {
namespace math {

/**
 * Check if the specified index is a valid column of the matrix.
 *
 * By default this is a 1-indexed check (as opposed to
 * 0-indexed). Behavior can be changed by setting
 * <code>stan::error_index::value</code>. This function will
 * throw an <code>std::out_of_range</code> exception if
 * the index is out of bounds.
 *
 * @tparam T_y Type of scalar
 * @tparam R Number of rows of the matrix
 * @tparam C Number of columns of the matrix
 *
 * @param y Matrix
 * @param i Index to check
 *
 * @return <code>true</code> no index is invalid column
 */
template <typename T_y, int R, int C>
inline bool is_col_index(const Eigen::Matrix<T_y, R, C>& y,
                         size_t i) {
  if (i >= stan::error_index::value
      && i < static_cast<size_t>(y.cols()) + stan::error_index::value)
    return true;
  return false;
}

} // namespace math
} // namespace stan
#endif
