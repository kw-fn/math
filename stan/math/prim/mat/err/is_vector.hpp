#ifndef STAN_MATH_PRIM_MAT_ERR_IS_MAT_VECTOR_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_MAT_VECTOR_HPP

#include <stan/math/prim/mat/fun/Eigen.hpp>

namespace stan {
namespace math {

/**
 * Return <code>true</code> if the matrix is either a row vector or
 * column vector. This function checks whether the runtime size of
 * the matrix to check is a row or column vector.
 * @tparam T Scalar type of the matrix
 * @tparam R Compile time rows of the matrix
 * @tparam C Compile time columns of the matrix
 * @param x Matrix to test, requires class method <code>.rows()</code>
 *   and <code>.cols()</code>
 * @return <code>true</code> if x is a row or column vector
 */
template <typename T, int R, int C>
inline bool is_mat_vector(const Eigen::Matrix<T, R, C>& x) {
  return R == 1 || C == 1 || x.rows() == 1 || x.cols() == 1;
}

}  // namespace math
}  // namespace stan
#endif
