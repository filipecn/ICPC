#define N 50000
#define M 16 // tem q ser a proxima potencia de 2 de N
int vet[N];
int rmq[N][M];
void pre(int n) // precalculo do rmq
{
	for (int i = 0; i < n; ++i) // k = 0, 2^0 = 1
		rmq[i][0] = vet[i];
	for (int j = 1, k = 1; k < n; ++j, k <<= 1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i+k >= n) break;
			rmq[i][j] = max(rmq[i][j-1], rmq[i+k][j-1]);
		}
	}
}
int query(int a, int b) // query de [a,b]
{
	int k = 0, d;
	while (a+(1<<k)-1 <= b) ++k;
	--k;
	d = 1<<k;
	return max(rmq[a][k], rmq[b-d+1][k]);
}

