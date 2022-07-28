#include<bits/stdc++.h>
using namespace std;

#define ll long long

void Expert_Elde7k() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

const int SIZE = 1e5 + 9;
ll dist[SIZE];
int dp[SIZE][20], depth[SIZE];

vector <vector<pair<int, int>>> adj;

void dfs(int node, ll cnt, int parent)
{
    dist[node] = cnt;
    if (parent != -1) {
        depth[node] = depth[parent] + 1;
    }
    for (auto& child : adj[node]) {
        if (child.first != parent) {
            dfs(child.first, cnt + child.second, node);
        }
    }
    dp[node][0] = parent;
}

void Build(int n) {
    for (int k = 1; k <= 20; k++) {
        for (int u = 1; u <= n; u++) {
            if (dp[u][k - 1] == -1) continue;
            dp[u][k] = dp[dp[u][k - 1]][k - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int k = 19; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = dp[u][k];
        }
    }
    if (u == v) {
        return v;
    }
    for (int k = 19; k >= 0; --k) {
        if (dp[u][k] != dp[v][k]) {
            u = dp[u][k];
            v = dp[v][k];
        }
    }
    return dp[u][0];
}

ll dis(int u, int v) {
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

void init(int n) {
    adj = vector <vector<pair<int, int>>>(n + 1);
    for (int i = 0; i <= n; i++) {
        dist[i] = 0;
        for (int j = 0; j < 20; j++) {
            dp[i][j] = -1;
        }
    }
}

int main() {
    Expert_Elde7k();
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        init(n);
        for (int i = 1; i < n; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({ v,w });
            adj[v].push_back({ u,w });
        }
        int uu, vv, ww; cin >> uu >> vv >> ww;
        dfs(1, 0, -1);
        Build(n);
        while (m--) {
            int u, v; cin >> u >> v;
            cout << dis(u, v) << "\n";
        }
    }
    return 0;
}
