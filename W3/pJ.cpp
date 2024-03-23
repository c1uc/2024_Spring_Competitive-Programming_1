// pJ - Circuit Math
#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    vector<bool> vec(26);
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        vec[i] = c == "T";
    }
    stack<bool> s;
    cin.ignore();
    string str;
    getline(cin, str);
    for(auto c: str) {
        if(c >= 'A' && c <= 'Z') {
            s.emplace(vec[c - 'A']);
        } else if(c == '+') {
            bool a = s.top();
            s.pop();
            bool b = s.top();
            s.pop();
            s.emplace(a || b);
        } else if(c == '-') {
            bool a = s.top();
            s.pop();
            s.emplace(!a);
        } else if(c == '*') {
            bool a = s.top();
            s.pop();
            bool b = s.top();
            s.pop();
            s.emplace(a && b);
        }
    }
    cout << (s.top() ? "T" : "F") << endl;
    return 0;
}
