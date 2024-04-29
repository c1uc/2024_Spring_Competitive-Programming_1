//
// Created by duck on 2024/4/28.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> vec(n + 1);
    for(int i = 1;i <= n;i++) cin >> vec[i];

    vector<ll> arr(n + 1);

    auto low_bit = [&](ll x) {
        return x & -x;
    };

    auto init_tree = [&]() {
        fill(arr.begin(), arr.end(), 0);
        for(ll i = 1;i <= n;i++) {
            arr[i] = vec[i];
            if(i + low_bit(i) <= n) {
                arr[i + low_bit(i)] += arr[i];
            }
        }
    };

    auto add = [&](ll i, ll x) {
        for(; i <= n;i += low_bit(i)) {
            arr[i] += x;
        }
    };

    auto sum = [&](ll i) {
        ll ans = 0;
        for(; i;i -= low_bit(i)) {
            ans += arr[i];
        }
        return ans;
    };

    auto sum_range = [&](ll l, ll r) {
        return sum(r) - sum(l - 1);
    };

    vector<ll> pre(n + 1), suf(n + 1);

    fill(arr.begin(), arr.end(), 0);
    for(int i = 1;i <= n;i++) {
        add(vec[i], 1);
        pre[i] = i - sum(vec[i]);
    }

    fill(arr.begin(), arr.end(), 0);
    for(int i = n;i > 0;i--) {
        add(vec[i], 1);
        suf[i] = sum(vec[i] - 1);
    }

//    for(int i = 1;i <= n;i++) {
//        cout << pre[i] << ' ';
//    }
//    cout << '\n';
//
//    for(int i = 1;i <= n;i++) {
//        cout << suf[i] << ' ';
//    }
//    cout << '\n';

    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += pre[i] * suf[i];
    }
    cout << ans << '\n';
}

signed main() {_
    solve();
    return 0;
}
