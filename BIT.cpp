const int N = 1e5 + 9;
int BIT[N];

int getSum(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += BIT[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}

void add(int idx, int val) {
	while (idx < N) {
		BIT[idx] += val;
		idx += (idx & (-idx));
	}

}
