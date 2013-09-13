#define N 1<<19
int seg[N], vet[N], F;
void init(int n)
{
	F = 1;
	while (F < n) F <<=1;
	--F;
	for (int i = 1; i <= n; ++i) // inicializando, opcional
		seg[i+F] = vet[i];
	for (int i = F; i; --i)
		seg[i] = max(seg[i*2], seg[i*2+1]);
}
int query(int a, int b)
{
	int r = 0, i = a+F, j = b+F;
	while (i <= j)
	{
		if (i&1) r = max(r, seg[i]);
		if (!(j&1)) r = max(r, seg[j]);
		i = (i+1)/2;
		j = (j-1)/2;
	}
	return r;
}
void update(int i, int v)
{
	i += F;
	seg[i] = v;
	i /= 2;
	while (i)
	{
		seg[i] = max(seg[i*2], seg[i*2+1]);
		i /= 2;
	}
}

