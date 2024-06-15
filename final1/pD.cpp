#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007;

ll m[3][3] = {
{1, 0, 1},
{1, 0, 0},
{0, 1, 0}
};

vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
  vector<vector<ll>> c(3, vector<ll>(3, 0));
  for(int i = 0;i < 3;i++) {
    for(int j = 0;j < 3;j++) {
      for(int k = 0;k < 3;k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= MOD;
      }
    }
  }
  return c;
}

vector<ll> mulv(vector<vector<ll>>& a, vector<ll>& v) {
  vector<ll> c(3, 0);
  for(int i = 0;i < 3;i++) {
    for(int j = 0;j < 3;j++) {
      c[i] += a[i][j] * v[j];
      c[i] %= MOD;
    }
  }
  return c;
}


void solve() {
  ll n; cin >> n;
  if(n == 1) cout << 1;
  else if(n == 2) cout << 1;
  else if(n == 3) cout << 2;
  else {
    n -= 3;
    vector<vector<ll>> m(3, vector<ll>(3, 0));
    vector<ll> v{2, 1, 1};
    m[0][0] = 1;
    m[0][2] = 1;
    m[1][0] = 1;
    m[2][1] = 1;
    while(n) {
      if(n & 1) v = mulv(m, v);
      m = mul(m, m);
      n >>= 1;
    }
    cout << v[0] << endl;
  }
}

int main()  {
  solve();
}
