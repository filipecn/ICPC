vector<pair<int, int> > adj[100001];
int num[100001]; // numeracao dos vertices (comeca em 1)
int inv[100001]; // numeracao inversa dos vertices (comeca em 1)
int oco[100001][2]; // ocorrencia a esquerda e a direita (comeca em 1)
int seg[600001]; // 2 vezes a proxima potencia de 2 do tamanho da entrada
int now, x;	 // o vetor vai ocupar 2*n-1, dai a arvore tem q ser 2x isso
void update(int p, int a, int b, int i, int val)
{
	if (a == b && a == i) seg[p] = val;
	else if (a > i || b < i) return;
	else
	{
		update(p*2, a, (a+b)/2, i, val);
		update(p*2+1, (a+b)/2+1, b, i, val);
		seg[p] = min(seg[p*2], seg[p*2+1]);
	}
}
int query(int p, int a, int b, int i, int j)
{
	if (j < a || i > b) return INT_MAX;
	if (i <= a && j >= b) return seg[p];
	else return min(query(p*2, a, (a+b)/2, i, j), query(p*2+1, (a+b)/2+1, b, i, j));
}
void numerate(int p, int l)
{
	num[p] = ++now;
	inv[num[p]] = p;
	if (oco[p][0] == -1) oco[p][0] = oco[p][1] = ++x;
	update(1, 1, n*2-1, x, num[p]);
	for (int i = 0; i < adj[p].size(); ++i)
	{
		int v = adj[p][i].F;
		if (v == l) continue;
		numerate(v, p);
		oco[p][1] = ++x;
		update(1, 1, n*2-1, x, num[p]);
	}
}
int main()
{
	// inicializacao
	memset(oco, -1, sizeof oco);
	now = x = 0;
	numerate(1, -1);
	// uso
	if (num[a] > num[b]) swap(a,b);
	int lca = query(1, 1, n*2-1, oco[a][0], oco[b][1]);
	lca = inv[lca];
}

