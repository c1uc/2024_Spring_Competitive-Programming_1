//
// Created by duck on 2024/5/20.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

auto lg = [](int x) -> int {
    return x ? __builtin_clz(1) - __builtin_clz(x) : 0;
};

void solve() {
    int N; cin >> N;
    vector p(N+1, 0);
    vector child_cnt(N+1, 1);
    vector depth(N+1, 0);
    vector adj(N+1, vector<int>());
    vector jpp(N+1, vector<int>(lg(N)+1, 0));

    for(int i = 1;i <= N;i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }

    for(int i = 1;i <= N;i++) jpp[i][0] = p[i];

    auto dfs = [&](int u, auto self) -> int {
        for(int i = 1;i <= lg(N);i++) {
            jpp[u][i] = jpp[jpp[u][i-1]][i-1];
        }
        for(int v : adj[u]) {
            depth[v] = depth[u] + 1;
            child_cnt[u] += self(v, self);
        }
        return child_cnt[u];
    };

    auto is_precede = [&](int u, int v) -> bool {
        if(depth[u] > depth[v]) return false;
        for(int i = lg(N);i >= 0;i--) {
            if(depth[jpp[v][i]] >= depth[u]) v = jpp[v][i];
        }
        return u == v;
    };

    dfs(0, dfs);

    int Q; cin >> Q;
    while(Q--) {
        int K; cin >> K;
        set<int> s;
        for(int i = 0;i < K;i++) {
            int x; cin >> x;
            auto check = [&]() -> bool {
                for(auto it = s.begin();it != s.end();) {
                    if(is_precede(x, *it)) {
                        it = s.erase(it);
                    } else {
                        it++;
                    }
                }
                for(auto it = s.begin();it != s.end();) {
                    if(is_precede(*it, x)) {
                        return false;
                    }
                    it++;
                }
                return true;
            };
            if(check()) s.insert(x);
        }
        int tot = 0;
        for(auto x : s) tot += child_cnt[x];
        cout << tot << '\n';
    }
}

signed main() {_
    solve();
    return 0;
}

//5
//0 1 1 2 2
//5
//1 1
//2 4 5
//2 3 4
//3 2 3 4
//1 2
