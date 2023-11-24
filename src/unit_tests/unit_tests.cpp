#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

/* Private
*************************************/
TEST(PrivateTests, DefaultConstructor) {
  S21Matrix mat;
  ASSERT_EQ(mat.getRows(), 0);
  ASSERT_EQ(mat.getCols(), 0);
  ASSERT_EQ(mat.getMatrix(), nullptr);
}
TEST(PrivateTests, constructor_move) {
  S21Matrix A(5, 5);
  S21Matrix B(std::move(A));
  EXPECT_EQ(5, B.getRows());
  EXPECT_EQ(5, B.getCols());
  EXPECT_EQ(0, A.getRows());
  EXPECT_EQ(0, A.getCols());
}
TEST(PrivateTests, CopyConstructor) {
  S21Matrix A(3, 4);
  S21Matrix B(A);
  EXPECT_EQ(3, B.getRows());
  EXPECT_EQ(4, B.getCols());
  EXPECT_EQ(1, A == B);
}
TEST(PrivateTests, SetRowTest) {
  S21Matrix a(2, 2);
  int b = 5;
  a.setRows(5);
  EXPECT_TRUE(a.getRows() == b);
}
TEST(PrivateTests, SetRowTest2) {
  S21Matrix a(5, 2);
  int b = 2;
  a.setRows(2);

  EXPECT_TRUE(a.getRows() == b);
}
TEST(PrivateTests, SetColTest) {
  S21Matrix a(2, 2);
  int b = 5;
  a.setColumns(5);

  EXPECT_TRUE(a.getCols() == b);
}
TEST(PrivateTests, SetColTest2) {
  S21Matrix a(5, 2);
  int b = 2;
  a.setColumns(2);

  EXPECT_TRUE(a.getCols() == b);
}

