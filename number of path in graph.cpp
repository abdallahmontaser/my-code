#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

void Candidate_Elde7k() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

int n;
vector<vector<int>>adj;
vector<ll>ans, sub;

int dfs(int node, int prev) {
    int cnt = 1;
    for (auto& child : adj[node]) {
        if (child != prev) {
            int temp = dfs(child, node);
            cnt += temp;
            sub[node] += temp;
            ans[node] += ((n - sub[node]) * sub[child]);
        }
    }
    return cnt;
}

int main() {
    Candidate_Elde7k();
    cin >> n;
    adj = vector<vector<int>>(n + 5);
    ans = vector<ll>(n + 5, n - 1);
    sub = vector<ll>(n + 5, 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    int q; cin >> q;
    while (q--) {
        int u; cin >> u;
        cout << ans[u] << "\n";
    }
    return 0;
}
