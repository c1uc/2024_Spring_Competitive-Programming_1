#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;

ll calc_save(ll* c, ll m, int i) {
    ll a, b;
    a = m / 2;
    b = m - a;
    return c[i] + a * a + b * b - m * m;
}

pll func(ll a, ll b, ll c) {
    pl d = {b, c};
    return pll(a, d);
}

ull solve() {
    int N, M;
    cin >> N >> M;
    priority_queue<pll, vector<pll>, greater<>> pq;
    ll w[N];
    for(int i = 0;i < N;i++) cin >> w[i];
    ll c[N];
    for(int i = 0;i < N;i++) cin >> c[i];

    for(int i = 0;i < N;i++) pq.emplace(func(calc_save(c, w[i], i), w[i], i));
    ull cost = 0;
    ull ans = 0;
    while(M--) {
        if(pq.top().first >= 0) break;
        auto tmp = pq.top(); pq.pop();
        
        pl b = tmp.second;
        
        ll m = b.first;
        ll t = b.second;

        if(m == 1) {
            ans += 1;
            M++;
            continue;
        }

        cost += c[t];

        ll newa = m / 2, newb;
        newb = m - newa;

        // cout << "split type " << t << " weight " << m << " to " << newa << " " << newb << '\n';

         pq.emplace(func(calc_save(c, newa, t), newa, t));
         pq.emplace(func(calc_save(c, newb, t), newb, t));
    }

    while(!pq.empty()) {
        ll m = pq.top().second.first; pq.pop();
        ans += m * m;
    }
    return ans + cost;
}

int main() {_
    cout << solve() << '\n';
    return 0;
}

// 4 1
// 5 1 3 8
// 6 15 2 30
