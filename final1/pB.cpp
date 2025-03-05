#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  map<ll, ll> ml;
  map<ll, vector<ll>> mv;

  ml[0] = -1000000000;
  mv[0] = vector<ll>();

  int n; cin >> n;
  vector<ll> vec(n);
  for(int i = 0;i < n;i++) {
    cin >> vec[i];
    vec[i] = -vec[i];
  }
  reverse(vec.begin(), vec.end());

  for(int i = 0;i < n;i++) {
    int k = vec[i];
    int l = 0, r = ml.rbegin()->first + 1;
    while(l + 1 < r) {
      int mid = (l + r) / 2;
      if(ml[mid] < k) l = mid;
      else r = mid;
    }

    vector<ll> v = mv[l];
    v.emplace_back(k);
    mv[l + 1] = v;
    ml[l + 1] = k;
  }

  cout << ml.rbegin()->first << '\n';
  vector<ll> v = mv[ml.rbegin()->first];
  reverse(v.begin(), v.end());
  for(int i = 0;i < v.size();i++) {
    cout << -v[i] << " \n"[i == v.size() - 1];
  }
}

int main()  {
  solve();
}

// 9
// 6 3 5 2 7 4 3 6 4
