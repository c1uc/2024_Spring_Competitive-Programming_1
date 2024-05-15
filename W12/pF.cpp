//
// Created by duck on 2024/5/15.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;

class node {
public:
    ll x, y, id;
    node(ll x, ll y, ll id): x(x), y(y), id(id) {}
};

void solve() {
    ll N; cin >> N;
    ll t = 1;
    vector<node> v(N+1, node(0, 0, 0));
    map<string, ll> mp;
    for(int i = 1;i <= N;++i) {
        ll x, y; string s;
        cin >> x >> y >> s;
        v[i] = node(x, y, 0);
        if(mp.find(s) == mp.end()) {
            mp[s] = t++;
        }
        v[i].id = mp[s];
    }

    auto dis = [&](ll i, ll j) {
        return abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
    };

    vector<vector<ll>> d(N + 1, vector<ll>(N + 1, INF));
    for(ll i = 0;i <= N;++i) {
        for(ll j = i;j <= N;++j) {
            d[i][j] = d[j][i] = dis(i, j);
        }
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(1 << t, INF));
    dp[0][0] = 0;
    for(int i = 0;i <= N;i++) dp[i][1 << v[i].id] = d[0][i];

    for(int i = 0;i < (1 << t);++i) {
        for(int j = 0;j <= N;++j) {
            if(!(i & (1 << v[j].id))) continue;
            for(int k = 0;k <= N;++k) {
                if(i & (1 << v[k].id)) continue;
                dp[k][i | (1 << v[k].id)] = min(dp[k][i | (1 << v[k].id)], dp[j][i] + d[j][k]);
            }
        }
    }

    cout << dp[0][(1 << t) - 1] << '\n';
}

signed main() {_
    solve();
    return 0;
}

//5
//5 9 Eevee
//20 20 Flareon
//1 1 Flareon
//1 8 Jolteon
//2 8 Umbreon
