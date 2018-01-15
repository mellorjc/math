#include <stan/math/prim/scal.hpp>
#include <gtest/gtest.h>

TEST(ProbBernoulliCLogLog, log_matches_lpmf) {
  int n = 1;
  double theta = 1.2;

  EXPECT_FLOAT_EQ((stan::math::bernoulli_cloglog_lpmf(n, theta)),
                  (stan::math::bernoulli_cloglog_log(n, theta)));
  EXPECT_FLOAT_EQ((stan::math::bernoulli_cloglog_lpmf<true>(n, theta)),
                  (stan::math::bernoulli_cloglog_log<true>(n, theta)));
  EXPECT_FLOAT_EQ((stan::math::bernoulli_cloglog_lpmf<false>(n, theta)),
                  (stan::math::bernoulli_cloglog_log<false>(n, theta)));
  EXPECT_FLOAT_EQ((stan::math::bernoulli_cloglog_lpmf<true, double>(n, theta)),
                  (stan::math::bernoulli_cloglog_log<true, double>(n, theta)));
  EXPECT_FLOAT_EQ((stan::math::bernoulli_cloglog_lpmf<false, double>(n, theta)),
                  (stan::math::bernoulli_cloglog_log<false, double>(n, theta)));
  EXPECT_FLOAT_EQ((stan::math::bernoulli_cloglog_lpmf<double>(n, theta)),
                  (stan::math::bernoulli_cloglog_log<double>(n, theta)));
}
