void pontes(int p, int l)
{
	dfsnum[p] = dfslow[p] = num++;
	
	for (int i = 0; i < adj[p].size(); ++i)
	{
		int v = adj[p][i];
		if (v == l) continue;
		if (dfsnum[v] == 0)
		{
			dfs(v, p);
			if (dfslow[v] > dfsnum[p])
			{
				// p -> v eh ponte!!
			}
			if (dfslow[v] >= dfsnum[p])
			{
				// p eh vertice de articulacao! atencao, checar se ele for
				// a raiz da dfs, se for ele tem q ter mais de um filho pra valer..
			}
			dfslow[p] = min(dfslow[p], dfslow[v]);
		}
		else 
		{
			dfslow[p] = min(dfslow[p], dfsnum[v]);
		}
	}
}
int main()
{
	adj[i].clear();
	memset(dfsnum, 0, sizeof dfsnum);
	ps = 0; // tarjan apenas
	num = 1;
	for (int i = 0; i < n; ++i)
	{
		if (dfsnum[i] == 0)
		{
			dfs(i, -1); // tarjan(i, -1);
		}
	}
}

