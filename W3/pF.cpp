// pF - Bank Queue
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> puu;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ull> res(k+1, 0);
    vector<puu> vec;
    for(int i = 0;i < n;i++) {
        int m, t;
        cin >> m >> t;
        vec.emplace_back(m, t);
    }
    sort(vec.begin(), vec.end(), greater<>());
    for(int i = 0;i < n;i++) {
        ull m = vec[i].first;
        ull t = vec[i].second;
        for(int j = t;j >= 0;j--) {
            if(res[j] == 0) {
                res[j] = m;
                break;
            }
        }
    }
    ull ans = 0;
    for(int i = 0;i <= k;i++) {
        ans += res[i];
    }
    cout << ans << endl;
    return 0;
}
