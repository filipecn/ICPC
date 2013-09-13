double matrix[MAX][MAX];
/*Calcula o determinante de uma matriz N x N*/
double detMatrix(double matrix[MAX][MAX], int n) {

	double det;
	int i, j, k, l;
	
	n = n - 1;
	det = matrix[0][0];
	for (k = 0; k < n; k++) {
		l = k + 1;
		for (i = l; i <= n; i++) {
			for (j = l; j <= n; j++) {
				matrix[i][j] = (matrix[k][k] * matrix[i][j] - matrix[k][j] * matrix[i][k]) / matrix[k][k];
			}
		}
		det *= matrix[k + 1][k + 1];
	}
	
	return det;
}

