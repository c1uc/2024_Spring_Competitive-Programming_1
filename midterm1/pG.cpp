//
// Created by duck on 2024/4/18.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = tuple<ll, ll, ll>;

ll solve() {
    int N, M; cin >> N >> M;

    vector<ll> W(N), C(N);
    for(auto& i: W) cin >> i;
    for(auto& i: C) cin >> i;

    ll cost = 0, ans = 0;

    auto split = [&](const ll x, const ll n) {
        const auto w = W[x];
        return (w / n + 1) * (w / n + 1) * (w % n) + (w / n) * (w / n) * (n - w % n);
    };

    auto calc = [&](const ll x, const ll n) {
        const auto c = C[x];
        const auto prev_value = split(x, n);
        const auto new_value = split(x, n + 1);
        return new_value + c - prev_value;
    };

    priority_queue<pl, vector<pl>, greater<>> pq;
    for(int i = 0; i < N; i++) {
        pq.emplace(calc(i, 1), i, 1);
        // cout << calc(i, 1) << endl;
    }

    while(M--) {
        auto [delta, x, n] = pq.top();
        if(delta >= 0) break;
        pq.pop();
        // cout << x << ' ' << n << ' ' << delta << endl;
        cost += C[x];
        pq.emplace(calc(x, n + 1), x, n + 1);
    }

    while(!pq.empty()) {
        auto [save, x, n] = pq.top(); pq.pop();
        ans += split(x, n);
    }

    return ans + cost;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// 4 1
// 5 1 3 8
// 6 15 2 30

// 3 5
// 2 3 5
// 100 100 100