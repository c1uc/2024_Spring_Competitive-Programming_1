//
// Created by duck on 2024/3/6.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0, pos = 0;
    while(s.find("kick", pos) != string::npos) {
        pos = s.find("kick", pos) + 3;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
