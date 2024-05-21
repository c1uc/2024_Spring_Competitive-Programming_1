//
// Created by user on 2024/5/18.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int INF = 1e9;

void solve() {
    int N; cin >> N;

    vector adj(N + 1, vector<int>());
    vector edges(N - 1, pii());
    vector vis(N + 1, false);
    vector child(N + 1, 0);

    for(auto& [a, b]: edges) cin >> a >> b;

    for(auto [a, b]: edges) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto dfs = [&](int x, int t, auto self) -> int {
        vis[x] = true;
        int depth = 0;

        for(auto y: adj[x]) {
            if(vis[y] || y == t) continue;

            int d = self(y, t, self) + 1;

            if(d > depth) {
                depth = d;
                child[x] = y;
            }
        }
        return depth;
    };

    auto go = [&](int x, int k) {
        while(k--) x = child[x];
        return x;
    };

    auto f = [&](int s, int t) -> pii {
        fill(vis.begin(), vis.end(), false);
        int d = dfs(s, t, dfs);
        int v = go(s, d);

        fill(vis.begin(), vis.end(), false);
        d = dfs(v, t, dfs);
        int midp = go(v, d / 2);

        return {d, midp};
    };

    int ans = INF;
    pii removed, added;
    for(auto [x, y]: edges) {
        auto [d1, mid1] = f(x, y);
        auto [d2, mid2] = f(y, x);

        int res = max(max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
        if(res < ans) {
            ans = res;
            removed = {x, y};
            added = {mid1, mid2};
        }
    }

    cout << ans << '\n';
    cout << removed.first << ' ' << removed.second << '\n';
    cout << added.first << ' ' << added.second << '\n';
}

signed main() {_
    solve();
    return 0;
}

//14
//1 2
//1 8
//2 3
//2 4
//8 9
//8 10
//8 11
//4 5
//4 6
//4 7
//10 12
//10 13
//13 14