/* Methods
*************************************/
TEST(S21MatrixTest, SumMatrixTest) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix expected(2, 2);

  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[1][0] = 3;
  a.getMatrix()[1][1] = 4;

  b.getMatrix()[0][0] = 5;
  b.getMatrix()[0][1] = 6;
  b.getMatrix()[1][0] = 7;
  b.getMatrix()[1][1] = 8;

  expected.getMatrix()[0][0] = 6;
  expected.getMatrix()[0][1] = 8;
  expected.getMatrix()[1][0] = 10;
  expected.getMatrix()[1][1] = 12;

  a.SumMatrix(b);
  EXPECT_TRUE(a == expected);
}
TEST(S21MatrixTest, SubMatrixTest) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix expected(2, 2);
  a.getMatrix()[0][0] = 4;
  a.getMatrix()[0][1] = 4;
  a.getMatrix()[1][0] = 6;
  a.getMatrix()[1][1] = 6;

  b.getMatrix()[0][0] = 2;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[1][0] = 3;
  b.getMatrix()[1][1] = 3;

  expected.getMatrix()[0][0] = 2;
  expected.getMatrix()[0][1] = 2;
  expected.getMatrix()[1][0] = 3;
  expected.getMatrix()[1][1] = 3;

  a.SubMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(S21MatrixTest, MulMatrixTest) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix expected(2, 2);
  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[1][0] = 3;
  a.getMatrix()[1][1] = 4;

  b.getMatrix()[0][0] = 5;
  b.getMatrix()[0][1] = 6;
  b.getMatrix()[1][0] = 7;
  b.getMatrix()[1][1] = 8;

  expected.getMatrix()[0][0] = 19;
  expected.getMatrix()[0][1] = 22;
  expected.getMatrix()[1][0] = 43;
  expected.getMatrix()[1][1] = 50;

  a.MulMatrix(b);
  EXPECT_TRUE(a == expected);
}
TEST(S21MatrixTest, MulNumberTest) {
  S21Matrix a(2, 2);
  S21Matrix expected(2, 2);
  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[1][0] = 3;
  a.getMatrix()[1][1] = 4;

  expected.getMatrix()[0][0] = 2;
  expected.getMatrix()[0][1] = 4;
  expected.getMatrix()[1][0] = 6;
  expected.getMatrix()[1][1] = 8;

  a.MulNumber(2);
  EXPECT_TRUE(a == expected);
}
TEST(S21MatrixTest, EqTest) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[1][0] = 3;
  a.getMatrix()[1][1] = 4;

  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[1][0] = 3;
  b.getMatrix()[1][1] = 4;

  EXPECT_TRUE(a.EqMatrix(b));
}
TEST(S21MatrixTest, EqTest1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a.getMatrix()[0][0] = 35;
  a.getMatrix()[0][1] = 23;
  a.getMatrix()[1][0] = 62;
  a.getMatrix()[1][1] = 11;

  b.getMatrix()[0][0] = 35;
  b.getMatrix()[0][1] = 23;
  b.getMatrix()[1][0] = 62;
  b.getMatrix()[1][1] = 11;

  EXPECT_TRUE(a.EqMatrix(b));
}
TEST(S21MatrixTest, TransposeTest2X2) {
  S21Matrix a(2, 2);
  S21Matrix expected(2, 2);
  a.getMatrix()[0][0] = 3;
  a.getMatrix()[0][1] = 5;
  a.getMatrix()[1][0] = 1;
  a.getMatrix()[1][1] = 3;

  expected.getMatrix()[0][0] = 3;
  expected.getMatrix()[0][1] = 1;
  expected.getMatrix()[1][0] = 5;
  expected.getMatrix()[1][1] = 3;

  EXPECT_TRUE(a.Transpose() == expected);
}
TEST(S21MatrixTest, TransposeTest3X3) {
  S21Matrix a(3, 3);
  S21Matrix expected(3, 3);

  a.getMatrix()[0][0] = 3;
  a.getMatrix()[0][1] = 5;
  a.getMatrix()[0][2] = 5;
  a.getMatrix()[1][0] = 1;
  a.getMatrix()[1][1] = 5;
  a.getMatrix()[1][2] = 2;
  a.getMatrix()[2][0] = 2;
  a.getMatrix()[2][1] = 1;
  a.getMatrix()[2][2] = 3;

  expected.getMatrix()[0][0] = 3;
  expected.getMatrix()[0][1] = 1;
  expected.getMatrix()[0][2] = 2;
  expected.getMatrix()[1][0] = 5;
  expected.getMatrix()[1][1] = 5;
  expected.getMatrix()[1][2] = 1;
  expected.getMatrix()[2][0] = 5;
  expected.getMatrix()[2][1] = 2;
  expected.getMatrix()[2][2] = 3;

  EXPECT_TRUE(a.Transpose() == expected);
}
TEST(S21MatrixTest, DeterminantsTest2x2) {
  S21Matrix a(2, 2);
  double expected = 11;
  a.getMatrix()[0][0] = 5;
  a.getMatrix()[0][1] = 4;
  a.getMatrix()[1][0] = 1;
  a.getMatrix()[1][1] = 3;

  EXPECT_TRUE(a.Determinant() == expected);
}
TEST(S21MatrixTest, DeterminantsTest3x3) {
  S21Matrix a(3, 3);
  double expected = -1;

  a.getMatrix()[0][0] = 3;
  a.getMatrix()[0][1] = 5;
  a.getMatrix()[0][2] = 5;
  a.getMatrix()[1][0] = 1;
  a.getMatrix()[1][1] = 5;
  a.getMatrix()[1][2] = 2;
  a.getMatrix()[2][0] = 2;
  a.getMatrix()[2][1] = 1;
  a.getMatrix()[2][2] = 3;

  EXPECT_TRUE(a.Determinant() == expected);
}
TEST(S21MatrixTest, CalcComplementsTest3x3) {
  S21Matrix a(3, 3);
  S21Matrix expected(3, 3);

  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[0][2] = 3;
  a.getMatrix()[1][0] = 0;
  a.getMatrix()[1][1] = 4;
  a.getMatrix()[1][2] = 2;
  a.getMatrix()[2][0] = 5;
  a.getMatrix()[2][1] = 2;
  a.getMatrix()[2][2] = 1;

  expected.getMatrix()[0][0] = 0;
  expected.getMatrix()[0][1] = 10;
  expected.getMatrix()[0][2] = -20;
  expected.getMatrix()[1][0] = 4;
  expected.getMatrix()[1][1] = -14;
  expected.getMatrix()[1][2] = 8;
  expected.getMatrix()[2][0] = -8;
  expected.getMatrix()[2][1] = -2;
  expected.getMatrix()[2][2] = 4;

  EXPECT_TRUE(a.CalcComplements() == expected);
}
TEST(S21MatrixTest, InverseTest2x2) {
  S21Matrix a(2, 2);
  S21Matrix check(2, 2);

  a.getMatrix()[0][0] = 2;
  a.getMatrix()[0][1] = 5;
  a.getMatrix()[1][0] = 6;
  a.getMatrix()[1][1] = 3;

  check.getMatrix()[0][0] = -1 / 8.0;
  check.getMatrix()[0][1] = 5 / 24.0;
  check.getMatrix()[1][0] = 1 / 4.0;
  check.getMatrix()[1][1] = -1 / 12.0;

  EXPECT_TRUE(a.InverseMatrix() == check);
}

