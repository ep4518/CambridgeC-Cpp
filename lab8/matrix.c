#include "matrix.h"
#include <stdbool.h>

matrix_t matrix_create(int rows, int cols) { 
  /* TODO */
  // matrix_t m = {rows, cols, NULL};
  matrix_t m;
  m.rows = rows;
  m.cols = cols;
  m.elts = (double*) malloc(rows * cols * sizeof(double));
  return m;
}

double matrix_get(matrix_t m, int r, int c) { 
  /* TODO */
  assert(r < m.rows && c < m.cols);
  int idx = m.cols * r + c;
  return m.elts[idx];
}

void matrix_set(matrix_t m, int r, int c, double d) { 
  assert(r < m.rows && c < m.cols);
  /* TODO */
  int idx = m.cols * r + c;
  m.elts[idx] = d;
  return;
}


void matrix_free(matrix_t m) { 
  /* TODO */
  free(m.elts);
  return;
}

matrix_t matrix_multiply(matrix_t m1, matrix_t m2) { 
  /* TODO */
  matrix_t m = matrix_create(m1.rows, m2.cols);
  for (int i = 0; i < m1.rows; i++) {
    for (int k = 0; k < m2.cols; k++) {
      double sum = 0.0;
      for (int j = 0; j < m1.cols; j++) {
        sum += m1.elts[i * m1.cols + j] * m2.elts[j * m2.cols + k];
      }
      m.elts[i * m.cols + k] = sum;
    }
  }
  return m;
}

matrix_t matrix_transpose(matrix_t m) { 
  /* TODO */
  matrix_t t = matrix_create(m.cols, m.rows);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      t.elts[j * t.cols + i] = m.elts[i * m.cols + j];
    }
  }
  return t;
}

matrix_t matrix_multiply_transposed(matrix_t m1, matrix_t m2) { 
  assert(m1.cols == m2.cols);
  /* TODO */
  return matrix_multiply(m1, matrix_transpose(m2));
}

matrix_t matrix_multiply_fast(matrix_t m1, matrix_t m2) { 
  /* TODO */
  matrix_t m2t = matrix_transpose(m2);
  matrix_t m = matrix_create(m1.rows, m2.cols);
  for (int i = 0; i < m1.rows; i++) {
    for (int k = 0; k < m2.rows; k++) {
      double sum = 0.0;
      for (int j = 0; j < m1.cols; j++) {
        sum += m1.elts[i * m1.cols + j] * m2.elts[j * m2.cols + k];
      }
      m.elts[i * m.cols + k] = sum;
    }
  }
  matrix_free(m2t);
  return m;
}

void matrix_print(matrix_t m) { 
  for (int i = 0; i < m.rows; i++) { 
    for (int j = 0; j < m.cols; j++) { 
      printf("%g\t", matrix_get(m, i, j));
    }
    printf("\n");
  }
  printf("\n");
}


