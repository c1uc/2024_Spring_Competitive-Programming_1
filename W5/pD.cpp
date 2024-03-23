// pD - Union-Find
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

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

int main() {_
    int n, m;
    cin >> n >> m;
    disjoint_set ds(n);
    for (int i = 0; i < m; i++) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == '=') {
            ds.unite(x, y);
        } else {
            cout << (ds.same(x, y) ? "yes\n" : "no\n");
        }
    }
}