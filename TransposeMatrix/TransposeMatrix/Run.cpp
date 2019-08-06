/* This Program computes the transpose of an m x n matrix
	Problem 18 From Intro. to 3D Game Programming with DirectX12
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

	// Transpose the matrix
	int** transpose = new int* [n];
	for (int i = 0; i < n; i++) {
		try {
			transpose[i] = new int[m];
			for (int j = 0; j < m; j++) {
				transpose[i][j] = matrix[j][i];
			}
		}
		catch (bad_alloc) {
			exitOnBadAlloc();
		}
	}

	// Print out the transpose matrix
	std::cout << "Transpos3e Matrix: \n";
	printMatrix(transpose, n, m);

	return 0;
}


void exitOnBadAlloc() {
	std::cerr << "ERROR: Bad Memory Allocation\n";
	exit(1);
}