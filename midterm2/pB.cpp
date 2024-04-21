#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pl =  pair<ll, ll>;

void solve() {
	int N; cin >> N;
	stack<pl> stk;
	for(int i = 0;i < N;i++) {
		ll t; cin >> t;
		ll mx = t, mn = t;
		while(!stk.empty() && stk.top().second > t) {
			ll a = stk.top().first, b = stk.top().second; stk.pop();
			mx = max(mx, b);
			mn = min(mn, a);
		}
		stk.emplace(mn, mx);
	}
	cout << stk.size() << '\n';
}

int main() {
	solve();
	return 0;
}

// 9
// 1 2 2 5 4 3 7 9 8

// 6
// 2 9 12 15 20 20

// 10
// 3 1 3 7 7 15 9 16 20 20
