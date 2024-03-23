#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int solve(string& s, ll x) {
    int n = s.length();
    int ans = 100000;
    int dp[100000][20] = {-1};
    for(int i = n - 1;i >= 0;i--) {
        for(int j = 1;i + j <= n;j++) {
            if(i + j == n && stoll(s.substr(i, j)) <= x) dp[i][j] = 0;
            else {
                int m = 100000;

                if(m != 100000) dp[i][j] = 1 + m;
            }
        }
    }
    for(int i = 1;i < 20;i++) {
        if(dp[0][i] == -1) continue;
        ans = min(ans, dp[0][i]);
    }
    return ans == 100000 ? -1 : ans;
}

int main() {
    string s;
    ll x;
    cin >> s >> x;
    int ans = solve(s, x);
    if(ans == -1) cout << "NO WAY" << endl;
    else cout << ans << endl;
    return 0;
}