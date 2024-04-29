// pE - Counting Subsequences (Hard)
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<ll, ll> cnt;
    cnt[0] = 1;
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        ans += cnt[sum - 47];
        cnt[sum]++;
    }
    return ans;
}

int main() {_
    int n; cin >> n;
    while(n--) cout << solve() << '\n';
    return 0;
}
