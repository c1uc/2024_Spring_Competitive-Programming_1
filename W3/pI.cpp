// pI - Delimiter Soup
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long double ld;

inline void not_ok(int i, char c) { cout << c << ' ' << i << endl; }

int main() {
    int n;
    cin >> n;
    stack<char> s;
    cin.ignore();
    for (int i = 0;i < n;i++) {
        char c = getchar();
        if(c == '(' || c == '[' || c == '{') {
            s.emplace(c);
        }
        if(c == ')' || c == ']' || c == '}') {
            if(s.empty()) {
                not_ok(i, c);
                return 0;
            }
            char t = s.top();
            s.pop();
            if(c == ')' && t != '(') {
                not_ok(i, c);
                return 0;
            }
            if(c == ']' && t != '[') {
                not_ok(i, c);
                return 0;
            }
            if(c == '}' && t != '{') {
                not_ok(i, c);
                return 0;
            }
        }
    }
    cout << "ok so far" << endl;
    return 0;
}
