struct DSU
{
	vi rank, parent;
	int forests;
	void init(int N)
	{
		rank = parent = vi(N);
		forests = N;
		for (int i = 0; i < N; i++)
			parent[i] = i, rank[i] = 1;
	}
	int find_set(int X)
	{
		if (X == parent[X])
			return X;
		return parent[X] = find_set(parent[X]);
	}
	void link(int X, int Y)
	{
		if (rank[X] > rank[Y])
			swap(X, Y);
		parent[X] = Y;
		if (rank[X] == rank[Y])
			rank[Y]++;
	}
	bool union_sets(int X, int Y)
	{
		X = find_set(X), Y = find_set(Y);
		if (X != Y)
		{
			link(X, Y);
			forests--;
		}
		return X != Y;
	}
}DSU;


const int MAXNODE = 100009;
struct DSU
{
	int parent[MAXNODE];
	int GroupSize[MAXNODE];
	DSU()
	{
		for (int i = 0; i < MAXNODE; i++)
		{
			parent[i] = i;
			GroupSize[i] = 1;
		}
	}
	int FindLeader(int node)
	{
		if (parent[node] == node)
			return node;
		return parent[node] = FindLeader(parent[node]);
	}
	bool SameGroup(int u, int v)
	{
		return (FindLeader(u) == FindLeader(v));
	}
	void MergeGroups(int u, int v)
	{
		int leader1 = FindLeader(u);
		int leader2 = FindLeader(v);
		if (leader1 == leader2)
			return;
		if (GroupSize[leader1] > GroupSize[leader2])
		{
			parent[leader2] = leader1;
			GroupSize[leader1] += GroupSize[leader2];
		}
		else
		{
			parent[leader1] = leader2;
			GroupSize[leader2] += GroupSize[leader1];
		}
	}
	int GetSize(int node)
	{
		return GroupSize[FindLeader(node)];
	}
};
