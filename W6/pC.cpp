// pC - Out of Sorts
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

vector<ll> vec;

ll solve() {
    ll N, M, A, C, X;
    cin >> N >> M >> A >> C >> X;
    vec.resize(N);
    vec[0] = (A * X + C) % M;
    for (int i = 1; i < N; ++i) {
        vec[i] = (A * vec[i - 1] + C) % M;
    }

    ll ans = 0;
    for(auto i: vec) {
        bool flag = false;
        ll L = 0, R = N - 1;
        while (L <= R) {
            ll mid = (L + R) / 2;
            if(vec[mid] == i) {
                flag = true;
                break;
            }
            if(vec[mid] < i) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        if(flag) ans++;
    }

    return ans;
}

int main() {_
    cout << solve() << endl;
    return 0;
}
