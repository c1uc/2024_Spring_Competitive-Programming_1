// pB - Backspace
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000001

int main() {
    string s;
    cin >> s;
    const int n = s.size();
    int j = 0;
    char res[MAXN];
    for(int i = 0;i < n;++i) {
        if (s[i] == '<') {
            j--;
        } else {
            res[j++] = s[i];
        }
    }
    res[j++] = '\0';
    cout << res << endl;
    return 0;
}
