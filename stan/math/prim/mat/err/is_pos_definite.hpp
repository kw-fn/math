#ifndef STAN_MATH_PRIM_MAT_ERR_IS_POS_DEFINITE_HPP
#define STAN_MATH_PRIM_MAT_ERR_IS_POS_DEFINITE_HPP

#include <stan/math/prim/mat/meta/get.hpp>
#include <stan/math/prim/mat/meta/length.hpp>
#include <stan/math/prim/mat/meta/is_vector.hpp>
#include <stan/math/prim/mat/meta/is_vector_like.hpp>
#include <stan/math/prim/scal/err/is_positive_size.hpp>
#include <stan/math/prim/scal/err/is_not_nan.hpp>
#include <stan/math/prim/scal/err/domain_error.hpp>

#include <stan/math/prim/mat/err/check_symmetric.hpp>
#include <stan/math/prim/mat/err/constraint_tolerance.hpp>

#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/mat/fun/value_of_rec.hpp>

namespace stan {
namespace math {

/**
 * Check if the specified square, symmetric
 * matrix is positive definite.
 *
 * @tparam T_y Type of scalar of the matrix
 *
 * @param y Matrix to test
 *
 * @return <code>true</code> if the matrix is square or if
 * the matrix has non-0 size, or if the matrix is symmetric,
 * or if it is positive definite, or if no element is <code>NaN</code>
 */
