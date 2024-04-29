// pE - Canvas Painting
#include <queue>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
    int m;
    cin >> m;
    while(m--) {
        int n;
        cin >> n;

        priority_queue<ull, vector<ull>, greater<>> pq;
        while(n--) {
            ull t;
            cin >> t;
            pq.push(t);
        }

        ull ans = 0;
        while(pq.size() > 1) {
            ull a = pq.top();
            pq.pop();
            ull b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << endl;
    }
    return 0;
}