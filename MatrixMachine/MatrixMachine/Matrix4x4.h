#pragma once
#include "Matrix.h"

class Matrix4x4 : public Matrix{
	static int det(int**, int);
public:
	Matrix4x4();
	~Matrix4x4();
	int determinant();
	Matrix inverse();
};

