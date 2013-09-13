int g[NN][NN], A[NN], B[NN]; // g eh o grafo, matriz adjacencia, zerar A e B!
bool v[NN]; // visitados, zerar tambem
int dfs(int x, int b) //
{
	if (x == 0) return 1;
	v[x] = 1;
	for (int j = 1; j <= b; j++) if (g[x][j] && !v[B[j]] && dfs(B[j], b)) 
	{
		B[j] = x;
		A[x] = j;
		return 1;
	}
	return 0;
}
int main() 
{
	//...
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
	int res = 0;
	for (int i = 1; i <= a; i++)  // a = tamanho de A, b = tamanho de B
	{
		memset(v, 0, sizeof v);
		if (dfs(i, b)) res++;
	}
	//...
}
