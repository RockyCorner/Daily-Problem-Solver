/* This Program creates a matrix, and then computes multiple different
	Operations on the matrix
	Problem 18 & 19 From Intro. to 3D Game Programming with DirectX12 Included in this program
	Author: Craig Aucoin
*/

#include "Matrix.h"
#include <iostream>


using namespace std;

void exitOnBadAlloc();
void printMatrix(int**, int, int);

int main() {
	/* Size components of matrix */
	int m, n;
	std::cout << "Enter the number of rows: ";
	std::cin >> m;
	std::cout << "Enter the number of columns: ";
	std::cin >> n;

	Matrix matrix = Matrix(m, n);
	matrix.printMatrix();
	Matrix transpose = matrix.transpose();
	transpose.printMatrix();
	Matrix inverse = matrix.inverse();
	inverse.printMatrix();


	return 0;
}


void exitOnBadAlloc() {
	std::cerr << "ERROR: Bad Memory Allocation\n";
	exit(1);
}