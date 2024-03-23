// pA - Deathstar
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int ans = 0, k;
        for(int j = 0;j < n;j++) {
            cin >> k;
            ans |= k;
        }
        cout << ans << " ";
    }
    return 0;
}