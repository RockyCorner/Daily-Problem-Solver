#pragma once
class Matrix
{
private:
	int** matrix;
	int row;
	int col;
	// Save the value of the determinant
	int det;
	Matrix(int**, int, int);
public:
	Matrix(int r, int c);
	Matrix();
	~Matrix();
	Matrix transpose();
	int determinant();
	Matrix inverse();
	void printMatrix();
	static void exitOnBadAlloc();
};

