/* This Program computes the transpose of an m x n matrix
	Problem 18 From Intro. to 3D Game Programming with DirectX12
	Author: Craig Aucoin
*/

#include <iostream>
#include <random>


using namespace std;

void exitOnNullPtr();
void printMatrix(int**, int, int);

int main() {
	/* Size components of matrix */
	int m, n;
	std::cout << "Enter the number of rows: ";
	std::cin >> m;
	std::cout << "Enter the number of columns: ";
	std::cin >> n;

	int** matrix = new int* [m];

	// allocate memory for the entries, and enter a random number as the entry
	std::random_device randomizer;
	std::mt19937 range(randomizer());
	std::uniform_int_distribution<std::mt19937::result_type> random(1, 100);
	for (int i = 0; i < m; i++) {
		matrix[i] = new (nothrow) int[n];
		if (matrix[i] == nullptr) {
			exitOnNullPtr();
		}
		for (int j = 0; j < n; j++) {
			matrix[i][j] = random(range);
		}
	}

	// Print out the original matrix
	std::cout << "Original Matrix: \n";
	printMatrix(matrix, m, n);

	// Transpose the matrix
	int** transpose = new int* [n];
	for (int i = 0; i < n; i++) {
		transpose[i] = new (nothrow) int[m];
		if (transpose[i] == nullptr) {
			exitOnNullPtr();
		}
		for (int j = 0; j < m; j++) {
			transpose[i][j] = matrix[j][i];
		}
	}

	// Print out the transpose matrix
	std::cout << "Transpos3e Matrix: \n";
	printMatrix(transpose, n, m);

	return 0;
}


void exitOnNullPtr() {
	std::cerr << "ERROR: Bad Memory Allocation\n";
	exit(1);
}

void printMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}