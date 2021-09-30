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
