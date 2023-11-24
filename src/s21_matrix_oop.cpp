#include "s21_matrix_oop.hpp"

/// @brief Constructors
S21Matrix::S21Matrix() noexcept { this->NullHandler(); }
S21Matrix::S21Matrix(int rows, int columns) {
  this->CreateMatrix(rows, columns);
}
S21Matrix::S21Matrix(const S21Matrix& other) noexcept { this->Copy(other); }
S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  this->Copy(other);
  other.RemoveMatrix();
}
S21Matrix::~S21Matrix() noexcept {
  if (this->matrix_ != nullptr) {
    this->RemoveMatrix();
  }
}

/// @brief Allocating memory for matrix
/// @param rows amount of row
/// @param cols amount of col
void S21Matrix::CreateMatrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::length_error("Row or Col is below 1");
  }
  this->rows_ = rows;
  this->cols_ = cols;
  this->matrix_ = new double*[rows_]();
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[this->cols_]();
    if (this->matrix_[i] == nullptr) {
      for (int j = 0; j < i; j++) {
        delete[] this->matrix_[j];
      }
      delete[] this->matrix_;
      this->NullHandler();
      throw std::bad_alloc();
    }
  }
}
/// @brief Free allocated memory
void S21Matrix::RemoveMatrix() noexcept {
  if (this->matrix_ != nullptr) {
    for (int i = 0; i < this->rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    this->NullHandler();
  }
}
/// @brief Copying one matrix to another
/// @param other copy source
void S21Matrix::Copy(const S21Matrix& other) noexcept {
  this->CreateMatrix(other.rows_, other.cols_);
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
/// @brief Finding Matrix Determinant
/// @return Result
double S21Matrix::GetDeterminant() noexcept {
  double res = 0.0;
  if (this->rows_ == 1) {
    res = this->matrix_[0][0];
  } else {
    S21Matrix tmp(this->rows_ - 1, this->cols_ - 1);
    for (int i = 0; i < this->rows_; ++i) {
      this->GetMatrix(0, i, tmp);
      if (i % 2) {
        res -= this->matrix_[0][i] * tmp.GetDeterminant();
      } else {
        res += this->matrix_[0][i] * tmp.GetDeterminant();
      }
    }
    // tmp.RemoveMatrix();
  }
  return res;
}
/// @brief Finding Minor of Matrix
/// @param row index of row matrix
/// @param col index of row matrix
/// @param tmp Tmp becomes minor of matrix
void S21Matrix::GetMatrix(int row, int col, const S21Matrix& tmp) noexcept {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < this->rows_; ++i) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < this->cols_; ++j) {
      if (j == col) {
        continue;
      }
      tmp.matrix_[m_row][m_col] = this->matrix_[i][j];
      m_col++;
    }
    m_row++;
  }
}
/// @brief Making out matrix to zero
void S21Matrix::NullHandler() noexcept {
  this->matrix_ = nullptr;
  this->rows_ = 0;
  this->cols_ = 0;
}
/// @brief Setting element of matrix row
/// @param rows how much we want to make it
void S21Matrix::setRows(int rows) {
  int tmpRows = 0;
  if (rows < 1) {
    throw std::length_error("Your matrix is empty.");
  }
  S21Matrix tmp(rows, this->cols_);
  if (this->rows_ < rows) {
    tmpRows = this->rows_;
  } else {
    tmpRows = rows;
  }
  for (int i = 0; i < tmpRows; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
  // tmp.RemoveMatrix();
}
/// @brief Setting element of matrix col
/// @param cols how much we want to make it
void S21Matrix::setColumns(int cols) {
  int tmpCols = 0;
  if (cols < 1) {
    throw std::length_error("Your matrix is empty or problem row and col.");
  }
  S21Matrix tmp(this->rows_, cols);
  if (this->cols_ < cols) {
    tmpCols = this->cols_;
  } else {
    tmpCols = cols;
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < tmpCols; j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
  // tmp.RemoveMatrix();
}

/// @brief Getters
/// @return Getiing Row of matrix
int S21Matrix::getRows() noexcept { return this->rows_; }  // getters
/// @brief Getters
/// @return Getiing Row of matrix
int S21Matrix::getCols() noexcept { return this->cols_; }
/// @brief Getters
/// @return Getiing Row of matrix
double** S21Matrix::getMatrix() noexcept { return this->matrix_; }
/// @brief Sum of our Matrix by [i][j]
/// @param other Our Matrix
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->matrix_ == nullptr || other.matrix_ == nullptr ||
      (this->rows_ < 1 || other.rows_ < 1)) {
    throw std::length_error("Your matrix is empty or row is lesser than 1");
  }
  if ((this->rows_ == other.rows_) && (this->cols_ == other.cols_)) {
    for (int i = 0; i < this->rows_; ++i) {
      for (int j = 0; j < this->cols_; ++j) {
        this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
      }
    }
  } else {
    throw std::invalid_argument("Error: matrix size if wrong");
  }
}
/// @brief Sub of our Matrix by [i][j]
/// @param other Our Matrix
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if ((this->matrix_ == nullptr || other.matrix_ == nullptr) ||
      (this->rows_ < 1 || other.rows_ < 1)) {
    throw std::length_error("Array is empty or problem with row, col size.");
  }
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < this->rows_; ++i) {
      for (int j = 0; j < this->cols_; ++j) {
        this->matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
      }
    }
  } else {
    throw std::length_error("Error: Matrix size are not same.");
  }
}
/// @brief Mul of our Matrix to num
/// @param num Our Num
void S21Matrix::MulNumber(const double num) {
  if (this->rows_ < 1 || this->matrix_ == nullptr) {
    throw std::length_error(
        "Error: Matrix size if sempty or cols and rows is empty.");
  }
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] = this->matrix_[i][j] * num;
    }
  }
}
/// @brief Mul of our Matrix by [i][j]
/// @param other Our Matrix
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if ((this->rows_ < 1 || other.rows_ < 1) ||
      (this->matrix_ == nullptr || other.matrix_ == nullptr)) {
    throw std::length_error("Error: Matrix is empty or row, col is empty.");
  }
  if (this->cols_ == other.rows_) {
    S21Matrix result(this->rows_, other.cols_);
    for (int i = 0; i < this->rows_; ++i) {
      for (int j = 0; j < other.cols_; ++j) {
        for (int k = 0; k < other.rows_; ++k) {
          result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    this->RemoveMatrix();
    this->Copy(result);
    // result.RemoveMatrix();
  } else {
    throw std::length_error("Error: matrix size is wrong.");
  }
}
/// @brief Checking if our elements from [i][j] to [i][j] are same
/// @param other Our Matrix
/// @return Returning, if same true or false
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool res = true;
  if (other.matrix_ == nullptr && this->matrix_ == nullptr &&
      (this->rows_ == other.rows_ && this->cols_ == other.cols_)) {
    res = false;
    throw std::length_error(
        "MAtrix is empty or maybe one of row and col is empty");
  }
  for (int i = 0; i < this->rows_ && res; ++i) {
    for (int j = 0; j < this->cols_ && res; ++j) {
      res = (fabs(this->matrix_[i][j] - other.matrix_[i][j]) < 1e-6);
    }
  }
  return res;
}
/// @brief Transposing out Matrix
/// @return Returning new Matrix
S21Matrix S21Matrix::Transpose() {
  if ((this->matrix_ == nullptr) && (this->rows_ < 1)) {
    throw std::length_error("Matrix is empty.");
  }
  S21Matrix result(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      result.matrix_[j][i] = this->matrix_[i][j];
    }
  }
  return result;
}
/// @brief Taking Determinant of Matrix
/// @return Returning value of our matrix
double S21Matrix::Determinant() {
  double result = 0.0;
  if (this->matrix_ == nullptr && this->rows_ < 1) {
    throw std::length_error("Matrix is empty.");
  }
  if (this->rows_ == this->cols_) {
    result = this->GetDeterminant();
  } else {
    throw std::length_error("Error: matrix size if wrong.");
  }
  return result;
}
/// @brief Calculating algebraic complement
/// @return Returning new changed Matrix
S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ < 1 && this->matrix_ == nullptr) {
    throw std::length_error("Matrix is empty. Or Problem with row and col.");
  }
  if (this->rows_ != this->cols_) {
    throw std::length_error("Error: matrix size is wrong.");
  }
  S21Matrix result(this->rows_, this->cols_);
  S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
  double determinant = 0.0;
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->GetMatrix(i, j, minor);
      determinant = minor.Determinant();
      result.matrix_[i][j] = pow(-1, i + j) * determinant;
    }
  }
  // minor.RemoveMatrix();
  return result;
}
/// @brief Calculating Matrix Inversion
/// @return Our new Matrix
S21Matrix S21Matrix::InverseMatrix() {
  if (this->matrix_ == nullptr && this->rows_ < 1) {
    throw std::length_error(
        "Matrix is empty. Or Problem with row and col inverse.");
  }
  if (this->rows_ != this->cols_) {
    throw std::length_error("Error: matrix size is wrong.");
  }
  double determinant = this->GetDeterminant();
  if (std::fabs(determinant) < 1e-7) {
    throw std::length_error("Determinant is 0, this is not allowed.");
  }
  S21Matrix result(this->rows_, this->cols_);
  if (this->rows_ == 1) {
    result.matrix_[0][0] = 1.0 / this->matrix_[0][0];
  } else {
    S21Matrix tmp = this->CalcComplements();
    result = tmp.Transpose();
    result.MulNumber(1 / determinant);
    // tmp.RemoveMatrix();
  }
  return result;
}

