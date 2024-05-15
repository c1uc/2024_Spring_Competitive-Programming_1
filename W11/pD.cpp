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
    auto lis = [&](ll n, vector<ll> vec) -> pair<ll, vector<ll>> {
        vector<ll> dp(n+1, INF), pre(n+1, -1), a(n+1, -1);
        dp[0] = -INF;
        for(ll i = 0;i < n;i++) {
            auto l = lower_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();
            if(dp[l - 1] < vec[i] && vec[i] < dp[l]) {
                dp[l] = vec[i];
                a[l] = i;
                pre[i] = l == 0 ? -1 : a[l - 1];
            }
        }
        ll ans = 0;
        for(ll i = 0;i <= n;i++) if(dp[i] != INF) ans = i;
        vector<ll> res;
        for(ll i = a[ans];i != -1;i = pre[i]) res.emplace_back(vec[i]);
        reverse(res.begin(), res.end());
        return {ans, res};
    };

    ll n;
    while(cin >> n && n) {
        vector<ll> vec(n);
        for(auto &x: vec) cin >> x;
        auto [ans, res] = lis(n, vec);
        cout << ans << ' ';
        for(auto &x: res) cout << x << ' ';
        cout << '\n';
    }

}

signed main() {_
    solve();
    return 0;
}

//4 1 25 2 3
//4 1 2 2 3
//8 90 4 10000 2 18 60 172 99
//0

