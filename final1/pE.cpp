#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

int lg(int x) {
  return x == 0 ? 0 : __builtin_clz(1) - __builtin_clz(x);
}

int pa[100001];
int sz[100001];

int find(int x) {
  return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void merge(int x, int y) {
  if(sz[x] < sz[y]) swap(x, y);
  x = find(x);
  y = find(y);
  if(sz[x] == sz[y]) sz[x]++;
  pa[y] = x;
}

int parent[100001];
int weight[100001];
int depth[100001];
vector<vector<pii>> adj(100001, vector<pii>());

void dfs(int x, int d) {
  depth[x] = d;
  for(auto it = adj[x].begin();it != adj[x].end();it++) {
    int y = it->first;
    if(y != parent[x]) {
      parent[y] = x;
      weight[y] = it->second;
      dfs(y, d + 1);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  priority_queue<tii, vector<tii>, greater<>> pq;
  for(int i = 0;i <= n;i++) pa[i] = i;
  for(int i = 0;i < m;i++) {
    int p, q, r; cin >> p >> q >> r;
    pq.emplace(r, p, q);
  }
  int tot = 0;
  while (!pq.empty()) {
    tii t = pq.top();
    pq.pop();
    int w = get<0>(t), p = get<1>(t), q = get<2>(t);
    if(find(p) == find(q)) continue;
    adj[p].emplace_back(q, w);
    adj[q].emplace_back(p, w);
    merge(p, q);
  }

  dfs(1, 1);
  // for(int i = 0;i <= n;i++) cout << depth[i] << endl;

  vector<vector<pii>> jpp(n + 1, vector<pii>(lg(n + 1) + 1));

  for(int i = 1;i <= n;i++) jpp[i][0] = {parent[i], weight[i]};

  for(int j = 1;j <= lg(n + 1);j++) {
    for(int i = 1;i <= n;i++) {
      jpp[i][j].first = jpp[jpp[i][j - 1].first][j - 1].first;
      jpp[i][j].second = max(jpp[i][j - 1].second, jpp[jpp[i][j - 1].first][j - 1].second);
    }
  }

  // for(int i = 1;i <= n;i++) for(int j = 0;j <= lg(n+1);j++) cout << i << ' ' << j << ' ' << jpp[i][j].first << ' ' << jpp[i][j].second << '\n';

  int q;
  cin >> q;
  while(q--) {
    int a, b; cin >> a >> b;
    int c = 0;
    if(depth[a] < depth[b]) swap(a, b);
    for(int i = lg(n+1);i >= 0;i--) {
      if(depth[jpp[a][i].first] >= depth[b]) {
        c = max(c, jpp[a][i].second);
        a = jpp[a][i].first;
      }
    }
      if(a == b) cout << c << endl;
      else {
        for(int i = lg(n+1);i >= 0;i--) {
          if(jpp[a][i].first != jpp[b][i].first) {
            c = max(jpp[a][i].second, c);
            c = max(jpp[b][i].second, c);

            a = jpp[a][i].first;
            b = jpp[b][i].first;
          }
        }
        c = max(jpp[a][0].second, c);
        c = max(jpp[b][0].second, c);
        cout << c << endl;
      }
  }
}

int main()  {
  solve();
}

// 5 5
// 1 2 3
// 2 3 7
// 3 4 8
// 2 4 1
// 4 5 5
// 3
// 1 3
// 3 5
// 1 5
