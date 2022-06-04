#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;
int vis[N], parent[N], len[N];
vector<vector<int>> adj(N);
vector<int>path;
int n, m, k;
void dfs(int node) {
	if (path.size()) return;
	vis[node] = 1;
	for (auto child : adj[node]) {
		if (path.size() == 0 && vis[child] == 1 && (len[node] - len[child] >= k)) {
			int cur = node;
			while (cur != child) {
				path.push_back(cur);
				cur = parent[cur];
			}
			path.push_back(child);
			return;
		}
		if (!vis[child]) {
			parent[child] = node;
			len[child] = len[node] + 1;
			dfs(child);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
		if (path.size()) break;
	}
	cout << path.size() << "\n";
	for (auto& it : path) cout << it << " ";

	return 0;
}
