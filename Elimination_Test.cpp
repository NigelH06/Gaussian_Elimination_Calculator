#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Gaussian Elimination Test:

		//Steps:
			//1. Make a dynamic matrix creation function 
				//*fill matrix with project values for testing
			//2. Create a forward elimination function
				//*print out to see the upper triangular form 
			//. Once in upper triangular form, use a back substitution function to see results
//function prototypes

double**CreateMatrix(int nr, int nc);
void ForwardElimination(double** A, int nr, int nc);
void BackSubstitution(double** A, int nr, int nc, double*x);

int main() {
	int nr = 3;
	int nc = nr+1;
	double* x = new double[nr];
	double** matrix = CreateMatrix(nr, nr + 1);
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			cout << "Matrix Elements A[" << i << "] [" << j << "]\n";
			cin >> matrix[i][j];
			
			
		}
	}

	cout << "Matrix before the Gaussian Elimination Test:\n";
			//this line of codde will put the matrix into x1+x2+x3+x4 form
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc-1; j++) {
			//Printing coefficient and variable name
			cout << matrix[i][j] << "x" << (j + 1);

			//adding + if not last variable
			if (j != nc-2)cout << "+";
		}
		//After all variables are done. print out constant at the end
		cout << " = " << matrix[i][nc-1] << "\n";
	}
	cout << "Matrix after the Gaussian Elimination Test:\n";
	ForwardElimination(matrix, nr, nc);
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc - 1; j++) {
			cout << matrix[i][j] << "x" << (j + 1);

			if (j != nc - 2)cout << "+";
		}
		cout << " = " << matrix[i][nc-1] << "\n";

			
	}
	cout << "Back substitution solution values: \n";
	BackSubstitution(matrix, nr, nc, x);
	//loop for printing the value x[i]
	for (int i = 0; i < nr; i++) {
		cout << "x" << (i + 1) << "=";
		cout << fixed << setprecision(3) << x[i] << "\n";
	}
	for (int i = 0; i < nr; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] x;

}



	



double**CreateMatrix(int nr, int nc) {
	double** A = new double* [nr];
	for (int r = 0; r < nr; r++) {
		A[r] = new double[nc];
	}
	return A;
} 
void ForwardElimination(double**A, int nr, int nc) {
	double m = 0;
	for (int k = 0; k < nr - 1; k++) {
		for (int i = k + 1; i < nr ; i++) {

			m = ((A[i][k] / A[k][k]));
			for (int j = k; j < nc; j++) {
				A[i][j] = A[i][j] - (m) * (A[k][j]);
			}

		}
	}
}

//there is something wrong with this back substitution logic
void BackSubstitution(double** A, int nr, int nc, double*x) {

	if (A[nr - 1][nr - 1] == 0) {
		cout << "Error: Division by zero at A[" << nr - 1 << "][" << nr - 1 << "]\n";
		return;
	}

	
	x[nr-1] = A[nr - 1][nc-1] / A[nr - 1][nr - 1];
	for (int k = nr - 1; k >= 0; k--) {
		if (A[k][k] == 0) {
			cout << "Error: Division by zero at A[" << k << "][" << k << "]\n";
			return;
		}
		double sum = 0;
		for (int j = k + 1; j < nr; j++) {
			sum += A[k][j] * x[j];
		}
		x[k] = (A[k][nc - 1] - sum) / A[k][k];
	}

	




}