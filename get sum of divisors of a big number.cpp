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
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
void file()
{
	freopen("math.in", "rt", stdin);
}
vi primes;
bool is_prime(int X)
{
	for (int i = 2; i * i <= X; i++)
		if (X % i == 0)
			return false;
	return true;
}
void  genrate()
{
	for (int i = 2; i <= 1e6; i++)
	{
		if (is_prime(i))
			primes.push_back(i);
	}
}
void solve()
{
	int N; cin >> N;
	ll X, tem, pow, ans = 1;
	map<ll, ll>fact;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		for (auto it : primes)
		{
			if (it * it > X)
				break;
			while (X % it == 0)
				X /= it, fact[it]++;
		}
		if (X > 1)
			fact[X]++;
	}
	for (auto it : fact)
	{
		tem = 1, pow = 1;
		for (int j = 1; j <= it.second; j++)
			pow *= it.first, pow %= Mod, tem += pow;
		tem %= Mod;
		ans *= tem;
		ans %= Mod;
	}
	cout << ans << "\n";
}
int main()
{
	file();
	fast();
	genrate();
	int T = 1; cin >> T;
	while (T--)
		solve();
}