/* Operators Tests
**********************************************/
TEST(S21MatrixTest, operator_plus) {
  S21Matrix a(3, 4);
  S21Matrix b(3, 4);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[0][2] = 3;
  b.getMatrix()[0][3] = 4;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;
  b.getMatrix()[1][2] = 7;
  b.getMatrix()[1][3] = 8;
  b.getMatrix()[2][0] = 9;
  b.getMatrix()[2][1] = 10;
  b.getMatrix()[2][2] = 11;
  b.getMatrix()[2][3] = 12;
  a = b + b;
  EXPECT_EQ(1, a == b);
}
TEST(Test, operator_minus) {
  S21Matrix a(3, 4);
  S21Matrix b(3, 4);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[0][2] = 3;
  b.getMatrix()[0][3] = 4;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;
  b.getMatrix()[1][2] = 7;
  b.getMatrix()[1][3] = 8;
  b.getMatrix()[2][0] = 9;
  b.getMatrix()[2][1] = 10;
  b.getMatrix()[2][2] = 11;
  b.getMatrix()[2][3] = 12;
  a = b - b;
  EXPECT_EQ(1, a == b);
}
TEST(Test, operator_pluseq) {
  S21Matrix a(3, 4);
  S21Matrix b(3, 4);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[0][2] = 3;
  b.getMatrix()[0][3] = 4;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;
  b.getMatrix()[1][2] = 7;
  b.getMatrix()[1][3] = 8;
  b.getMatrix()[2][0] = 9;
  b.getMatrix()[2][1] = 10;
  b.getMatrix()[2][2] = 11;
  b.getMatrix()[2][3] = 12;
  a += b;
  EXPECT_EQ(1, a == b);
}
TEST(Test, operator_minuseq) {
  S21Matrix a(3, 4);
  S21Matrix b(3, 4);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[0][2] = 3;
  b.getMatrix()[0][3] = 4;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;
  b.getMatrix()[1][2] = 7;
  b.getMatrix()[1][3] = 8;
  b.getMatrix()[2][0] = 9;
  b.getMatrix()[2][1] = 10;
  b.getMatrix()[2][2] = 11;
  b.getMatrix()[2][3] = 12;

  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[0][2] = 3;
  a.getMatrix()[0][3] = 4;
  a.getMatrix()[1][0] = 5;
  a.getMatrix()[1][1] = 6;
  a.getMatrix()[1][2] = 7;
  a.getMatrix()[1][3] = 8;
  a.getMatrix()[2][0] = 9;
  a.getMatrix()[2][1] = 10;
  a.getMatrix()[2][2] = 11;
  a.getMatrix()[2][3] = 12;
  a -= b;
  b -= b;
  EXPECT_EQ(1, a == b);
}
TEST(Test, operator_mulNumbereq) {
  S21Matrix b(3, 4);
  S21Matrix a(3, 4);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[0][2] = 3;
  b.getMatrix()[0][3] = 4;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;
  b.getMatrix()[1][2] = 7;
  b.getMatrix()[1][3] = 8;
  b.getMatrix()[2][0] = 9;
  b.getMatrix()[2][1] = 10;
  b.getMatrix()[2][2] = 11;
  b.getMatrix()[2][3] = 12;

  a.getMatrix()[0][0] = 2;
  a.getMatrix()[0][1] = 4;
  a.getMatrix()[0][2] = 6;
  a.getMatrix()[0][3] = 8;
  a.getMatrix()[1][0] = 10;
  a.getMatrix()[1][1] = 12;
  a.getMatrix()[1][2] = 14;
  a.getMatrix()[1][3] = 16;
  a.getMatrix()[2][0] = 18;
  a.getMatrix()[2][1] = 20;
  a.getMatrix()[2][2] = 22;
  a.getMatrix()[2][3] = 24;

  b = b * 2;
  EXPECT_EQ(1, b == a);
}
TEST(Test, operator_mulNumbereq1) {
  S21Matrix b(3, 4);
  S21Matrix a(3, 4);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[0][2] = 3;
  b.getMatrix()[0][3] = 4;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;
  b.getMatrix()[1][2] = 7;
  b.getMatrix()[1][3] = 8;
  b.getMatrix()[2][0] = 9;
  b.getMatrix()[2][1] = 10;
  b.getMatrix()[2][2] = 11;
  b.getMatrix()[2][3] = 12;

  a.getMatrix()[0][0] = 2;
  a.getMatrix()[0][1] = 4;
  a.getMatrix()[0][2] = 6;
  a.getMatrix()[0][3] = 8;
  a.getMatrix()[1][0] = 10;
  a.getMatrix()[1][1] = 12;
  a.getMatrix()[1][2] = 14;
  a.getMatrix()[1][3] = 16;
  a.getMatrix()[2][0] = 18;
  a.getMatrix()[2][1] = 20;
  a.getMatrix()[2][2] = 22;
  a.getMatrix()[2][3] = 24;

  b *= 2;
  EXPECT_EQ(1, b == a);
}
TEST(Test, operator_mulMatrixeq) {
  S21Matrix b(2, 2);
  S21Matrix a(2, 2);
  S21Matrix expected(2, 2);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;

  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[1][0] = 5;
  a.getMatrix()[1][1] = 6;

  expected.getMatrix()[0][0] = 11;
  expected.getMatrix()[0][1] = 14;
  expected.getMatrix()[1][0] = 35;
  expected.getMatrix()[1][1] = 46;

  b *= a;
  EXPECT_EQ(1, b == expected);
}
TEST(Test, operator_mulMatrix) {
  S21Matrix b(2, 2);
  S21Matrix a(2, 2);
  S21Matrix expected(2, 2);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;

  a.getMatrix()[0][0] = 1;
  a.getMatrix()[0][1] = 2;
  a.getMatrix()[1][0] = 5;
  a.getMatrix()[1][1] = 6;

  expected.getMatrix()[0][0] = 11;
  expected.getMatrix()[0][1] = 14;
  expected.getMatrix()[1][0] = 35;
  expected.getMatrix()[1][1] = 46;

  a = b * a;
  EXPECT_EQ(1, b == expected);
}
TEST(Test, operator_mulNumber) {
  S21Matrix b(3, 4);
  S21Matrix a(3, 4);
  b.getMatrix()[0][0] = 1;
  b.getMatrix()[0][1] = 2;
  b.getMatrix()[0][2] = 3;
  b.getMatrix()[0][3] = 4;
  b.getMatrix()[1][0] = 5;
  b.getMatrix()[1][1] = 6;
  b.getMatrix()[1][2] = 7;
  b.getMatrix()[1][3] = 8;
  b.getMatrix()[2][0] = 9;
  b.getMatrix()[2][1] = 10;
  b.getMatrix()[2][2] = 11;
  b.getMatrix()[2][3] = 12;

  a.getMatrix()[0][0] = 2;
  a.getMatrix()[0][1] = 4;
  a.getMatrix()[0][2] = 6;
  a.getMatrix()[0][3] = 8;
  a.getMatrix()[1][0] = 10;
  a.getMatrix()[1][1] = 12;
  a.getMatrix()[1][2] = 14;
  a.getMatrix()[1][3] = 16;
  a.getMatrix()[2][0] = 18;
  a.getMatrix()[2][1] = 20;
  a.getMatrix()[2][2] = 22;
  a.getMatrix()[2][3] = 24;

  b = b * 2;
  EXPECT_EQ(1, b == a);
}
TEST(Test, OperatorTest) {
  S21Matrix a(2, 2);
  a.getMatrix()[1][0] = 234;
  EXPECT_TRUE(a.operator()(1, 0) == 234);
}
TEST(Test, OperatorTestConst) {
  S21Matrix a(2, 2);
  a.getMatrix()[1][0] = 234;
  const S21Matrix b = a;
  EXPECT_TRUE(b.operator()(1, 0) == 234);
}

