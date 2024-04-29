// pA - Arachnophobia
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;



ll solve() {
    int M, N, T;
    cin >> N >> M >> T;
    vector<vector<pll>> adj(N);

    for (int i = 0; i < M; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, d);
    }

    int start, goal;
    cin >> start >> goal;
    int k;
    cin >> k;

    priority_queue<pll, vector<pll>, greater<>> pq;
    for (int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        pq.emplace(0, tmp);
    }

    vector<ll> s_dist(N, 1e9);
    vector<bool> vis(N, false);

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (s_dist[u] <= d) continue;
        s_dist[u] = d;
        for (auto [v, w] : adj[u]) {
            if (s_dist[v] > s_dist[u] + w) {
                pq.emplace(s_dist[u] + w, v);
            }
        }
    }

    ll ans = 0;
    for(ll tmp = static_cast<ll>(1) << 30;tmp;tmp >>= 1) {
        if(s_dist[start] < ans + tmp) continue;
        if(s_dist[goal] < ans + tmp) continue;
        fill(vis.begin(), vis.end(), false);

        vector<ll> dis(N, 1e10);
        pq.emplace(0, start);
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(dis[u] <= d) continue;
            dis[u] = d;
            for(auto [v, w] : adj[u]) {
                if(s_dist[v] < ans + tmp) continue;
                if(dis[v] > dis[u] + w) {
                    pq.emplace(dis[u] + w, v);
                }
            }
        }
        if(dis[goal] <= T) {
            ans += tmp;
        }
    }
    return ans;
}

int main() {
    cout << solve() << endl;
}
