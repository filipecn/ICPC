#define N 802
#define INF 0x3f3f3f3f
int cap[N][N], cost[N][N]; // so precisa preencher o cap e cost!! nao esquece de zerar..
int lim[N], id[N], pre[N], dist[N], flow[N][N]; // nao meche aqui nem nos vectors abaixo!!!
vector<int> adj[N]; vector<int> wei[N]; // o codigo vai montar a lista de adjacencia baseado no cap e cost!
pair<int, int> maxFlowMinCost(int S, int T, int n)
{
	for (int i = 0; i < n; ++i) adj[i].clear(), wei[i].clear();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			flow[i][j] = 0;
			if (cap[i][j]) 
				adj[i].push_back(j), wei[i].push_back(cost[i][j]),
				adj[j].push_back(i), wei[j].push_back(-cost[i][j]);
		}
	}

	pair<int, int> res = make_pair(0, 0);
	
	while (1)
	{
		for (int i = 0; i < n; ++i)
		{
			dist[i] = lim[i] = INF;
			id[i] = 0; pre[i] = -1;
		}
		deque<int> que;
		dist[S] = 0;
		que.push_front(S);
		while (!que.empty())
		{
			int p = que.front();
			que.pop_front();
			id[p] = 2;
			for (int i = 0; i < adj[p].size(); ++i)
			{
				int v = adj[p][i];
				int f = cap[p][v]-flow[p][v];
				if (f)
				{
					int c = wei[p][i]+dist[p];
					if (c < dist[v])
					{
						dist[v] = c;
						if (id[v] == 0) que.push_back(v);
						else if (id[v] == 2) que.push_front(v);
						id[v] = 1;
						pre[v] = p;
						lim[v] = min(lim[p], f);
					}
				}
			}
		}
		if (dist[T] == INF) break;
		int f = lim[T];
		res.first += f*dist[T];
		res.second += f;
		for (int p = T; p != S; p = pre[p])
			flow[pre[p]][p] += f, flow[p][pre[p]] -= f;
	}
	
	return res;
}

