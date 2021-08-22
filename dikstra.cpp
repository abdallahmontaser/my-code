struct node
{
	int cost, cur;
	bool operator<(const node& e)const
	{
		if (cost != e.cost)
			return cost > e.cost;
		else
			return cur > e.cur;
	}
};
void dijkstra()
{
	int N, M, u, v, cost, cur_node, cur_cost, d; cin >> N >> M;
	d = N - 1;
	vector<vector<pair<int, int>>>adj(N);
	vi len(N, -1);
	for (int i = 0; i < M; i++)
		cin >> u >> v >> cost, u--, v--, adj[u].push_back({ v,cost }), adj[v].push_back({ u,cost });
	priority_queue<node>qe;
	qe.push({ 0,0 });
	while (!qe.empty())
	{
		cur_node = qe.top().cur, cur_cost = qe.top().cost, qe.pop();
		if (~len[cur_node])
			continue;
		len[cur_node] = cur_cost;
		for (auto child : adj[cur_node])
			if (len[child.first] == -1)
				qe.push({ cur_cost + child.second,child.first });
	}
}
