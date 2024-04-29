//
// Created by duck on 2024/4/28.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = unsigned long long;

unsigned long long vec[100010];

void solve() {
    ll N, K; cin >> N >> K;

    auto build_table = []() {
        for(int i = 3;i <= 100001;i++) {
            vec[i] = vec[i - 1] + vec[i - 2];
            if(vec[i] > static_cast<ll>(1e18)) {
                vec[i] = 1e18 + 1;
            }
        }
    };

    auto search = [](ll x, ll pos) -> string {
        while(x > 2) {
            if(pos > vec[x - 2]) {
                pos -= vec[x - 2];
                x -= 1;
            } else {
                x -= 2;
            }
        }
        return x == 1 ? "N" : "A";
    };

    vec[1] = 1;
    vec[2] = 1;

    build_table();
    cout << search(N, K) << '\n';
}

signed main() {_
    solve();
    return 0;
}
