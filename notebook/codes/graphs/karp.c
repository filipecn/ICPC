#define NN 200 // se tamanho dos vertices crescer usar lista adjacencia
#define INF 999999999 // infinito da distancia
int flow[NN][NN]; // zerar antes (para 0..)
int cap[NN][NN]; // preencher com as capacidades, deixar 0 se nao tiver ligacao
int pre[NN], que[NN], d[NN]; // anteriores, fila, distancia
int edmondsKarp(int n, int source, int sink) // nao testa se source == sink
{
	int p, q, t, i, j;
	while (1)
	{
		memset(pre, -1, sizeof(pre));
		d[source] = INF;
		p = q = 0, que[q++] = source;
		while (p<q && pre[sink] < 0) // bfs
		{
			t = que[p++]; // facil de trocar por uma lista de adjacencia, so arrumar \/
			for (i=0; i<n; i++) if (pre[i]<0 && (j=cap[t][i]-flow[t][i])) 
				pre[que[q++]=i]=t, d[i]=min(d[t],j);
		}
		if (pre[sink]<0) break;
		for (i=sink; i!=source; i=pre[i]) flow[pre[i]][i]+=d[sink],flow[i][pre[i]]-=d[sink];
	}
	for (j=i=0; i<n; j+=flow[source][i++]);
	return j;
}
