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
		int leader1 = FindLeader(u), leader2 = FindLeader(v);
		if (leader1 == leader2)
			return;
		if (GroupSize[leader1] < GroupSize[leader2])
			swap(leader1, leader2);
		parent[leader2] = leader1;
		GroupSize[leader1] += GroupSize[leader2];
	}
	int GetSize(int node)
	{
		return GroupSize[FindLeader(node)];
	}
};
struct edge 
{
	int to, from, weigh;
	bool operator<(const edge& e)const
	{
			return weigh > e.weigh;
	}
};
vector<edge>edgelist;
void MST_Kruskal()
{
	DSU MST;
	vector<edge>answer;
	int mstCost = 0;
	priority_queue<edge>qe;
	for (int i = 0; i < edgelist.size(); i++)
		qe.push(edgelist[i]);
	while (!qe.empty())
	{
		edge cur = qe.top();
		qe.pop();
		if (!MST.SameGroup(cur.from, cur.to))
		{
			MST.MergeGroups(cur.from, cur.to);
			mstCost += cur.weigh;
			answer.push_back(cur);
		}
	}
}
