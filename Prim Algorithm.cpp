#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
struct Edge 
{
    int from, to, w;
    bool operator<(const Edge& e)const
    {
        return w > e.w;
    }
};
int N, M, u, v, c, mstcost = 0;
vector<vector<Edge>> adj;
vector< Edge>edges;
void prim()
{
    vi vis(N, 0);
    priority_queue< Edge>qe;
    qe.push({ -1,0,0 });
    while (!qe.empty())
    {
        Edge e = qe.top();
        qe.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        mstcost += e.w;
        if (~e.from)
            edges.push_back(e);
        for (auto child : adj[e.to])
            if (!vis[child.to])
                qe.push(child);
    }
    cout << mstcost << "\n";
    for (auto& it : edges)
        cout << it.from+1 << " " << it.to+1 << "\n";
}
int main()
{
    cin >> N >> M;
    adj = vector<vector<Edge>>(N);
    for (int i = 0; i < M; i++)
        cin >> u >> v >> c, u--, v--, adj[u].push_back({ u, v, c }), adj[v].push_back({ v, u, c });
    prim();
}
