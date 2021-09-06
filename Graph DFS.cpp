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
//directed graph
int cycle = 0;
vector<vi>adj;
vi color;
void dfs(int node)
{
	color[node] = 1;
	for (auto child : adj[node])
	{
		if (color[child] == 0)
			dfs(child);
		else if (color[child] == 1)
			cycle = 1;
	}
	color[node] = 2;
}

// **************************************************************************************************
//undirected graph
int cycle = 0;
vector<vi>adj;
vi  vis;
void dfs(int node,int par)
{
	vis[node] = 1;
	for (auto child : adj[node])
	{
		if (child != par)
		{
			if (vis[child] == 0)
				dfs(child,node);
			else
				cycle = 1;
		}
	}
}

// **************************************************************************************************
//Checking a graph for acyclicity and finding a cycle in O(M)
int is_cycle = 0, cycle_start, cycle_end;
vector<vi>adj;
vi color, parent;
void dfs(int node)
{
	color[node] = 1;
	for (auto child : adj[node])
	{
		if (color[child] == 0)
			parent[child] = node, dfs(child);
		else if (color[child] == 1)
			cycle_end = node, cycle_start = child, is_cycle = 1;
	}
	color[node] = 2;
}
void genrate_cycle_path()
{
	vi cycle;
	cycle.push_back(cycle_start);
	int d = cycle_end;
	while (d != cycle_start)
		cycle.push_back(d), d = parent[d];
	cycle.push_back(cycle_start);
	reverse(cycle.begin(), cycle.end());
	for (int it : cycle)
		cout << it+1 << " ";
}