/// @brief Check if matrxi1 == matrix2
/// @param other our new matrix2
/// @return return Matrix
S21Matrix& S21Matrix::operator=(const S21Matrix& other) noexcept {
  this->RemoveMatrix();
  this->Copy(other);
  return *this;
}
/// @brief Check if matrxi1 == matrix2
/// @param other
/// @return
bool S21Matrix::operator==(const S21Matrix& other) {
  bool tmp = this->EqMatrix(other);
  return tmp;
}
/// @brief Add matrix1 += matrix2
/// @param other our matrix2
/// @return Return changed matrix1
S21Matrix S21Matrix::operator+=(const S21Matrix& other) noexcept {
  this->SumMatrix(other);
  return *this;
}
/// @brief Add new = matrix1 + matrix2
/// @param other our matrix2
/// @return Return new matrix
S21Matrix S21Matrix::operator+(const S21Matrix& other) noexcept {
  this->SumMatrix(other);
  S21Matrix tmp = *this;
  return tmp;
}
/// @brief Add matrix1 -= matrix2
/// @param other our matrix2
/// @return Return changed matrix1
S21Matrix S21Matrix::operator-(const S21Matrix& other) noexcept {
  this->SubMatrix(other);
  S21Matrix res = *this;
  return res;
}
/// @brief Add new = matrix1 - matrix2
/// @param other our matrix2
/// @return Return new matrix
S21Matrix S21Matrix::operator-=(const S21Matrix& other) noexcept {
  this->SubMatrix(other);
  return *this;
}
/// @brief Add new = matrix1 * matrix2
/// @param other our matrix2
/// @return Return new matrix
S21Matrix S21Matrix::operator*(const S21Matrix& other) noexcept {
  this->MulMatrix(other);
  S21Matrix res = *this;
  return res;
}
/// @brief Add matrix1 *= matrix2
/// @param other our matrix2
/// @return Return changed matrix1
S21Matrix S21Matrix::operator*=(const S21Matrix& other) noexcept {
  this->MulMatrix(other);
  return *this;
}
/// @brief Add new = matrix1 * num
/// @param num our matrix2
/// @return Return new matrix
S21Matrix S21Matrix::operator*(const double num) noexcept {
  this->MulNumber(num);
  return *this;
}
/// @brief Multiply num to matrix
/// @param num our number
/// @return Return new matrix
S21Matrix S21Matrix::operator*=(const double num) noexcept {
  this->MulNumber(num);
  S21Matrix res = *this;
  return res;
}
/// @brief Returning matrix index
/// @param i row
/// @param j col
/// @return Returning matrix element of [i][j]
double& S21Matrix::operator()(int i, int j) const {
  if (i > this->rows_ || j > this->cols_ || i < 0 || j < 0) {
    throw std::length_error("Index is lesser 0 or bigger than rowsm cols.");
  }
  return this->matrix_[i][j];
}
/// @brief Returning const matrix index whick cannot be changed
/// @param i row
/// @param j col
/// @return Returning const Matrix element
double& S21Matrix::operator()(int i, int j) {
  if (i > this->rows_ || j > this->cols_ || i < 0 || j < 0) {
    throw std::length_error("Index is lesser 0 or bigger than rowsm cols.");
  }
  return this->matrix_[i][j];
}