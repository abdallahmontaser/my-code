#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define un(ve)                 ve.resize(unique(ve.begin(),ve.end())-ve.begin())
using namespace std;
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return (b / gcd(a, b))*a;
}
int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int lcm(int a, int b)
{
	int icma = max(a, b);
	while (true)
	{
		if (icma % a == 0 && icma % b == 0)
		{
			return icma;
		}
		icma++;
	}
}
void solve()
{
	cout << gcd_recursion(45, 10) << " " << gcd(45, 10) << "\n";
	cout << ((45 * 10) / gcd(45, 10)) << " " << lcm(45, 10);
}
int main()
{
	fast();
	int T = 1; // cin >> T;
	while (T--)
	{
		solve();
	}
}
