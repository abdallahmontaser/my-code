ll get_sum_div(ll x){
	ll ans = 0;
	for (ll left = 1, right; left <= x; left = right + 1){
		right = x / (x / left);
		ans += (x / left)*(left + right)*(right - left + 1) / 2;
	}
	return ans;
}
