// pH - Multigram
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for(int i = 1;i < s.size();i++) {
        if(s.size() % i != 0) continue;
        vector<int> cnt(26, 0);
        for(int j = 0;j < i;j++) {
            cnt[s[j] - 'a']++;
        }
        bool ok = true;
        for(int pos = i;pos < s.size();pos += i) {
            vector<int> c1(26, 0);
            for(int j = 0;j < i;j++) {
                c1[s[pos + j] - 'a']++;
            }
            for(int j = 0;j < 26;j++) {
                if(cnt[j] != c1[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            cout << s.substr(0, i) << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    solve();
}
