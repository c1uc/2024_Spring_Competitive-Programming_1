//
// Created by user on 2024/5/21.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;
constexpr int MAXN = 300001;

auto lg = [](const int x) {
    return x ? __builtin_clz(1) - __builtin_clz(x) : 0;
};

void solve() {
    int N; cin >> N;
    vector vec(N + 1, 0);
    vector depth(N + 1, 0);
    vector jpp(N + 1, vector(lg(MAXN) + 1, 0));

    auto build = [&](const int x) {
        for(int i = 1;i <= lg(MAXN);i++) {
            jpp[x][i] = jpp[jpp[x][i - 1]][i - 1];
        }
    };

    auto f = [&](int x, int y) -> int {
        if(depth[x] > depth[y]) swap(x, y);
        for(int i = lg(MAXN);i >= 0;i--) {
            if(depth[jpp[y][i]] >= depth[x]) y = jpp[y][i];
        }
        if(vec[x] == vec[y]) return depth[x];
        for(int i = lg(MAXN);i >= 0;i--) {
            if(jpp[x][i] != jpp[y][i]) x = jpp[x][i], y = jpp[y][i];
        }
        return depth[jpp[x][0]];
    };

    for(int i = 1;i <= N;i++) {
        char c; cin >> c;
        int a; cin >> a;

        vec[i] = vec[a];
        depth[i] = depth[a];
        jpp[i][0] = jpp[a][0];

        if(c == 'a') {
            vec[i] = i;
            jpp[i][0] = vec[a];
            depth[i]++;
            build(i);
        } else if(c == 'b') {
            cout << vec[a] << '\n';
            vec[i] = jpp[a][0];
            jpp[i][0] = jpp[a][1];
            depth[i]--;
            build(i);
        } else {
            int b; cin >> b;
            build(i);
            cout << f(a, b) << '\n';
        }
    }
}

signed main() {_
    solve();
    return 0;
}

// 11
// a 0
// a 1
// a 2
// a 3
// a 2
// c 4 5
// a 5
// a 6
// c 8 7
// b 8
// b 8
