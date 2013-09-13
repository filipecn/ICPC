void tarjan(int p, int l)
{
	dfsnum[p] = dfslow[p] = num++;
	pilha[ps++] = p;
	napilha[p] = 1;
	
	for (int i = 0; i < adj[p].size(); ++i)
	{
		int v = adj[p][i];
		//if (v == l) continue; // atencao, so usar isso aqui se for NAO direcionado as arestas!
		if (dfsnum[v] == 0) // tree edge
			tarjan(v, p);
		else
		{
			if (!napilha[v]) ; // cross edge
			else if (dfsnum[v] < dfsnum[p]) ; // back edge
			else ; // forward edge
		}
		if (napilha[v]) 
			dfslow[p] = min(dfslow[p], dfslow[v]);
	}
	
	if (dfsnum[p] == dfslow[p])
	{
		++res;
		while (1)
		{
			int v = pilha[ps-1];
			--ps;
			napilha[v] = 0;
			// v esta neste componente!
			if (v == p) break;
		}
	}
}

