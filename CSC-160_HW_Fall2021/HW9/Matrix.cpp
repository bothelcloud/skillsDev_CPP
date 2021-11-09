#include "csc160.h"

using namespace csc160::constructs;

// Default constructor of a Matrix object with no input options specified (Creates a 0 initialized 2 x 2 matrix)
csc160::constructs::Matrix::Matrix()
{
	int i = 0, ii = 0;

	// Setting the dimensions of the Matrix
	prvt_int_rows = 2;
	prvt_int_cols = 2;

	// Generation of the array that will then hold the values of the matrix
	prvt_dbla_matrix = new double* [prvt_int_rows];
	for (i = 0; i <= (prvt_int_rows - 1); i++) prvt_dbla_matrix[i] = new double[prvt_int_cols];

	// Initializing the values for the matrix
	for (i = 0; i <= (prvt_int_rows - 1); i++)
		for (i = 0; i <= (prvt_int_cols - 1); i++) prvt_dbla_matrix[i][ii] = 0;
}

// Constructor that sets up the Matrix object given the dimensions
csc160::constructs::Matrix::Matrix(const int& arg_rows, const int& arg_cols)
{
	int i = 0, ii = 0;

	// Setting the dimensions of the Matrix
	prvt_int_rows = arg_rows;
	prvt_int_cols = arg_cols;

	// Generation of the array that will then hold the values of the matrix
	prvt_dbla_matrix = new double* [prvt_int_rows];
	for (i = 0; i <= (prvt_int_rows - 1); i++) prvt_dbla_matrix[i] = new double[prvt_int_cols];

	// Initializing the values for the matrix
	for (i = 0; i <= (prvt_int_rows - 1); i++)
		for (i = 0; i <= (prvt_int_cols - 1); i++) prvt_dbla_matrix[i][ii] = 0;
}

csc160::constructs::Matrix::Matrix(const Matrix& arg_obj)
{
	int i = 0, ii = 0;

	// Setting the dimensions of the Matrix
	prvt_int_rows = arg_obj.prvt_int_rows;
	prvt_int_cols = arg_obj.prvt_int_cols;

	// Generation of the array that will then hold the values of the matrix
	prvt_dbla_matrix = new double* [prvt_int_rows];
	for (i = 0; i <= (prvt_int_rows - 1); i++) prvt_dbla_matrix[i] = new double[prvt_int_cols];

	// Initializing the values for the matrix
	for (i = 0; i <= (prvt_int_rows - 1); i++)
		for (i = 0; i <= (prvt_int_cols - 1); i++) prvt_dbla_matrix[i][ii] = arg_obj.prvt_dbla_matrix[i][ii];

	
}

// Deconstructor for the Matrix class that destroys the objects at the end of their lives
csc160::constructs::Matrix::~Matrix()
{
	
}

// Function that pulls back the rows that are present in the Matrix
int csc160::constructs::Matrix::GetRows()
{
	return prvt_int_rows;
}

// Function that pulls back the cols that are present in the Matrix
int csc160::constructs::Matrix::GetCols()
{
	return prvt_int_cols;
}

// Returns the double value that is stored in the cell of the Matrix
double csc160::constructs::Matrix::GetValue(const int& arg_row, const int& arg_col)
{
	return prvt_dbla_matrix[(arg_row - 1)][(arg_col - 1)];
}

// Functions that sets the value of a Matrix cell
void csc160::constructs::Matrix::SetValue(const int& arg_row, const int& arg_col, const double& arg_value)
{
	prvt_dbla_matrix[(arg_row - 1)][(arg_col - 1)] = arg_value;
}

// Function that performs the addition operation of two Matrix objects
Matrix csc160::constructs::operator+(const Matrix& arg_left, const Matrix& arg_right)
{
	if (arg_left.prvt_int_rows == arg_right.prvt_int_rows && arg_left.prvt_int_cols == arg_right.prvt_int_cols)
	{
		int i = 0, ii = 0;
		Matrix result(arg_left.prvt_int_rows, arg_left.prvt_int_cols);
		
		for (i = 0; i <= (arg_left.prvt_int_rows - 1); i++)
			for (ii = 0; ii <= (arg_left.prvt_int_cols - 1); ii++) result.prvt_dbla_matrix[i][ii] = (arg_left.prvt_dbla_matrix[i][ii] + arg_right.prvt_dbla_matrix[i][ii]);
		
		return result;
	}
}

// Function that performs the multiplication operation of two Matrix objects
Matrix csc160::constructs::operator*(const Matrix& arg_left, const Matrix& arg_right)
{
	return Matrix();
}
