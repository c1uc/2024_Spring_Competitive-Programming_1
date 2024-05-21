//
// Created by duck on 2024/5/19.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve() {
    int N; cin >> N;

    vector adj(N + 1, vector<int>());
    vector dist(N + 1, 0ll);
    vector jpp(N + 1, vector<int>(20, 0));

    for(int i = 0;i < N - 1;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](int u, int p, auto self) -> void {
        dist[u] = dist[p] + 1;
        jpp[u][0] = p;

        for(int i = 1;i < 20;i++){
            jpp[u][i] = jpp[jpp[u][i - 1]][i - 1];
        }

        for(int v : adj[u]) {
            if(v == p) continue;
            self(v, u, self);
        }
    };

    dfs(1, 0, dfs);

    auto lca = [&](int u, int v) -> int {
        if(dist[u] < dist[v]) swap(u, v);
        for(int i = 19;i >= 0;i--) {
            if(dist[jpp[u][i]] >= dist[v]) u = jpp[u][i];
        }
        if(u == v) return u;
        for(int i = 19;i >= 0;i--) {
            if(jpp[u][i] != jpp[v][i]) {
                u = jpp[u][i];
                v = jpp[v][i];
            }
        }
        return jpp[u][0];
    };

    ll tot = 0;
    for(int i = 1;i <= N;i++) {
        for(int j = 2 * i;j <= N;j += i) {
            int l = lca(i, j);
            tot += dist[i] + dist[j] - 2 * dist[l] + 1;
        }
    }
    cout << tot << '\n';
}

signed main() {_
    solve();
    return 0;
}

//10
//3 4
//3 7
//1 4
//4 6
//1 10
//8 10
//2 8
//1 5
//4 9
