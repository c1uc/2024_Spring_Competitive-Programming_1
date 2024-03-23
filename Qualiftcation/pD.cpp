//
// Created by duck on 2024/3/6.
//
#include <iostream>
using namespace std;
typedef long long ll;

ll alp, beta, m;


ll f(ll x) {
    if(x == 0) return 2;
    if(x == 1) return alp;
    if(x % 2 == 0) return (f(x / 2) * f(x / 2) - 2 + m) % m;
    return (f(x / 2) * f(x - x / 2) - alp + m) % m;
}

int main() {
    cin >> alp >> beta >> m;
    cout << (f(beta) + m) % m << endl;
    return 0;
}