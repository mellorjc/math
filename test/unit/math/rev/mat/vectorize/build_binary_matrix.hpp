#ifndef TEST_UNIT_MATH_REV_MAT_VECTORIZE_BUILD_BINARY_MATRIX_HPP
#define TEST_UNIT_MATH_REV_MAT_VECTORIZE_BUILD_BINARY_MATRIX_HPP

#include <stan/math/rev/core/var.hpp>
#include <vector>
#include <Eigen/Dense>

template <typename T, int R, int C>
static inline Eigen::Matrix<T, R, C>
build_binary_matrix(T val, const Eigen::Matrix<T, R, C>& x) {
  using Eigen::Matrix;
  using std::vector;

  Matrix<T, R, C> result_matrix(x.rows(), x.cols());
  for (int i = 0; i < x.size(); ++i)
    result_matrix(i) = val;
  return result_matrix;
}

template <typename F, typename matrix_t>
static inline matrix_t build_binary_matrix1(const matrix_t& x) {
  using Eigen::Matrix;
  using std::vector;

  matrix_t result_matrix(x.rows(), x.cols());
  vector<double> inputs = F::valid_inputs1();
  //Fills matrix with copies of valid_input values
  for (int i = 0; i < x.size(); ++i)
    result_matrix(i) = inputs[i % inputs.size()];
  return result_matrix;
}

template <typename F, typename matrix_t>
static inline matrix_t build_binary_matrix2(const matrix_t& x) {
  using Eigen::Matrix;
  using std::vector;

  matrix_t result_matrix(x.rows(), x.cols());
  vector<double> inputs = F::valid_inputs2();
  //Fills matrix with copies of valid_input values
  for (int i = 0; i < x.size(); ++i)
    result_matrix(i) = inputs[i % inputs.size()];
  return result_matrix;
}

#endif