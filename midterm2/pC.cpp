//
// Created by duck on 2024/4/21.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAX_N = 5e5;
constexpr ll INF = 1e18;

vector arr(4 * MAX_N + 1, -INF);


void solve() {
    ll N, M; cin >> N >> M;
    vector<ll> V(N + 2, -INF);
    V[1] = 0;
    for(int i = 2;i <= N + 1;i++) cin >> V[i];

    auto build = [&](const ll x, const ll l, const ll r, auto self) {
        if(l == r) return arr[x] = V[l];

        // cout << l << ' ' << r << endl;
        ll mid = (l + r) >> 1;

        ll L = self(x << 1, l, mid, self);
        ll R = self(x << 1 | 1, mid + 1, r, self);

        return arr[x] = max(L, R);
    };

    build(1, 1, N + 1, build);
    map<ll, ll> mp;

    auto query = [&](const ll x, const ll l, const ll r, const ll tl, const ll tr, auto self) {
        if(l > r) return -INF;
        if(l == tl && r == tr) return arr[x];

        // cout << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
        const ll mid = (tl + tr) >> 1;
        const ll L = self(x << 1, l, min(mid, r), tl, mid, self);
        const ll R = self(x << 1 | 1, max(l, mid + 1), r, mid + 1, tr, self);

        return max(L, R);
    };

    auto build_table = [&]() {
        for(int l = 1;l <= N;l++) {
            ll idx = 1;
            ll ans = 0;
            while(idx != N + 1) {
                ll new_pos = min(idx + l, N + 1);
                ans += (query(1, idx, new_pos, 1, N + 1, query) - V[idx]);
                idx = new_pos;
            }
            mp[l] = ans;
        }
    };

    build_table();

    // for(int i = 1;i <= N + 1;i++) for(int j = i;j <= N + 1;j++) cout << query(1, i, j, 1, N + 1, query) << ' ';

    while(M--) {
        ll w, l; cin >> w >> l;

        cout << (N + mp[l]) * w << '\n';
    }
}

int main() {
    solve();
    return 0;
}

// 5 3
// -30 12 60 -43 -10
// 7 2
// 10 1
// 3 4