//
// Created by user on 2024/5/17.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr int INF_i = 1e9;
constexpr ll INF_ll = 1e18;

void solve() {
    int N; cin >> N;
    vector<P> vec(N);
    ll tot = 0;

    auto calc = [&](const ll x, const ll y, const ll z) {
        const ll c = (x + y + z) / 2 - x + 1;
        if(c > z) return INF_ll;
        return c > 0 ? c : 0;
    };

    for(int i = 0;i < N;i++) {
        ll v, x, y, z; cin >> v >> x >> y >> z;
        vec[i] = {v, calc(x, y, z)};
        tot += v;
    }

    vector dp(tot + 1, INF_ll);
    dp[0] = 0;

    for(int i = 0;i < N;i++) for(ll j = tot;j >= vec[i].first;j--)
        dp[j] = min(dp[j], dp[j - vec[i].first] + vec[i].second);

    ll ans = INF_ll;
    for(ll i = tot / 2 + 1;i <= tot;i++) ans = min(ans, dp[i]);

    if(ans == INF_ll) cout << "impossible\n";
    else cout << ans << "\n";
}

signed main() {_
    solve();
    return 0;
}

// 3
// 32 0 0 20
// 32 0 0 20
// 64 0 0 41
