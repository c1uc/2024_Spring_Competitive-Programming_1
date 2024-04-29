//
// Created by duck on 2024/4/28.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

set<ll> s;

void solve() {
    vector<vector<ll>> l = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1}
    };

    pll moves[] = {
            {0, 0},
            {0, 1},
            {1, 0},
    };

    auto func = [&](ll x, ll i, ll j, auto self) -> void {
        for(auto [dx, dy] : moves) {
            ll ni = i + dx, nj = j + dy;
            if(ni < 4 && nj < 3 && l[ni][nj] != -1) {
                ll nx = x * 10 + l[ni][nj];
                if(nx > 400) continue;
                s.insert(nx);

                if(!dx && !dy) {
                    if(!nx) continue;
                    self(nx, ni, nj, self);
                } else {
                    self(nx, ni, nj, self);
                    self(x, ni, nj, self);
                }
            }
        }
    };

    func(0, 0, 0, func);
//    for(auto i : s) cout << i << ' ';
//    cout << '\n';
    int n;
    cin >> n;
    while(n--) {
        ll x;
        cin >> x;
        ll low = *prev((s.lower_bound(x)));
        ll high = *s.lower_bound(x);
        cout << (x - low < high - x ? low : high) << '\n';
    }
}

signed main() {_
    solve();
    return 0;
}
