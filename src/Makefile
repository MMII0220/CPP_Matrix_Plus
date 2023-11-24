CFLAGS = -Wall -Werror -Wextra

all: s21_matrix_oop.a

build: s21_matrix_oop.cpp
	g++ -c $(CFLAGS) -lstdc++ -std=c++17 s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_matrix_oop.a: build
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

clean:
	rm -rf *.o *.out s21_matrix_oop.a unit_test tests
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info

rebuild:
	make clean
	make build

leaks: test
	leaks -atExit -- ./unit_test

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n *.cpp *.hpp
	rm .clang-format

test: s21_matrix_oop.a ./unit_tests/unit_tests.cpp
	g++ -lgtest -lstdc++ -std=c++17 -ftest-coverage -pthread s21_matrix_oop.a ./unit_tests/unit_tests.cpp -o unit_test
	./unit_test

gcov_report: clean
	@g++ --coverage $(CFLAGS) ./unit_tests/unit_tests.cpp s21_matrix_oop.cpp -o tests -lstdc++ -lm -lgtest
	@./tests
# @lcov -t "info" -o tests.info -c -d .
# @lcov -t "tests" -o tests.info -c -d '/usr/*' '*gtest*' '*CMakeFiles*' '*s21_matrix_oop.h*' '*tests.cc*' --output-file gcovreport.info
	@geninfo --ignore-errors inconsistent --output-filename tests.info --test-name tests --memory 0 s21_matrix_oop.gcda
	@genhtml --ignore-errors inconsistent -o report tests.info
	@open report/index.html
