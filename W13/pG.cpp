//
// Created by duck on 2024/5/24.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

auto lg = [](const int x) {
    return x ? __builtin_clz(1) - __builtin_clz(x) : 0;
};

void solve() {
    int N, M; cin >> N >> M;
    vector depth(N+1, 0ll);
    vector adj(N+1, vector<int>());
    vector jpp(N+1, vector<int>(lg(N)+1, 0));

    auto dfs = [&](int x, int p, auto self) -> void {
        jpp[x][0] = p;
        for(int i = 1;i <= lg(N);i++) {
            jpp[x][i] = jpp[jpp[x][i-1]][i-1];
        }
        for(int y : adj[x]) {
            if(y == p) continue;
            depth[y] = depth[x] + 1;
            self(y, x, self);
        }
    };

    auto lca = [&](int x, int y) -> int {
        if(depth[x] > depth[y]) swap(x, y);
        for(int i = lg(N);i >= 0;i--) {
            if(depth[jpp[y][i]] >= depth[x]) y = jpp[y][i];
        }
        if(x == y) return x;
        for(int i = lg(N);i >= 0;i--) {
            if(jpp[x][i] != jpp[y][i]) x = jpp[x][i], y = jpp[y][i];
        }
        return jpp[x][0];
    };

    for(int i = 1;i < N;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, dfs);

    while(M--) {
        int p, q; cin >> p >> q;
        int l = lca(p, q);
        ll d = depth[p] + depth[q] - 2 * depth[l] + 1;
        cout << (d * (d + 1)) / 2 + N - d << '\n';
    }
}

signed main() {_
    solve();
    return 0;
}

//5 2
//1 2
//2 3
//2 4
//4 5
//1 3
//4 5
