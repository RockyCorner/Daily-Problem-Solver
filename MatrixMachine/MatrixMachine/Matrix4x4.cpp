#include "Matrix4x4.h"
#include <random>
#include <iostream>



Matrix4x4::Matrix4x4() : Matrix(4,4)
{

}


Matrix4x4::~Matrix4x4()
{
}

int Matrix4x4::determinant() {
	return det(getMatrix(), getRow());
}

/* Calculates the determinant of a nxn matrix (in array form) */
int Matrix4x4::det(int** matrix, int size) {
	int determinant = 0;
	if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	/* assign the values of the minor for minor[1][j] and calculate the determinant for that minor*/
	for (int j = 0; j < size; j++) {
		int** minor = new int* [size - 1];
		for (int j = 0; j < size - 1; j++) {
			minor[j] = new int[size - 1];
		}
		int minorColumn = 0;
		for (int i = 0; i < size; i++) {
			if (i != j) { // Not a removed row: Add matrix[x][i] to the minor
				for (int k = 0; k < size - 1; k++) {
					minor[k][minorColumn] = matrix[k + 1][i];
				}
				minorColumn++;
			}
		}

		determinant += matrix[1][j] * pow(-1, 1 + (j + 1)) * det(minor, size - 1);

		// Delete the current minor: no longer being used
		delete[] minor;
	}

	return determinant;
}

Matrix Matrix4x4::inverse() {
	int** matrixArray = new int*[getRow()];

	Matrix inverse = Matrix(matrixArray, getRow(), getRow());
	return inverse;
}
