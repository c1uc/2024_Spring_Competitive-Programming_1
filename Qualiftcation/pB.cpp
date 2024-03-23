#include <iostream>
using namespace std;

int main() {
    double r1, r2, s1, s2;
    cin >> r1 >> r2 >> s1 >> s2;
    int ss1 = s1 * 100, ss2 = s2 * 100;
    if((r1 - 1) * ss2 < (r2 - 1) * ss1)
        cout << "TAOYUAN" << endl;
    else if((r1 - 1) * ss2 > (r2 - 1) * ss1)
        cout << "JAKARTA" << endl;
    else
        cout << "SAME" << endl;
    return 0;
}