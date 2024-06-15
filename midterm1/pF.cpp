//
// Created by duck on 2024/4/19.
//
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
using ll = long long;

struct DSU {
    vector<ll> parent;
    vector<ll> size;

    explicit DSU(int n): parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    ll find(ll x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void merge(ll x, ll y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};

void solve() {
    int N, M; cin >> N >> M;
    DSU dsu(2 * (N + 1));

    for(int i = 1;i <= M;i++) {
        char op; int a, b;
        cin >> op >> a >> b;
        if(op == '+') {
            dsu.merge(a, b);
            dsu.merge(a + N, b + N);
        } else {
            dsu.merge(a, b + N);
            dsu.merge(a + N, b);
        }

        if(dsu.find(a) == dsu.find(a + N) || dsu.find(b) == dsu.find(b + N)) {
            cout << i << '\n';
            return;
        }
    }
    cout << "They are nice guys" << '\n';
}


int main() {
    FAST_IO
    solve();
    return 0;
}

//3 3
//- 1 2
//- 2 3
//+ 3 1

//3 3
//- 1 2
//- 2 3
//- 3 1
