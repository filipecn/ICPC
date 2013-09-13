vector<int> adj[101], wei[101];
int n, m;
int pot[101];
int vis[101];
bool potencias() // bellman-ford, retorna falso caso tenha ciclo negativo
{
	bool g = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 0; k < adj[j].size(); ++k)
			{
				int v = adj[j][k];
				int w = wei[j][k];
				if (pot[v] > pot[j]+w)
				{
					pot[v] = pot[j]+w;
					if (i == n) g = 0;
				}
			}
		}
	}
	return g;
}
void solve(int s) // djikstra
{
	vis[s] = 0;
	priority_queue<pair<int, int> > que;
	que.push(mp(0, s));
	
	while (!que.empty())
	{
		int d = -que.top().F;
		s = que.top().S;
		que.pop();
		if (vis[s] < d) continue;
		
		for (int i = 0; i < adj[s].size(); ++i)
		{
			int v = adj[s][i];
			int w = wei[s][i]+pot[s]-pot[v];
			if (vis[v] > d+w)
			{
				vis[v] = d+w;
				que.push(mp(-(d+w), v));
			}
		}
	}
}
int main()
{
	int t; scanf("%d", &t);
	
	for (int q = 1; q <= t; ++q)
	{
		if (q > 1) printf("\n");
		printf("graph %d ", q);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) adj[i].clear(), wei[i].clear();
		while (m--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back(b);
			wei[a].push_back(c);
		}
		memset(pot, 0, sizeof pot);
		if (!potencias()) // ciclo negativo
		{
			printf("no\n");
			continue;
		}
		printf("yes\n\n");
		for (int i = 1; i <= n; ++i)
		{
			if (i > 1) printf(" ");
			printf("%d", pot[i]);
		}
		printf(" 0\n\n");
		for (int i = 1; i <= n; ++i)
		{
			memset(vis, 0x3f, sizeof vis);
			solve(i);
			for (int j = 1; j <= n; ++j)
			{
				if (j > 1) printf(" ");
				if (vis[j] == INF) printf("#");
				else printf("%d", vis[j]-pot[i]+pot[j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}

