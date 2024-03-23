// pK - Sheba's Amoebas
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long double ld;
typedef pair<int, int> pii;

pii dir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
bool mm[101][101];

void traverse(int x, int y, int n, int m) {
    for (auto d: dir) {
        int nx = x + d.first;
        int ny = y + d.second;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && mm[nx][ny]) {
            mm[nx][ny] = false;
            traverse(nx, ny, n, m);
        }
    }
}

int main() {_
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        for (int j = 0; j < m; j++) {
            mm[i][j] = c[j] == '#';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mm[i][j]) {
                traverse(i, j, n, m);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
