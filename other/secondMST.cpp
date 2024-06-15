//
// Created by duck on 2024/6/7.
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

struct Edge {
    int u, v, c, idx;

    Edge(int u, int v, int c, int idx) : u(u), v(v), c(c), idx(idx) {}
    bool operator<(const Edge &e) const {
        return c < e.c;
    }
};

class DSU {
    vector<int> p, sz;
public:
    explicit DSU(int N) : p(N), sz(N, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

void solve() {
    int N, M; cin >> N >> M;
    vector<Edge> edges;
    vector<int> in_tree(M + 1, 0), depth(N + 1, 0), vis(N + 1, 0);
    vector adj(N + 1, vector<pair<int, int>>());
    vector jpp(N + 1, vector<int>(lg(N) + 1, 0));
    vector heaviest_edge(N + 1, vector<int>(lg(N) + 1, 0));

    for(int i = 0;i < M;i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.emplace_back(a, b, c, i);
    }

    auto sorted_edges = edges;
    sort(sorted_edges.begin(), sorted_edges.end());
    DSU dsu(N + 1);
    ll ans = 0;

    for(int i = 0;i < M;i++) {
        auto [a, b, c, idx] = sorted_edges[i];
        if(dsu.unite(a, b)) {
            in_tree[idx] = 1;
            ans += c;
            adj[a].emplace_back(b, c);
            adj[b].emplace_back(a, c);
        }
    }

    auto dfs = [&](int x, int p, int d, auto self) -> void {
        vis[x] = 1;
        for(auto [y, c] : adj[x]) {
            if(vis[y]) continue;
            jpp[y][0] = x;
            heaviest_edge[y][0] = c;
            depth[y] = d + 1;
            self(y, x, d + 1, self);
        }
    };

    dfs(1, 0, 0, dfs);
    for(int i = 1;i <= lg(N);i++) {
        for(int j = 1;j <= N;j++) {
            jpp[j][i] = jpp[jpp[j][i - 1]][i - 1];
            heaviest_edge[j][i] = max(heaviest_edge[j][i - 1], heaviest_edge[jpp[j][i - 1]][i - 1]);
        }
    }

    auto lca = [&](int u, int v) -> pair<int, int> {
        if(depth[u] < depth[v]) swap(u, v);
        int heaviest = 0;
        for(int i = lg(N);i >= 0;i--) {
            if(depth[jpp[u][i]] >= depth[v]) {
                heaviest = max(heaviest, heaviest_edge[u][i]);
                u = jpp[u][i];
            }
        }

        if(u == v) return {u, heaviest};
        for(int i = lg(N);i >= 0;i--) {
            if(jpp[u][i] != jpp[v][i]) {
                heaviest = max({heaviest, heaviest_edge[u][i], heaviest_edge[v][i]});
                u = jpp[u][i], v = jpp[v][i];
            }
        }
        return {jpp[u][0], max({heaviest, heaviest_edge[u][0], heaviest_edge[v][0]})};
    };

    auto mst_containing_edge = [&](int i) {
        if(in_tree[i]) return ans;
        auto [a, b, c, idx] = edges[i];
        auto [l, heaviest] = lca(a, b);
        return ans - heaviest + c;
    };

    for(int i = 0;i < M;i++) {
        cout << mst_containing_edge(i) << '\n';
    }
}

signed main() {_
    solve();
    return 0;
}
