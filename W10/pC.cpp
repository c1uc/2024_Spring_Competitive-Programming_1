//
// Created by duck on 2024/4/28.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;

void solve() {
    ll a, b; cin >> a >> b;

    auto fast_exp = [](ll a, ll b, ll m) -> ll {
        ll res = 1;
        while(b) {
            if(b & 1) res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    };

    cout << (a & 1 ? 0 : fast_exp(a / 2, b, a)) << '\n';
}

signed main() {_
    solve();
    return 0;
}
