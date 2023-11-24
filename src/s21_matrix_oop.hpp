#ifndef SRC_S21_MATRIX_OPP_H_
#define SRC_S21_MATRIX_OPP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  int getRows() noexcept;  // getters
  int getCols() noexcept;
  double** getMatrix() noexcept;
  void setRows(int rows);  // setters
  void setColumns(int cols);

  // Constructors
  S21Matrix() noexcept;  // Default constructor
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix& other) noexcept;
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix() noexcept;  // Destructor

  // Other methods..
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators
  S21Matrix& operator=(const S21Matrix& other) noexcept;  // equal
  bool operator==(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) noexcept;  // addition
  S21Matrix operator+=(const S21Matrix& other) noexcept;
  S21Matrix operator-(const S21Matrix& other) noexcept;  // substraction
  S21Matrix operator-=(const S21Matrix& other) noexcept;
  S21Matrix operator*(const S21Matrix& other) noexcept;  // multiplication
  S21Matrix operator*=(const S21Matrix& other) noexcept;
  S21Matrix operator*(const double num) noexcept;  // multiple to num
  S21Matrix operator*=(const double num) noexcept;
  double& operator()(int i, int j);  // indexing matrix
  double& operator()(int i, int j) const;

 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
  void NullHandler() noexcept;
  void CreateMatrix(int rows, int columns);
  void RemoveMatrix() noexcept;
  void Copy(const S21Matrix& other) noexcept;
  double GetDeterminant() noexcept;
  void GetMatrix(int row, int col, const S21Matrix& tmp) noexcept;
};

#endif  // SRC_S21_MATRIX_OPP_H_