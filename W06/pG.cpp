// pG - Supercomputer
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
    vector<ll> bit(N+1, 0);
    vector<bool> a(N+1, false);

    while(Q--) {
        string c;
        cin >> c;
        if(c == "F") {
            int i;
            cin >> i;
            add(bit, i, a[i] ? -1 : 1);
            a[i] = !a[i];
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(bit, l, r) << '\n';
        }
    }
    return -1;
}

int main() {_
    solve();
    return 0;
}

