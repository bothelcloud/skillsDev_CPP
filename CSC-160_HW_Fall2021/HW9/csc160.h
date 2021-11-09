#pragma once

/**** Course Classes for Objects ****/

namespace csc160
{
	namespace constructs
	{
		class Matrix
		{
		public:
			// Constructors for the class objects
			Matrix();
			Matrix(const int& arg_rows, const int& arg_cols);
			Matrix(const Matrix& arg_obj);

			// Destructor for the class objects
			~Matrix();
			
			// Public functions for the class
			int GetRows();
			int GetCols();
			double GetValue(const int& arg_row, const int& arg_col);
			void SetValue(const int& arg_row, const int& arg_col, const double& arg_value);

			// Overloading of the operators for the Matrix class of objects
			friend Matrix operator + (const Matrix& arg_left, const Matrix& arg_right);
			friend Matrix operator * (const Matrix& arg_left, const Matrix& arg_right);

		private:
			int prvt_int_rows;
			int prvt_int_cols;
			double** prvt_dbla_matrix;
			double** prvt_dbla_holder;
		};

		
	}
}