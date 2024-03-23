// pG - Gear Changing
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main() {
    int n, m;
    ld p;
    cin >> n >> m >> p;
    p /= 100;

    vector<ld> vec;
    vector<ld> g1;
    vector<ld> g2;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        g1.emplace_back(t);
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        g2.emplace_back(t);
    }
    for(const auto it1: g1) {
        for(const auto it2: g2) {
            vec.emplace_back(it1 / it2);
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 0;i+1 < vec.size(); i++) {
        if(vec[i+1] > vec[i] * (1 + p)) {
            cout << "Time to change gears!" << endl;
            return 0;
        }
    }
    cout << "Ride on!" << endl;
    return 0;
}
