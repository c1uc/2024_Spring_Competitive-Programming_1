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
    ll n; cin >> n;
    while(n--) {
        ll N, K; cin >> K >> N;
        vector<ll> vec(N);
        for(auto &x: vec) cin >> x;
        vector<ll> dp(20001, INF);
        dp[0] = 0;
        for(auto &x: vec) {
            for(ll i = 20000;i >= x;i--) {
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
        for(ll i = K;i <= 20000;i++) {
            if(dp[i] != INF) {
                cout << i << ' ' << dp[i] << '\n';
                break;
            }
        }
    }
}

signed main() {_
    solve();
    return 0;
}

//1
//1400
//3
//500
//1000
//2000

