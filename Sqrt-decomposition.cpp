#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

void Candidate_Elde7k() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}

int main() {
	Candidate_Elde7k();

    int n; cin >> n;
    vector<int> ve(n);
    for (auto& it : ve) {
        cin >> it;
    }

    // preprocessing
    int len = (int)sqrt(n + 0.0) + 1; // size of the block and the number of blocks
    vector<int> b(len);
    for (int i = 0; i < n; ++i)
        b[i / len] += ve[i];

    int q; cin >> q;

    // first implementation  ( slower )
    while (q--) {
        int l, r; cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; ) {
            if (i % len == 0 && i + len - 1 <= r) {
                // if the whole block starting at i belongs to [l, r]
                sum += b[i / len];
                i += len;
            }
            else {
                sum += ve[i];
                i++;
            }
        }
        cout << sum << "\n";
    }


    // second implementation  ( faster )
    while (q--) {
        int l, r; cin >> l >> r;
        int sum = 0;
        int c_l = l / len;
        int c_r = r / len;
        if (c_l == c_r) {
            while (l <= r) {
                sum += ve[l++];
            }
        }
        else {
            for (int i = l, end = (c_l + 1) * len - 1; i <= end; i++) {
                sum += ve[i];
            }
            for (int i = c_l + 1; i <= c_r - 1; ++i) {
                sum += b[i];
            }
            for (int i = c_r * len; i <= r; ++i) {
                sum += ve[i];
            }
        }
        cout << sum << "\n";
    }
}
