// pF - Same Digits (Hard)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> count_digits(int x) {
    vector<int> cnt(10, 0);
    while(x > 0) {
        cnt[x % 10]++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    vector<pii> ans;
    int A, B;
    cin >> A >> B;
    for(int x = A;x <= B && x * x <= B;x++) {
        for(int y = x;y <= B && x * y <= B;y++) {
            auto a = count_digits(x);
            auto b = count_digits(y);
            auto c = count_digits(x * y);

            bool ok = true;
            for(int i = 0;i < 10;i++) {
                if(a[i] + b[i] != c[i]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans.emplace_back(x, y);
            }
        }
    }
    cout << ans.size() << " digit-preserving pair(s)" << endl;
    for(auto p : ans) {
        cout << "x = " << p.first << ", y = " << p.second << ", xy = " << p.first * p.second << endl;
    }
}

int main() {
    solve();
    return 0;
}
