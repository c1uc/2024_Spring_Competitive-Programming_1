// pG - Muddy Hike
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
constexpr int MAXN = 1e9;
int MAP[1001][1001];

pair<int, int> MOVE[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs(int x, int y, int n, int m) {
    bool visited[n][m];

    memset(visited, false, sizeof(visited));

    priority_queue<piii, vector<piii>, greater<>> pq;
    pq.emplace(MAP[x][y], pii(x, y));

    while(!pq.empty()) {
        auto [val, p] = pq.top();
        pq.pop();

        if(p.second == m - 1) {
            return val;
        }

        for(const auto move: MOVE) {
            int nx = p.first + move.first;
            int ny = p.second + move.second;

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            pq.emplace(max(val, MAP[nx][ny]), pii(nx, ny));
        }
    }
    return MAXN;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> MAP[i][j];
    int ans = MAXN;
    for(int i = 0;i < n;i++) ans = min(ans, bfs(i, 0, n, m));
    cout << ans << endl;
}

int main() {_
    solve();
}
