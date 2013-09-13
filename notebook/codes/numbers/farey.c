int t[100001], a, b, n; // t deve ser do tamanho de n+1
// dado a fracao a/b com limitante do denominador n, determina a posicao na seq de farey em O(nlogn)
int solve() 
{
	for (int i = 1; i <= n; ++i)
		t[i] = (LL)a*i/b;
	for (int i = 1; i <= n; ++i)
		for (int j = 2; i*j <= n; ++j)
			t[i*j] -= t[i];
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += t[i];
	return res; // indexado a partir do 0
}
// gera todas as fracoes da sequencia de farey com denominador limitante n, complexidade linear
void gen(int n)
{
	int p = 2;
	res[0][0] = 0; res[0][1] = 1;
	res[1][0] = 1; res[1][1] = n;
	while (res[p-1][0] <= n)
	{
		int k = (n+res[p-2][1])/(res[p-1][1]);
		res[p][0] = k*res[p-1][0]-res[p-2][0]; res[p][1] = k*res[p-1][1]-res[p-2][1];
		++p;
	}
}
