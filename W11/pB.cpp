//
// Created by duck on 2024/5/5.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

void solve() {
    int k, n;
    cin >> k >> n;
    vector<pll> vec(k);
    for (auto &x: vec) cin >> x.first >> x.second;

    sort(vec.begin(), vec.end(),
         [](const pll &a, const pll &b) { return a.second < b.second || (a.first < b.first && a.second == b.second); });

    multiset<ll> st;
    ll ans = 0;
    for (int i = 0; i < n; i++) st.emplace(0);
    for (auto &x: vec) {
        auto it = st.lower_bound(x.first);
        if (it == st.begin()) continue;
        it--;
        st.erase(it);
        st.emplace(x.second);
        ans++;
    }
    cout << ans << '\n';
}

signed main() {_
    solve();
    return 0;
}

