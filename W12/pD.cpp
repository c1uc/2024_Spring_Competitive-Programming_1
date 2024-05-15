//
// Created by duck on 2024/5/14.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve() {
    ll M, N, X, Y; cin >> M >> N >> X >> Y;
    vector<vector<ll>> adj(M + 1);
    vector<ll> count(M + 1, 0);
    vector<bool> left(M + 1, false);
    for(ll i = 0;i < N;i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        count[u]++; count[v]++;
    }
    queue<ll> q;
    q.emplace(Y);
    left[Y] = true;
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto &v: adj[u]) {
            if(count[v] > 0) {
                count[v]--;
                if(count[v] <= adj[v].size() / 2 && !left[v]) {
                    q.emplace(v);
                    left[v] = true;
                }
            }
        }
        if(u == X) {
            cout << "leave\n";
            return;
        }
    }
    cout << "stay\n";
}

signed main() {_
    solve();
    return 0;
}

//4 5 3 1
//1 2
//1 3
//2 3
//2 4
//3 4

//10 14 1 10
//1 2
//1 3
//1 4
//2 5
//3 5
//4 5
//5 6
//5 7
//5 8
//5 9
//6 10
//7 10
//8 10
//9 10

