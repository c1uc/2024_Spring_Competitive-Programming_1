//
// Created by duck on 2024/3/6.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end(), greater<>());
    sort(y.begin(), y.end(), greater<>());
    cout << x[n / 2] << ' ' << y[n / 2] << endl;
    return 0;
}