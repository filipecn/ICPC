void invertMatrix(double matrix[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j + n] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		matrix[i][i + n] = 1;
	}
	printMatrix(matrix, n, 2*n);
	gaussElimination(matrix, n, n);
	
}
