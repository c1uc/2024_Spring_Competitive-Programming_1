//
// Created by duck on 2024/5/15.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N+1);

    for(int i = 0;i < M;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> color(N+1, -1), DFN(N+1), LOW(N+1), vis(N+1, 0);
    vector<vector<int>> scc(N+1);
    stack<int> stk;
    int time = 0, cnt = 0;

    auto find_scc = [&](int u, auto self) -> void {
        DFN[u] = LOW[u] = ++time;
        stk.push(u);
        vis[u] = 1;
        for(int v : adj[u]) {
            if(!DFN[v]) {
                self(v, self);
                LOW[u] = min(LOW[u], LOW[v]);
            } else if(vis[v]) {
                LOW[u] = min(LOW[u], DFN[v]);
            }
        }
        if(DFN[u] == LOW[u]) {
            int t;
            ++cnt;
            do {
                t = stk.top();
                stk.pop();
                vis[t] = 0;
                color[t] = cnt;
                scc[cnt].push_back(t);
            } while(t != u);
        }
    };

    for(int i = 1;i <= N;i++) {
        if(!DFN[i]) {
            find_scc(i, find_scc);
        }
    }

    vector<vector<int>> dag(cnt+1);
    vector<int> in(cnt+1);
    for(int i = 1;i <= N;i++) {
        for(int j : adj[i]) {
            if(color[i] != color[j]) {
                dag[color[i]].push_back(color[j]);
                in[color[j]]++;
            }
        }
    }

    queue<int> q;
    for(int i = 1;i <= cnt;i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    vector<int> dp(N + 1, 0);
    vector<int> tmp(N + 1, 0);

    auto DP = [&](int u, int c, auto self) -> void {
        vis[u] = 1;
        for(int v: adj[u]) {
            if(color[v] == color[u] && !vis[v]) {
                self(v, c + 1, self);
                dp[v] = max(c + 1, dp[v]);
            } else if(color[v] != color[u]) {
                dp[v] = max(c + 1, dp[v]);
            }
        }
        vis[u] = 0;
    };

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: scc[u]) tmp[v] = dp[v];

        for(int v: scc[u]) {
            DP(v, tmp[v], DP);
        }

        for(int v : dag[u]) {
            if(--in[v] == 0) {
                q.push(v);
            }
        }
    }

    int ans = 0;
    for(int i = 1;i <= N;i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans + 1 << '\n';
}

signed main() {_
    solve();
    return 0;
}

//7 7
//1 2
//2 3
//3 4
//4 5
//5 2
//4 6
//5 7
