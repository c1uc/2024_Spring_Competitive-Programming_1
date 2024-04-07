// pH - Just for Sidekicks
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

ll lowbit(ll x) {
    return x & -x;
}

void add(vector<ll> &bit, int i, ll x) {
    for(; i < bit.size(); i += lowbit(i)) bit[i] += x;
}

ll sum(vector<ll> &bit, int i) {
    ll ans = 0;
    for(; i; i -= lowbit(i)) ans += bit[i];
    return ans;
}

ll sum(vector<ll> &bit, int l, int r) {
    return sum(bit, r) - sum(bit, l - 1);
}

void init(vector<ll> &bit, vector<ll> &a) {
    bit.resize(a.size(), 0);
    for(int i = 1; i < a.size(); i++) {
        bit[i] += a[i];
        if(i + lowbit(i) < a.size()) a[i + lowbit(i)] += a[i];
    }
}

ll solve() {
    int N, Q; cin >> N >> Q;
    vector<vector<ll>> bits(7, vector<ll>(N+1, 0));
    vector<ll> value(7);
    vector<ll> a(N+1, 0);

    for(int i = 1;i < 7;i++) cin >> value[i];
    string s; cin >> s;
    for(int i = 1;i <= N;i++) {
        a[i] = s[i-1] - '0';
        add(bits[a[i]], i, 1);
    }
    while(Q--) {
        int q; cin >> q;
        if(q == 1) {
            int k, p; cin >> k >> p;
            add(bits[a[k]], k, -1);
            a[k] = p;
            add(bits[a[k]], k, 1);
        } else if(q == 2) {
            int x, p; cin >> x >> p;
            value[x] = p;
        } else {
            int l, r; cin >> l >> r;
            ll ans = 0;
            for(int i = 1;i < 7;i++) {
                ans += value[i] * sum(bits[i], l, r);
            }
            cout << ans << '\n';
        }
    }
    return -1;
}

int main() {_
    solve();
    return 0;
}

