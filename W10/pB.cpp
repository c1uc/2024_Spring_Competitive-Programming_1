//
// Created by duck on 2024/4/28.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    auto n = s.size();
    vector<ll> c(n, 1);

    auto check = [&](const string& s) -> ll {
        bool hasL = false;
        int C = 0, V = 0;
        for(auto i : s) {
            if(i == 'L') {
                hasL = true;
                C++;
                V = 0;
            } else if(i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
                V++;
                C = 0;
            } else {
                C++;
                V = 0;
            }
            if(C == 3 || V == 3) return 0;
        }
        if(!hasL) return 0;
        ll tot = 1;
        for(auto x : c) tot *= x;
        return tot;
    };

    auto func = [&](ll i, auto self) -> ll {
        ll ans = 0;
        if(i == n) {
            ans += check(s);
            return ans;
        }

        if(s[i] != '_') return self(i + 1, self);

        s[i] = 'A';
        c[i] = 5;
        ans += self(i + 1, self);

        s[i] = 'C';
        c[i] = 20;
        ans += self(i + 1, self);

        s[i] = 'L';
        c[i] = 1;
        ans += self(i + 1, self);

        s[i] = '_';
        c[i] = 1;

        return ans;
    };

    cout << func(0, func) << '\n';
}

signed main() {_
    solve();
    return 0;
}