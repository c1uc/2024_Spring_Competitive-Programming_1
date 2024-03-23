// pE - Almost Union-Find
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

struct disjoint_set {
    vector<int> parent, rank;
    vector<ll> sum;
    map<int, int> mp;
    int record = 0;
    explicit disjoint_set(int n, int m): parent(n + m + 1), rank(n + m + 1, 1), sum(n + m + 1, 0), record(n) {
        for(int i = 1;i <= n + m;i++) parent[i] = i, sum[i] = i;
        for(int i = 1;i <= n;i++) mp[i] = i;
    }

    int Find(int x) {
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        x = Find(mp[x]);
        y = Find(mp[y]);
        if(x == y) return;
        if(rank[x] < rank[y]) {
            parent[x] = y;
            rank[y] += rank[x];
            sum[y] += sum[x];
        } else {
            parent[y] = x;
            rank[x] += rank[y];
            sum[x] += sum[y];
        }
    }

    void Insert(int x, int y) {
        int px = Find(mp[x]);
        int py = Find(mp[y]);

        sum[px] -= x;
        rank[px]--;

        sum[py] += x;
        rank[py]++;

        mp[x] = ++record;
        parent[record] = py;
    }

    bool Same(int x, int y) { return Find(mp[x]) == Find(mp[y]); }

    void Output(int x) {
        int px = Find(mp[x]);
        cout << rank[px] << " " << sum[px] << endl;

    }
};

void solve(int n, int m) {
    disjoint_set ds(n, m);
    for(int i = 0;i < m;i++) {
        int op, p, q;
        cin >> op >> p;
        if(op == 1) {
            cin >> q;
            if(!ds.Same(p, q)) ds.Union(p, q);
        } else if(op == 2) {
            cin >> q;
            if(!ds.Same(p, q)) ds.Insert(p, q);
        } else {
            ds.Output(p);
        }
    }
}

int main() {_
    int m, n;
    while(cin >> n >> m) solve(n, m);
    return 0;
}