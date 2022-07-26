#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 2000000011ll;
const ll BASE = 53ll;
const ll BASE_INV = 1283018875ll;

ll fast_pow(ll N, ll M) {
	if (M == 0)
		return 1;
	ll sq = fast_pow(N, M / 2);
	sq = ((sq % MOD) * (sq % MOD)) % MOD;
	sq %= MOD;
	if (M % 2) {
		sq = ((sq % MOD) * (N % MOD)) % MOD;
	}
	return (sq % MOD);
}

ll removeAt(ll code, int idx, int val) {
	return (code - (val * fast_pow(BASE, idx)) % MOD + MOD) % MOD;
}

ll addAt(ll code, int idx, int val) {
	return (code + (val * fast_pow(BASE, idx)) % MOD) % MOD;
}

ll shiftLeft(ll code) {
	return (code * BASE) % MOD;
}

ll shifRight(ll code) {
	return (code * BASE_INV) % MOD;
}

ll getHashValue(string pat) {
	int n = pat.size();
	ll patCode = 0;
	for (int i = 0; i < n; i++) {
		patCode = shiftLeft(patCode);
		patCode = addAt(patCode, 0, (int)pat[i]);
	}
	return patCode;
}

void pattern_search(string main, string pat) {
	int n = pat.size();
	int m = main.size();
	ll patCode = 0;
	for (int i = 0; i < n; i++) {
		patCode = shiftLeft(patCode);
		patCode = addAt(patCode, 0, (int)pat[i]);
	}
	ll subCode = 0;
	for (int i = 0; i < m; i++) {
		if (i - n >= 0) {
			subCode = removeAt(subCode, m - 1, (int)main[i - n]);
		}
		subCode = shiftLeft(subCode);
		subCode = addAt(subCode, 0, (int)main[i]);
	}
}

int main() {
	
	return 0;
}
