// pD - Kayaking Trip
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
    ll count[3];
    cin >> count[0] >> count[1] >> count[2];

    ll S[3];
    cin >> S[0] >> S[1] >> S[2];

    ll tot = (count[0] + count[1] + count[2]) >> 1;
    ll C[tot];
    for (int i = 0; i < tot; ++i) {
        cin >> C[i];
    }

    ll ans = 0;
    sort(C, C + tot);
    for(ll tmp = 1 << 30;tmp;tmp >>= 1) {
        bool ok = true;
        ll tmpcount[3] = {count[0], count[1], count[2]};
        for(int i = 0;i < tot && ok;i++) {
            bool paired = false;
            for(int p = 0;p < 4;p++) {
                if(p == 3) {
                    ok = false;
                    break;
                }

                if(tmpcount[p] == 0) continue;

                for(int q = p;q < 3;q++) {
                    if(tmpcount[q] == 0) continue;
                    if(p == q && tmpcount[q] < 2) continue;

                    if(C[i] * (S[p] + S[q]) >= ans + tmp) {
                        tmpcount[p]--;
                        tmpcount[q]--;
                        paired = true;
                        break;
                    }
                }
                if(paired) break;
            }
        }
        if(ok) {
            ans += tmp;
        }
    }
    return ans;
}


int main() {
    cout << solve() << endl;
    return 0;
}
