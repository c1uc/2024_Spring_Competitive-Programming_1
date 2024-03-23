// pF - Lost Map
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

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

void solve() {
    int n;
    cin >> n;
    disjoint_set ds(n);
    priority_queue<PP, vector<PP>, greater<>> pq;
    priority_queue<P, vector<P>, greater<>> edges;

    int MAP[n][n];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> MAP[i][j];
            if(i < j) pq.emplace(MAP[i][j], P(i, j));
        }
    }
    while(!pq.empty()) {
        auto [w, p] = pq.top();
        pq.pop();
        auto [u, v] = p;
        if(!ds.same(u, v)) {
            ds.unite(u, v);
            edges.emplace(u, v);
        }
    }
    while(!edges.empty()) {
        auto [u, v] = edges.top();
        edges.pop();
        cout << u + 1 << ' ' << v + 1 << endl;
    }
}

int main() {_
    solve();
}
