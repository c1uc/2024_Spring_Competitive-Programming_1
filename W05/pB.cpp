// pB - Terraces
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef pair<int, int> pii;

pii MOVE[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int MAP[502][502] = {1000};
int VISIT[502][502] = {0};
int n, m, area = 0, lowest = 1;

void dfs(int x, int y) {
    VISIT[x][y] = 1;
    area++;
    for(auto [dx, dy]: MOVE) {
        int nx = x + dx, ny = y + dy;
        if(MAP[nx][ny] < MAP[x][y]) {
            lowest = 0;
        }
    }
    for(auto [dx, dy]: MOVE) {
        int nx = x + dx, ny = y + dy;
        if(MAP[nx][ny] == MAP[x][y] && VISIT[nx][ny] == 0) dfs(nx, ny);
    }
}

int solve() {
    cin >> m >> n;

    for(int i = 0;i <= n+1;i++) MAP[i][0] = MAP[i][m+1] = 1000;
    for(int i = 0;i <= m+1;i++) MAP[0][i] = MAP[n+1][i] = 1000;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> MAP[i][j];

    int ans = 0;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(VISIT[i][j] == 0) {dfs(i, j); ans += area * lowest; area = 0; lowest = 1;}

    // for(int i = 0;i <= n+1;i++) for(int j = 0;j <= m+1;j++) { cout << MAP[i][j] << " "; if(j == m+1) cout << endl; }
    // for(int i = 0;i <= n+1;i++) for(int j = 0;j <= m+1;j++) { cout << FLAG[i][j] << " "; if(j == m+1) cout << endl; }

    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}
