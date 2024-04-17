#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, string> node;

void solve() {
    set<node> db;
    int N, Q;
    cin >> N >> Q;
    for(int i = 0;i < N;i++) {
        string s;
        ll a;
        cin >> s >> a;
        db.emplace(node(a, s));
    }

    int idx = 1;
    auto it1 = db.begin();
    auto it2 = db.begin();
    int idx1 = N / 3;
    int idx2 = 2 * N / 3;
    for(auto it = db.begin();it != db.end();it++) {
        if(idx == idx1) it1 = it;
        if(idx == idx2) it2 = it;
        idx++;
    }

    while(Q--) {
        string s;
        ll a;
        cin >> s >> a;
        if(a < idx1) idx1++;
        if(a < idx2) idx2++;
        db.emplace(node(a, s));
        N++;
        while(idx1 < N / 3) {
            it1++;
            idx1++;
        }
        while(idx1 > N / 3) {
            it1--;
            idx1--;
        }
        while(idx2 < 2 * N / 3) {
            it2++;
            idx2++;
        }
        while(idx2 > 2 * N / 3) {
            it2--;
            idx2--;
        }

        cout << it1->second << ' ' << it2->second << ' ' << it2->first - it1->first << '\n';
    }

}

int main() {_
    solve();
    return 0;
}

// 3 3
// a 1
// b 2
// c 3
// d 4
// e 5
// f 6

// 3 2
// aBc 0
// dEf 1000000000000000000
// efg 123
// hIj 456
// kLm 789
