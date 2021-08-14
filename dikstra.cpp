int dikstra(int from, int to)
{
	vi len(N, -1);
	int cur_node, cur_cost;
	priority_queue<node>qe;
	qe.push({ 0,from });
	while (!qe.empty())
	{
		cur_node = qe.top().cur, cur_cost = qe.top().cost, qe.pop();
		if (cur_node == to)
			return cur_cost;
		if (~len[cur_node])
			continue;
		len[cur_node] = cur_cost;
		for (auto child : adj[cur_node])
			if (len[child.first] == -1)
				qe.push({ cur_cost + child.second,child.first });
	}
}
