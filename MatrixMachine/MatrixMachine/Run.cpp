/* This Program creates a matrix, and then computes multiple different
	Operations on the matrix
	Problem 18 & 19 From Intro. to 3D Game Programming with DirectX12 Included in this program
	Author: Craig Aucoin
*/

#include "Matrix4x4.h"
#include <iostream>


using namespace std;

void exitOnBadAlloc();
void printMatrix(int**, int, int);

int main() {
	// 4x4 Matrix to calculate determinant
	Matrix4x4 fourByfour = Matrix4x4();
	
	std::cout << "Determinant of 4x4 Matrix: " << fourByfour.determinant();
	//Matrix inverse = fourByfour.inverse();

	/*
	inverse.printMatrix();


	return 0;
	*/
}


void exitOnBadAlloc() {
	std::cerr << "ERROR: Bad Memory Allocation\n";
	exit(1);
}