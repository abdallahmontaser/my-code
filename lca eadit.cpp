const int MAXNODE = 2e4 + 9;
vector <vector<pair<int, int>>> adj;
ll dist[MAXNODE];
int depth[MAXNODE];
pair<int,int> dp[MAXNODE][25];
void dfs(int node, ll cnt, int parent) {
	dist[node] = cnt;
	if (parent != -1) {
		depth[node] = depth[parent] + 1;
	}
	for (auto& child : adj[node]) {
		if (child.first != parent) {
			dp[child.first][0].second = child.second;
			dfs(child.first, cnt + child.second, node);
		}
	}
	dp[node][0].first = parent;
}
void Build(int n) {
	for (int k = 1; k <= 24; k++) {
		for (int u = 1; u <= n; u++) {
			if (dp[u][k - 1].first == -1) continue;
			dp[u][k].first = dp[dp[u][k - 1].first][k - 1].first;
			dp[u][k].second = min(dp[u][k - 1].second, dp[dp[u][k - 1].first][k - 1].second);
		}
	}
}
int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	int ans = INT_MAX;
	for (int k = 24; k >= 0; --k) {
		if (depth[u] - (1 << k) >= depth[v]) {
			ans = min(ans, dp[u][k].second);
			u = dp[u][k].first;
		}
	}
	if (u == v) {
		return ans;
	}
	for (int k = 24; k >= 0; --k) {
		if (dp[u][k] != dp[v][k]) {
			ans = min(ans, dp[u][k].second);
			ans = min(ans, dp[v][k].second);
			u = dp[u][k].first;
			v = dp[v][k].first;
		}
	}
	return ans;
}
