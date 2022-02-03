const int N = 1e6 + 5;
ll fact[N], inv[N];
ll fp(ll base, ll exp)
{
	if (exp == 0)
		return 1;
	ll ans = fp(base, exp / 2);
	ans = (ans * ans) % Mod;
	if (exp % 2 != 0)
		ans = (ans * (base % Mod)) % Mod;
	return ans;
}
void build(ll n)
{
	fact[0] = 1;
	inv[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fact[i] = (i * fact[i - 1]) % Mod;
		inv[i] = fp(fact[i], Mod - 2);
	}
}
int nCr(ll n, ll r)
{
	return (((fact[n] * inv[n - r]) % Mod) * inv[r]) % Mod;
}
int nPr(ll n, ll r)
{
	return (fact[n] * inv[n - r]) % Mod;
}
