// pB - Expeditious Cubing
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;


int main() {_
    vector<ld> vec(4);
    for (int i = 0; i < 4; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    ld target;
    cin >> target;

    ld sum1 = vec[1] + vec[2] + vec[3];
    ld sum2 = vec[0] + vec[1] + vec[2];

    if(sum1 <= 3 * target) {
        cout << "infinite" << endl;
    } else if(sum2 > 3 * target) {
        cout << "impossible" << endl;
    } else {
        cout << fixed << setprecision(2) << 3 * target - vec[1] - vec[2] << endl;
    }
    return 0;
}

