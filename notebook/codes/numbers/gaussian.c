void gaussElimination(double matrix[MAX][MAX], int n, int m) {
	int i, j, k, l, max;
	double aux;
	i = 0;
	j = 0;
	while (i < n && j < n) {
		max = i;
		for (k = i + 1; k < n; k++) {
			if (fabs(matrix[k][j]) > fabs(matrix[max][j])) {
				max = k;
			}
		}
		if (matrix[max][j] != 0) {
			for (k = 0; k < n + m; k++) {
				aux = matrix[i][k];
				matrix[i][k] = matrix[max][k];
				matrix[max][k] = aux;
			}
			aux = matrix[i][j];
			for (k = 0; k < n + m; k++) {
				matrix[i][k] /= aux;
			}
			for (k = i + 1; k < n; k++) {
				aux = matrix[k][j];
				for (l = 0; l < n + m; l++) {
					matrix[k][l] -= aux * matrix[i][l];
				}
			}
			i++;
		}
		j++;
	}
	for (k = 0; k < m; k++) {
		for (i = n - 1; i >= 0; i--) {
			aux = 0;
			for (j = n - 1; j > i; j--) {
				aux += matrix[i][j] * matrix[j][k + n];
			}
			matrix[i][k + n] -= aux;
			matrix[i][k + n] /= matrix[i][i];
		}
	}
	// copiando resultado
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			matrix[i][j] = matrix[i][j + n];
		}
	}
}
