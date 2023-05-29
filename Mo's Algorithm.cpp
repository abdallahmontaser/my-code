#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

void Candidate_Elde7k() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

const int N = 2e5 + 9;
const int SIZE = 1e6 + 9;
ll ans = 0;
int arr[N], freq[SIZE];
int BLOCK_SIZE;

void remove(int val) {
    ans -= ((freq[val] * 1ll * freq[val]) * 1ll * val);
    freq[val]--;
    ans += ((freq[val] * 1ll * freq[val]) * 1ll * val);
}
void add(int val) {
    ans -= ((freq[val] * 1ll * freq[val]) * 1ll * val);
    freq[val]++;
    ans += ((freq[val] * 1ll * freq[val]) * 1ll * val);
}
ll get_answer() {
    return ans;
}

struct Query {
    int l, r, k, idx;
    bool operator < (Query other) {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE) return l < other.l;
        return l / BLOCK_SIZE % 2 ? r > other.r : r < other.r;
    }
};


int main() {
    Candidate_Elde7k();

    int n, q; cin >> n >> q;
    vector<Query> queries(q);
    BLOCK_SIZE = (int)sqrt(n + .0) + 1;
    vector<ll> answers(q);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end());
    int cur_l = 0;
    int cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(arr[cur_l]);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(arr[cur_r]);
        }
        while (cur_l < q.l) {
            remove(arr[cur_l]);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(arr[cur_r]);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    for (auto& it : answers)cout << it << "\n";
}
