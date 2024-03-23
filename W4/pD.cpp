// pD - Bungee Builder
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000001

int solve() {
    int n;
    cin >> n;
    int ans = 0;
    int m[n];
    for(int i = 0;i < n;i++) cin >> m[i];

    int MIN = MAXN, MAX = 0;
    for(int i = 0;i < n;i++) {
        if(m[i] > MAX) {
            ans = max(ans, MAX - MIN);
            MAX = m[i];
            MIN = m[i];
        }
        if(m[i] < MIN) MIN = m[i];
        ans = max(ans, m[i] - MIN);
        // cout << ans << endl;
    }
    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}
