#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

void Candidate_Elde7k() {
    //freopen("binary.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

const int N = 1e7 + 5;

string pat, str;
int f[N];

int newL(int l, char ch) {
    while (l && ch != pat[l]) l = f[l - 1];
    return l += (ch == pat[l]);
}

void computeF() {
    if (!pat[0]) return;
    f[0] = 0;
    for (int i = 1; pat[i]; i++)
        f[i] = newL(f[i - 1], pat[i]);
}

int  match() {
    computeF();
    int l = 0;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        l = newL(l, str[i]);
        if (!pat[l]) cnt++;
    }
    return cnt;
}

int main() {
    Candidate_Elde7k();
    getline(cin, str);
    getline(cin, pat);
    string temp = pat;
    int k; cin >> k;
    int l = 1, r = pat.size(), mid, ans = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        pat = temp.substr(0, mid);
        if (match() >= k) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    if (ans == -1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << temp.substr(0, ans) << "\n";
    }
    return 0;
}
