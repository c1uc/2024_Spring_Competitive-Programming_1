// pH - Minimum Spanning Tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

struct disjoint_set {
    vector<int> parent, rank;
    explicit disjoint_set(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve(int n, int m) {
    priority_queue<PP, vector<PP>, greater<>> pq;
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(v < u) swap(v, u);
        pq.emplace(w, P(u, v));
    }
    disjoint_set ds(n);
    ll ans = 0;

    priority_queue<P, vector<P>, greater<>> edges;
    while(!pq.empty()) {
        auto [w, p] = pq.top();
        pq.pop();
        auto [u, v] = p;
        if(!ds.same(u, v)) {
            ds.unite(u, v);
            ans += w;
            edges.emplace(u, v);
        }
    }
    if(edges.size() == n - 1) {
        cout << ans << endl;
        while(!edges.empty()) {
            auto [u, v] = edges.top();
            edges.pop();
            cout << u << " " << v << endl;
        }
    }
    else cout << "Impossible\n";
}

int main() {
    int m, n;
    while(cin >> n >> m && n) solve(n, m);
}

