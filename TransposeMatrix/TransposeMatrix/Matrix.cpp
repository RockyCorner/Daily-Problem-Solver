#include "Matrix.h"
#include <iostream>
#include <random>


/*
	Constructs a r x c Matrix with random entries
	Author: Craig Aucoin
*/
Matrix::Matrix(int r, int c): row(r), col(c), det(-1)
{
	// allocate memory for the entries, and enter a random number as the entry
	std::random_device randomizer;
	std::mt19937 range(randomizer());
	std::uniform_int_distribution<std::mt19937::result_type> random(1, 100);

	matrix = new int* [r];

	for (int i = 0; i < r; i++) {
		try {
			matrix[i] = new int[c];
			for (int j = 0; j < c; j++) {
				matrix[i][j] = random(range);
			}
		}
		catch (std::bad_alloc) {
			exitOnBadAlloc();
		}
	}
}

// Constructor to store a previously created matrix
// To be used only by transpose() and inverse()
Matrix::Matrix(int** m, int r, int c) : matrix(m), col(c), row(r), det(-1) {}

// Identity Matrix default constructor (size 5x5)
Matrix::Matrix(): col(5), row(5), det(-1){

	// allocate memory for the entries, and enter a random number as the entry
	std::random_device randomizer;
	std::mt19937 range(randomizer());
	std::uniform_int_distribution<std::mt19937::result_type> random(1, 100);

	matrix = new int* [5];

	for (int i = 0; i < 5; i++) {
		try {
			matrix[i] = new int[5];
			matrix[i][i] = 1;
		}
		catch (std::bad_alloc) {
			exitOnBadAlloc();
		}
	}
}


Matrix::~Matrix()
{
	delete[] matrix;
}

/* Returns the transpose matrix of this matrix */
Matrix Matrix::transpose() {
	// Transpose the matrix
	int** transpose = new int* [col];
	for (int i = 0; i < col; i++) {
		try {
			transpose[i] = new int[row];
			for (int j = 0; j < row; j++) {
				transpose[i][j] = matrix[j][i];
			}
		}
		catch (std::bad_alloc) {
			exitOnBadAlloc();
		}
	}

	return Matrix(transpose, col, row);
}

/* Returns the determinant of this matrix */
int Matrix::determinant() {

}

/* Returns the inverse of this matrix */
Matrix Matrix::inverse() {

}

/* prints this matrix */
void Matrix::printMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}