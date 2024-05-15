//
// Created by duck on 2024/5/14.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

void solve() {
    int n; cin >> n;
    int t = 0;

    map<string, int> m;
    vector<string> m_(n);
    vector<vector<int>> adj(n);

    string s;
    stringstream ss;

    while(n--) {
        getline(cin >> ws, s);
        ss << s;

        string tag; ss >> tag;
        tag.pop_back();
        if(m.find(tag) == m.end()) {
            m_[t] = tag;
            m[tag] = t++;
        }

        while(ss >> s) {
            if(m.find(s) == m.end()) {
                m_[t] = s;
                m[s] = t++;
            }
            adj[m[s]].emplace_back(m[tag]);
        }
        ss.clear();
        ss.str("");
    }
    cin >> s;
    queue<int> q;
    vector<int> in_deg(t+1, 0);

    q.emplace(m[s]);
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto &v: adj[u]) {
            if(in_deg[v]++ == 0)
                q.emplace(v);
        }
    }

    q.emplace(m[s]);
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        cout << m_[u] << '\n';
        for(auto &v: adj[u]) {
            if(--in_deg[v] == 0) q.emplace(v);
        }
    }
}

signed main() {_
    solve();
    return 0;
}

//6
//gmp:
//solution: set map queue
//        base:
//set: base gmp
//map: base gmp
//queue: base
//        gmp
