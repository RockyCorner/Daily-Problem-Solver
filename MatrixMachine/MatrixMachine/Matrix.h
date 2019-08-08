#pragma once
class Matrix
{
private:
	int** matrix;
	int row;
	int col;
	int calculateDet(int firstRow, int firstColumn, int removeRow, int removeCol, int size);

public:
	Matrix(int r, int c);
	Matrix();
	Matrix(int**, int, int);
	~Matrix();
	Matrix transpose();
	int determinant();
	Matrix inverse();
	void printMatrix();
	int getRow();
	int getColumn();
	int** getMatrix();


	static void exitOnBadAlloc();
};

