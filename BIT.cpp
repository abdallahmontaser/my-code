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


struct fenwick_tree {
	vector<int> BIT;
	int n;
	fenwick_tree(int n) :
			n(n), BIT(n + 1) {
	}
	int getAccum(int idx) {
		int sum = 0;
		while (idx) {
			sum += BIT[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	void add(int idx, int val) {
		assert(idx != 0);
		while (idx <= n) {
			BIT[idx] += val;
			idx += (idx & -idx);
		}
	}
	int getValue(int idx) {
		return getAccum(idx) - getAccum(idx - 1);
	}
	int getIdx(int accum) {
		int start = 1, end = (int) BIT.size() - 1, rt = -1;
		while (start <= end) {
			int mid = start + end >> 1;
			int val = getAccum(mid);
			if (val >= accum)
				rt = mid, end = mid - 1;
			else
				start = mid + 1;
		}
		return rt;
	}
};
 
