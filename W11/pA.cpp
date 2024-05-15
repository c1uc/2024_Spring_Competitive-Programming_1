//
// Created by duck on 2024/5/5.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<ld> vec(N);
    for(auto &x : vec) cin >> x;

    priority_queue<ld, vector<ld>, greater<>> pq;
    ld tmp;
    for(int i = 0;i < M;i++) {
        cin >> tmp;
        pq.emplace(tmp);
    }

    for(int i = 0;i < K;i++) {
        cin >> tmp;
        pq.emplace(tmp / sqrt(2));
    }

    sort(vec.begin(), vec.end());
    ll ans = 0;
    for(auto& it: vec) {
        if(pq.empty()) break;
        if(it > pq.top()) {
            ans++;
            pq.pop();
        }
    }
    cout << ans << '\n';
}

signed main() {_
    solve();
    return 0;
}
