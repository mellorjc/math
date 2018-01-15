#ifndef STAN_MATH_PRIM_SCAL_PROB_BERNOULLI_CLOGLOG_RNG_HPP
#define STAN_MATH_PRIM_SCAL_PROB_BERNOULLI_CLOGLOG_RNG_HPP

#include <boost/random/bernoulli_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <stan/math/prim/scal/err/check_consistent_sizes.hpp>
#include <stan/math/prim/scal/err/check_bounded.hpp>
#include <stan/math/prim/scal/err/check_finite.hpp>
#include <stan/math/prim/scal/err/check_not_nan.hpp>
#include <stan/math/prim/scal/fun/constants.hpp>
#include <stan/math/prim/scal/fun/inv_cloglog.hpp>
#include <stan/math/prim/scal/fun/log1m.hpp>
#include <stan/math/prim/scal/fun/value_of.hpp>
#include <stan/math/prim/scal/meta/include_summand.hpp>

namespace stan {
namespace math {

/**
 * A Bernoulli random number generator which takes as its argument the
 * often more convenient cloglog-parametrization.
 *
 * @tparam RNG Random number generator type.
 * @param t cloglog-transformed probability parameter.
 * @param rng pseudorandom number generator.
 * @return Bernoulli(cloglog^{-1}(t)) generated random number, either 0 or 1.
 */
template <class RNG>
inline int bernoulli_cloglog_rng(double t, RNG& rng) {
  using boost::variate_generator;
  using boost::bernoulli_distribution;
  using stan::math::inv_cloglog;

  check_finite("bernoulli_cloglog_rng", "Complementary log-log transformed probability parameter",
               t);

  variate_generator<RNG&, bernoulli_distribution<> > bernoulli_rng(
      rng, bernoulli_distribution<>(inv_cloglog(t)));
  return bernoulli_rng();
}

}  // namespace math
}  // namespace stan
#endif
