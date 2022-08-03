#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define all(x)                 x.begin(),x.end()
#define allr(x)                x.rbegin(),x.rend()
#define clr(x,val)           memset((x),(val),sizeof(x))
const double EPS = 1e-7;
const int Mod = 1e9 + 7;
int dx[] = { 0, 0,1,-1, -1,-1,1, 1 };
int dy[] = { 1,-1,0, 0 ,-1, 1,1,-1 };
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
vl fac(1e3 + 2);
void prim_fac(ll X)
{
	for (ll i = 2; i * i <= X; i++)
	{
		while (X % i == 0)
			X /= i, fac[i]++;
	}
	if (X != 1)
		fac[X]++;
}
void solve()
{
	ll N, ans = 1; cin >> N;
	for (ll i = 2; i <= N; i++)
		prim_fac(i);
	for (int i = 2; i <= 1e3; i++)
		ans = ((ans % Mod) * ((fac[i] + 1) % Mod)) % Mod;
	cout << ans;
}
int main()
{
	fast();
	int T = 1;// cin >> T;
	while (T--)
		solve();
}
