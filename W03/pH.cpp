// pH - Sim
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long double ld;

int main() {_
    int n;
    cin >> n;
    string s;
    cin.ignore();
    while(n--) {
        getline(cin, s);
        list<char> res;
        auto it = res.begin();
        for(const auto c: s) {
            if(c == '[') {
                it = res.begin();
            } else if(c == ']') {
                it = res.end();
            } else if(c == '<') {
                if(it != res.begin()) {
                    it--;
                    it = res.erase(it);
                }
            } else {
                res.insert(it, c);
            }
        }
        for(const auto c: res) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
