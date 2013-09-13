#define N (1<<18) // 2x proxima potencia de 2 de M
#define M 100001 
int vet[M]; 
int seg[N]; // raiz comeca em 1
// exemplo de lazy propagation, query e update juntos
void prop(int p, int a, int b, LL v)
{
	seg[p] += (b-a+1)*laz[p];
	LL t = laz[p];
	laz[p] = 0;
	if (a != b) laz[p*2] += t, laz[p*2+1] += t;
}
LL query(int p, int a, int b, int x, int y, LL v)
{
	prop(p, a, b, 0);
	if (y < a || x > b) return 0;
	if (x <= a && y >= b)
	{
		laz[p] += v;
		prop(p, a, b, v);
		return seg[p];
	}	
	else
	{
		LL r = query(p*2, a, (a+b)/2, x, y, v);
		LL s = query(p*2+1, (a+b)/2+1, b, x, y, v);
		seg[p] = seg[p*2]+seg[p*2+1];
		return r+s;
	}
}
