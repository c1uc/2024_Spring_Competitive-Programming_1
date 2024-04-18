#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;

#define MOD 998244353

struct disjoint_set {
    vector<int> parent;
    vector<int> rank;
    vector<set<ll>> sets;
    vector<ll> sum;

    disjoint_set(ll n): parent(n), rank(n, 1), sets(n, set<ll>()), sum(n, 0) {
        iota(parent.begin(), parent.end(), 0);
        iota(sum.begin(), sum.end(), 0);
        for(ll i = 0;i < n;i++) sets[i].insert(i);
        // cout << "init" << endl;
    }

    ll find(ll x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }

    ll unite(ll x, ll y) {
        x = find(x);
        y = find(y);

        if(rank[x] < rank[y])
            swap(x, y);
        
        ll EV = 0, sumsum = 0;
        auto it1 = sets[x].rbegin(), it2 = sets[y].rbegin();
        // cout << '-' << endl;
        while(it2 != sets[y].rend()) {
            EV += *it1 * *it2;
            sumsum += *it1;
            it2++;
            it1++;
        }
        // cout << '*' << endl;
        EV += sum[x] - sumsum;
        EV %= MOD;

        parent[y] = x;
        rank[x] += rank[y];
        sum[x] += sum[y];
        sets[x].insert(sets[y].begin(), sets[y].end());
        return EV;
    }
};

ll solve() {
    int n; cin >> n;
    ll a, b;
    ll ans = 0;
    disjoint_set ds(n+1);
    for(int i = 0;i < n-1;i++) {
        cin >> a >> b;
        ans += ds.unite(a, b);
        ans %= MOD;
    }
    
    return ans;
}


int main() {_
    // int n; cin >> n;
    cout << solve() << '\n';
    return 0;
}

// 12
// 1 3
// 8 11
// 10 7
// 6 5
// 1 7
// 8 5
// 4 2
// 12 8
// 7 9
// 12 7
// 1 2

// 5
// 1 5
// 2 4
// 3 1
// 2 5