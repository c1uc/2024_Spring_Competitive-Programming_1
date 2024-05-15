//
// Created by duck on 2024/5/14.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve(int t) {
    int N, K; cin >> N >> K;
    vector<vector<int>> forbid(N, vector<int>(N, 0));
    for(int i = 0;i < K;++i) {
        int a, b; cin >> a >> b;
        forbid[a - 1][b - 1] = 1;
        forbid[b - 1][a - 1] = 1;
    }
    int ans = 0;
    auto dfs = [&](int i, int n, int vis, auto self) {
        if(n == 0 && i == 0) {
            ans++;
            return;
        }
        for(int j = 0;j < N;++j) {
            if(forbid[i][j] || (vis & (1 << j))) continue;
            self(j, n - 1, vis | (1 << j), self);
        }
    };
    dfs(0, N, 0, dfs);
    cout << "Case #" << t + 1 << ": " << (ans >> 1) % 9901 << '\n';
}

signed main() {_
    int T; cin >> T;
    for(int i = 0;i < T;++i) solve(i);
    return 0;
}

//2
//4 1
//1 2
//8 4
//1 2
//2 3
//4 5
//5 6
