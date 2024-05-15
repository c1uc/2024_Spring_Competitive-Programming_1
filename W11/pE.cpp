//
// Created by duck on 2024/5/10.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve() {
    ll n, w;
    while(cin >> w >> n && n && w) {
        vector<pair<ll, ll>> vec(n);
        for(auto &x: vec) cin >> x.first >> x.second;
        vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));

        for(ll i = 1;i <= n;i++) {
            for(ll j = 1;j <= w;j++) {
                dp[i][j] = dp[i - 1][j];
                if(j >= vec[i - 1].second) dp[i][j] = max(dp[i][j], dp[i - 1][j - vec[i - 1].second] + vec[i - 1].first);
            }
        }

        set<ll> res;
        for(ll i = n, j = w;i > 0;i--) {
            if(dp[i][j] != dp[i - 1][j]) {
                res.emplace(i - 1);
                j -= vec[i - 1].second;
            }
        }
        cout << res.size() << '\n';
        for(auto &x: res) cout << x << ' ';
        cout << '\n';
    }
}

signed main() {_
    solve();
    return 0;
}

//5 3
//1 5
//10 5
//100 5
//6 4
//5 4
//4 3
//3 2
//2 1

