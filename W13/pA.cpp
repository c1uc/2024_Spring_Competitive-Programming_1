//
// Created by user on 2024/5/17.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve() {
    int N; cin >> N;
    vector<int> vec(N);
    for(auto& v: vec) cin >> v;

    vector dp(N, vector(30001, 0));
    for(int i = 0;i < N;i++) {
        dp[i][0] = 1;
        if(i > 0) for(int j = 0;j <= 30000;j++) dp[i][j] = dp[i-1][j];
        for(int j = vec[i];j <= 30000;j++) {
            dp[i][j] += dp[i][j-vec[i]];
            if(dp[i][j] > 1) dp[i][j] = 2; // prevent overflow
        }
    }

    int M; cin >> M;
    while(M--) {
        int K; cin >> K;
        if(dp[N-1][K] == 0) cout << "Impossible\n";
        else if(dp[N-1][K] != 1) cout << "Ambiguous\n";
        else {
            int i = N-1, j = K;
            stack<int> ans;
            while(i >= 0 && j > 0) {
                if(j >= vec[i] && dp[i][j] == dp[i][j-vec[i]]) {
                    ans.push(i);
                    j -= vec[i];
                } else {
                    i--;
                }
            }
            while(!ans.empty()) {
                cout << ans.top()+1 << " ";
                ans.pop();
            }
            cout << "\n";
        }
    }
}

signed main() {_
    solve();
    return 0;
}

// 3
// 4 5 8
// 3
// 11 13 14
