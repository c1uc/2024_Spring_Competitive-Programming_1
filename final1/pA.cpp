#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1001][501];
ll v[51][2];

void solve() {
  int n, m, l;
  cin >> n >> m >> l;

  for(int i = 0;i < n;i++) cin >> v[i][0] >> v[i][1];

  int q = 0;
  for(int i = 0;i < l;i++) {
    int t; cin >> t; q += t;
  }

  ll ans = 0;
  for(int i = 0;i < n;i++) {
    for(int j = m;j >= v[i][0];j--) {
      for(int k = 1;k <= q;k++) {
        dp[j][k] = max(dp[j][k], dp[j - v[i][0]][k - 1] + v[i][1]);
        ans = max(ans, dp[j][k]);
      }
    }
  }
  cout << ans << endl;
}

int main()  {
  solve();
}

// 3 9 1
// 2 4
// 3 5
// 4 6
// 2

// 3 6 2
// 2 4
// 3 5
// 4 6
// 2 1
