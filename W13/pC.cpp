//
// Created by user on 2024/5/18.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve() {
    auto f = []() -> pair<vector<ll>, ll> {
        int N; cin >> N;

        vector vec(N, 0ll);
        for(auto& v: vec) cin >> v;
        const ll tot = accumulate(vec.begin(), vec.end(), 0ll);

        vector dp(tot+1, INF);
        dp[0] = 0;
        for(int i = 0;i < N;i++) for(ll j = tot;j >= vec[i];j--)
            dp[j] = min(dp[j], dp[j - vec[i]] + 1ll);

        return {dp, tot};
    };

    auto [dp1, c1] = f();
    auto [dp2, c2] = f();

    ll ans = INF;
    const ll low = min(c1, c2);
    for(ll i = 1;i <= low;i++) ans = min(ans, dp1[i] + dp2[i]);

    if(ans != INF) cout << ans << "\n";
    else cout << "impossible\n";
}

signed main() {_
    solve();
    return 0;
}

// 4 10 10 10 10
// 10 8 8 8 12 12 12 8 8 12 12
