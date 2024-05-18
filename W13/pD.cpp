//
// Created by user on 2024/5/18.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

void solve() {
    int N; cin >> N;
    vector adj(N + 1, vector<int>());
    vector edges(N, pii());
    for(auto& [a, b]: edges) cin >> a >> b;

    for(auto [a, b]: edges) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto f = [&](int x, int y) {
        vector vis(N + 1, 0);

        auto bfs = [&](const int r, int a) {
            queue<int> que;
            que.push(r);
            vis[r] = 1;
            vector<int> leaves;
            while(!que.empty()) {
                int u = que.front(); que.pop();
                int cnt = 0;
                for(auto v: adj[u]) {
                    if(vis[v]) continue;
                    vis[v] = 1;
                    que.push(v);
                    cnt++;
                }
                if(cnt == 0) leaves.push_back(u);
            }
            return leaves;
        };

        auto remove_leaves = [&](vector<int>& leaves) {
            queue<pii> que;
            vector width(N+1, 0);
            int last;
            for(auto u: leaves) {
                que.emplace(u, 0);
                vis[u] = 1;
            }
            while(!que.empty()) {
                auto [u, d] = que.front(); que.pop();
                last = u;
                width[u] = max(width[u], d);
                for(auto v: adj[u]) {
                    if(vis[v]) continue;
                    vis[v] = 1;
                    que.emplace(v, d + 1);
                }
            }
            int w = 0;
            for(auto e: adj[last]) w +=
        };
    };

    for(auto [x, y]: edges) {

    }

}

signed main() {_
    solve();
    return 0;
}

// 14
// 1 2
// 1 8
// 2 3
// 2 4
// 8 9
// 8 10
// 8 11
// 4 5
// 4 6
// 4 7
// 10 12
// 10 13
// 13 14
