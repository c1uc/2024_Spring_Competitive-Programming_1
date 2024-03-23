// pA - Opening Ceremony
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000001

int main() {
    int n;
    cin >> n;
    vector<int> v(MAXN, 0);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v[t]++;
    }
    vector<int> ps(MAXN, 0);
    for(int i = 0; i < MAXN; ++i) {
        ps[i] = v[i] + (i > 0 ? ps[i - 1] : 0);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < MAXN; ++i) {
        int r = n - ps[i];
        ans = min(ans, i + r);
    }
    cout << ans << endl;
    return 0;
}