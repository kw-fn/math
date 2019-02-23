#ifndef STAN_MATH_PRIM_MAT_ERR_IS_CORR_MATRIX_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_CORR_MATRIX_HPP

#include <stan/math/prim/scal/err/is_positive_size.hpp>
#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/mat/meta/index_type.hpp>
#include <stan/math/prim/scal/meta/error_index.hpp>

#include <stan/math/prim/mat/err/is_pos_definite.hpp>
#include <stan/math/prim/mat/err/is_symmetric.hpp>
#include <stan/math/prim/scal/err/is_size_match.hpp>
#include <stan/math/prim/mat/err/is_constraint_tolerance.hpp>

namespace stan {
namespace math {

/**
 * Check if the specified matrix is a valid
 * correlation matrix.
 *
 * A valid correlation matrix is symmetric, has a unit diagonal
 * (all 1 values), and has all values between -1 and 1 (inclusive).
 *
 * This function throws exceptions if the variable is not a valid
 * correlation matrix.
 *
 * @param y Matrix to test
 *
 * @return <code>true</code> if the matrix is square and not 0x0,
 *   if the matrix is symmetric, diagonals are near 1, positive definite,
 *   and no elements are NaN.
 */
#endif
