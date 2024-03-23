// pA - Where's My Internet??

#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct disjoint_set {
    vector<int> rank, parent;
    disjoint_set(int n): rank(n+1, 1), parent(n+1) {
        for(int i = 1;i <= n;i++) parent[i] = i;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    disjoint_set ds(n);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        ds.unite(a, b);
    }

    bool flag = true;
    for(int i = 1;i <= n;i++) if(!ds.same(i, 1)) {cout << i << endl; flag = false;}
    if(flag) cout << "Connected" << endl;
}

int main() {_
    solve();
    return 0;
}
