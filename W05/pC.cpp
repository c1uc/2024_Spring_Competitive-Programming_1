// pC - Faulty Robot
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> edges;
vector<int> vis, forced, endpoint;

void dfs(int x, bool flag) {
    if(vis[x]) return;
    if(!forced[x]) endpoint[x] = 1;

    if(forced[x] && !vis[forced[x]]) {
        vis[x] = 1;
        dfs(forced[x], flag);
        vis[x] = 0;
    }

    if(flag) return;
    for(auto e: edges[x]) {
        if(vis[e]) continue;
        vis[x] = 1;
        dfs(e, true);
        vis[x] = 0;
    }

}

int solve() {
    int m, n;
    cin >> n >> m;

    edges.resize(n+1, vector<int>());
    vis.resize(n+1, 0);
    forced.resize(n+1, 0);
    endpoint.resize(n+1, 0);


    for(int i = 0;i < m;i++) {
        int p, q;
        cin >> p >> q;
        if(p < 0) {
            forced[-p] = q;
        } else {
            edges[p].emplace_back(q);
        }
    }

    dfs(1, false);

    int ans = 0;

    for(int i = 1;i <= n;i++) if(endpoint[i]) ans++;

    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}