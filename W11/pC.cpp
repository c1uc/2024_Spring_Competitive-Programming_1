//
// Created by duck on 2024/5/5.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int k; cin >> k;
    string res = "a";
    if(k <= 25) {
        res += static_cast<char>('a' + k);
        cout << res << '\n';
    } else if(k % 25 == 0) {
        while(k > 0) {
            res += *res.rbegin() == 'z' ? 'a' : 'z';
            k -= 25;
        }
        cout << res << '\n';
    } else {
        auto tmp = k % 25;
        res += static_cast<char>('a' + 13 + (tmp / 2));
        res += 'a';
        k -= tmp + 25;
        while(k > 0) {
            res += *res.rbegin() == 'z' ? 'a' : 'z';
            k -= 25;
        }
        if(!(tmp & 1)) *res.rbegin() == 'z' ? *res.rbegin() = 'y' : *res.rbegin() = 'b';
        cout << res << '\n';
    }
}

signed main() {_
    solve();
    return 0;
}