/* Errors
*************************************/
TEST(MethodErrors, SumError) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_THROW(A.SumMatrix(B), std::length_error);
}
TEST(MethodErrors, SumErrorInvalidArg) {
  S21Matrix a(2, 3);
  S21Matrix b(4, 5);
  EXPECT_THROW(a.SumMatrix(b), std::invalid_argument);
}
TEST(MethodErrors, SubLengthError) {
  S21Matrix a;
  S21Matrix b;
  EXPECT_THROW(a.SubMatrix(b), std::length_error);
}
TEST(MethodErrors, SubErrorInvalidArg) {
  S21Matrix a(2, 3);
  S21Matrix b(4, 5);
  EXPECT_THROW(a.SubMatrix(b), std::length_error);
}
TEST(MethodErrors, MulMatrixLengthError) {
  S21Matrix a;
  S21Matrix b;
  EXPECT_THROW(a.MulMatrix(b), std::length_error);
}
TEST(MethodErrors, MulMatrixErrorInvalidArg) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 3);
  EXPECT_THROW(a.MulMatrix(b), std::length_error);
}
TEST(MethodErrors, MulNumberLengthError) {
  S21Matrix a;
  double num = 2;
  EXPECT_THROW(a.MulNumber(num), std::length_error);
}
TEST(MethodErrors, DeterminantLengthError) {
  S21Matrix a;
  EXPECT_THROW(a.Determinant(), std::length_error);
}
TEST(MethodErrors, DeterminantLengthErrorNotSameRowCol) {
  S21Matrix a(4, 6);
  EXPECT_THROW(a.Determinant(), std::length_error);
}
TEST(MethodErrors, TransposeLengthError) {
  S21Matrix a;
  EXPECT_THROW(a.Transpose(), std::length_error);
}
TEST(MethodErrors, CalcComplementsLengthError) {
  S21Matrix a;
  EXPECT_THROW(a.CalcComplements(), std::length_error);
}
TEST(MethodErrors, CalcComplementsLengthErrorNotSameRowCol) {
  S21Matrix a(3, 1);
  EXPECT_THROW(a.CalcComplements(), std::length_error);
}
TEST(MethodErrors, InverseLengthError) {
  S21Matrix a;
  EXPECT_THROW(a.InverseMatrix(), std::length_error);
}
TEST(MethodErrors, InverseLengthErrorNotSameRowCol) {
  S21Matrix a(3, 5);
  EXPECT_THROW(a.InverseMatrix(), std::length_error);
}
TEST(MethodErrors, OperatorLengthErrorNotSameRowCol) {
  S21Matrix a(2, 2);
  EXPECT_THROW(a.operator()(4, 6), std::length_error);
}
TEST(MethodErrors, OperatorConstLengthErrorNotSameRowCol) {
  const S21Matrix a(2, 2);
  EXPECT_THROW(a.operator()(4, 6), std::length_error);
}
TEST(MethodErrors, SetRowsLengthError) {
  S21Matrix a;
  EXPECT_THROW(a.setRows(0), std::length_error);
}
TEST(MethodErrors, SetColsLengthError) {
  S21Matrix a;
  EXPECT_THROW(a.setColumns(0), std::length_error);
}
TEST(PrivateTests, Constructor) {
  S21Matrix mat(3, 4);
  ASSERT_EQ(mat.getRows(), 3);
  ASSERT_EQ(mat.getCols(), 4);
  ASSERT_NE(mat.getMatrix(), nullptr);
  // check all elem are initi. zero
  for (int i = 0; i < mat.getRows(); ++i) {
    for (int j = 0; j < mat.getCols(); ++j) {
      ASSERT_EQ(mat.getMatrix()[i][j], 0.0);
    }
  }
  // Check that an exception is thrown if rows or columns are less than 1
  ASSERT_THROW(S21Matrix mat2(0, 4), std::length_error);
  ASSERT_THROW(S21Matrix mat3(3, -1), std::length_error);
  // ASSERT_THROW(S21Matrix mat3(3, -1), std::exception);
}
TEST(S21MatrixTest, EQmatrix) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_THROW(A == B, std::length_error);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}