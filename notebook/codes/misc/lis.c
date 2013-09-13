int vet[N]; // comeca sempre do 1
int lis[N]; // vetor lis
int bak[N]; // bak[i] eh o indice do ultimo elemento posto em lis[i], so pra ficar mais facil de usar o lower_bound
int pre[N]; // pre[i] eh o indice pro elemento anterior
int solve(int* vet, int n) // lis
{
	for (int i = 1; i <= n; ++i) lis[i] = INF;
	bak[0] = 0;
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		int v = vet[i];
		int p = (int)(lower_bound(lis+1, lis+n+1, v)-lis);
		bak[p] = i;
		pre[i] = bak[p-1];
		lis[p] = v;
		res = max(res, p);
	}
	return res;
}
int main()
{
	int res = solve(vet, n);
	// recupera a resposta
	int v = bak[res];
	vector<int> print;
	while (v != 0)
	{
		print.push_back(vet[v]);
		v = pre[v];
	}
	reverse(print.begin(), print.end());
}
