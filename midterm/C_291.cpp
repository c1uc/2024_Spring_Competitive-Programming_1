#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;

#define MOD 998244353

struct disjoint_set {
    vector<int> parent;
    vector<int> rank;
    vector<priority_queue<ll, vector<ll>, less<>>> sets;

    disjoint_set(ll n): parent(n), rank(n, 1), sets(n, priority_queue<ll, vector<ll>, less<>>()) {
        iota(parent.begin(), parent.end(), 0);
        for(ll i = 0;i < n;i++) sets[i].push(i);
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
        
        priority_queue<ll, vector<ll>, less<>> pq;
        ll EV = 0;
        // cout << '-' << endl;
        while(!sets[y].empty()) {
            ll a = sets[y].top(); sets[y].pop();
            ll b = sets[x].top(); sets[x].pop();
            EV += a * b;
            EV %= MOD;
            pq.push(a); pq.push(b);
        }
        // cout << '*' << endl;
        while(!sets[x].empty()) {
            ll a = sets[x].top();
            sets[x].pop();
            pq.push(a);

            EV += a;
            EV %= MOD;
        }

        parent[y] = x;
        rank[x] += rank[y];
        sets[x] = pq;
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


int main() {
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