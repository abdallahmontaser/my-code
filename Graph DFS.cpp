int is_bipartite = 1;
vector<vi>adj;
vi col;
void bipartite(int node, int color)
{
	col[node] = color;
	for (auto child : adj[node])
	{
		if (col[child] == -1)
			bipartite(child, !color);
		else
			is_bipartite &= (col[node] != col[child]);
	}
}

// **************************************************************************************************
//cycle directed graph
int cycle_start = -1, cycle_end;
vector<vi>adj;
vi vis(1e5,0), parent(1e5,-1);
void dfs(int node)
{
	color[node] = 1;
	for (int child : adj[node])
	{
		if (color[child] == 0) 
			parent[child] = node, dfs(child);
		else if (color[child] == 1)
			cycle_end = node, cycle_start = child;
	}
	color[node] = 2;
}

// **************************************************************************************************
//cycle undirected graph
int cycle_start = -1, cycle_end;
vi vis(1e5,0), parent(1e5,-1);
void dfs(int node, int par)
{
	vis[node] = 1;
	for (int child : adj[node])
		if (child != par)
			if (vis[child])
				cycle_end = child, cycle_start = node;
			else
				parent[child] = node, dfs(child, node);
}

// **************************************************************************************************
//Checking a graph for acyclicity and finding a cycle in O(M)
int cycle_start = -1, cycle_end;
void genrate_cycle_path()
{
	vi cycle;
	cycle.push_back(cycle_start);
	int d = cycle_end;
	while (d != cycle_start)
		cycle.push_back(d), d = parent[d];
	cycle.push_back(cycle_start);
	reverse(cycle.begin(), cycle.end());
	cout << cycle.size() << "\n";
	for (int it : cycle)
		cout << it + 1 << " ";
}
