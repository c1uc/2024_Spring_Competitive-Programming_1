//
// Created by duck on 2024/5/15.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;
using pii = pair<int, int>;

void solve() {
    int N;
    while(cin >> N && N) {
        priority_queue<pii, vector<pii>, greater<>> pq;
        for(int i = 0; i < N; i++) {
            int x, y; cin >> x >> y;
            pq.emplace(x, y);
        }

        vector<pii> vec;
        while(!pq.empty()) {
            if(!vec.empty() && vec.back() == pq.top()) {
                pq.pop();
                continue;
            }
            vec.emplace_back(pq.top());
            pq.pop();
        }

        N = vec.size();

        auto cross = [&](int o, int a, int b) {
            return (vec[a].first - vec[o].first) * (vec[b].second - vec[o].second) - (vec[a].second - vec[o].second) * (vec[b].first - vec[o].first);
        };

        vector<int> ans;
        int t = 0;
        for(int i = 0;i < N;i++) {
            while(t >= 2 && cross(ans[t - 2], ans[t - 1], i) <= 0) {
                ans.pop_back();
                t--;
            }
            ans.push_back(i);
            t++;
        }
        for(int i = N - 2, u = t + 1;i >= 0;i--) {
            while(t >= u && cross(ans[t - 2], ans[t - 1], i) <= 0) {
                ans.pop_back();
                t--;
            }
            ans.push_back(i);
            t++;
        }
        if(ans.size() > 1)
            ans.pop_back();
        cout << ans.size() << '\n';
        for(int an : ans) {
            cout << vec[an].first << ' ' << vec[an].second << '\n';
        }
    }
}

signed main() {_
    solve();
    return 0;
}

//3
//0 0
//10 0
//0 10
//5
//41 -6
//-24 -74
//-51 -6
//73 17
//-30 -34
//2
//50 50
//50 50
//0
