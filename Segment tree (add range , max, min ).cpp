#include<bits/stdc++.h>
using namespace std;

#define ll long long

void Expert_Elde7k() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}

struct segtree {

	int size;
	vector<pair<ll, ll>>values;
	vector<ll>sums;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2ll;
		values.assign(2 * size, { 0LL ,0LL });
		sums.assign(2 * size, 0LL);
	}

	pair<int, int> calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return { INT_MAX ,INT_MIN };
		if (lx >= l && rx <= r) return values[x];
		int mid = (lx + rx) / 2;
		pair<ll, ll> s1 = calc(l, r, 2 * x + 1, lx, mid);
		pair<ll, ll> s2 = calc(l, r, 2 * x + 2, mid, rx);
		return { sums[x] + min(s1.first, s2.first), sums[x] + max(s1.second,s2.second) };
	}

	pair<int, int> calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}

	void add(int l, int r, int v, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return;
		if (lx >= l && rx <= r) {
			sums[x] += v;
			values[x].first += v;
			values[x].second += v;
			return;
		}
		int mid = (lx + rx) / 2;
		add(l, r, v, 2 * x + 1, lx, mid);
		add(l, r, v, 2 * x + 2, mid, rx);
		values[x].first = sums[x] + min(values[2 * x + 1].first, values[2 * x + 2].first);
		values[x].second = sums[x] + max(values[2 * x + 1].second, values[2 * x + 2].second);
	}

	void add(int l, int r, int v) {
		add(l, r, v, 0, 0, size);
	}
};

int main() {
	Expert_Elde7k();
	
	return 0;
}
