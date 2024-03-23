// pG - Permutation Code
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

void solve(int x) {
    string s, p, c;
    cin >> s >> p >> c;

    map<char, int> ms, mp;
    for(int i = 0;i < s.size();i++) {
        ms[s[i]] = i;
        mp[p[i]] = i;
    }
    int n = c.size();
    int d = static_cast<int>(pow(static_cast<ld>(n), 1.5) + static_cast<ld>(x)) % n;
    vector<char> m(n);

    m[d] = p[ms[c[d]]];

    for(int i = d - 1;i >= 0;i--) {
        uint64_t a = ms[c[i]];
        uint64_t b = ms[m[(i + 1) % n]];

        m[i] = p[a ^ b];
    }

    for(int i = n - 1;i > d;i--) {
        uint64_t a = ms[c[i]];
        uint64_t b = ms[m[(i + 1) % n]];

        m[i] = p[a ^ b];
    }

    for(auto &i : m) cout << i;
    cout << endl;
}

int main() {
    int x;
    while(cin >> x && x) solve(x);
}
