//
// Created by duck on 2024/5/15.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;
using pii = pair<ld, ld>;

void solve() {
    int N; cin >> N;
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

    auto area = [&](int a, int b, int c) {
        return abs(cross(a, b, c));
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

    ld res = 0;
    for(int i = 0;i < ans.size();i++) {
        int k = i + 2;
        for(int j = i + 1;j < ans.size();j++) {
            while(k + 1 < ans.size() && area(ans[i], ans[j], ans[k]) < area(ans[i], ans[j], ans[k + 1])) {
                ++k;
            }
            res = max(res, area(ans[i], ans[j], ans[k % ans.size()]));
        }
    }
    cout << fixed << setprecision(10) << res / 2 << '\n';

}

signed main() {_
    solve();
    return 0;
}

//7
//0 0
//0 5
//7 7
//0 10
//0 0
//20 0
//10 10
