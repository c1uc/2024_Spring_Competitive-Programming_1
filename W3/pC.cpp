// pC - Bacon, Eggs, and Spam
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        cin.ignore();
        map<string, vector<string>> m;
        while(n--) {
            char s[160];
            cin.getline(s, 160);

            char* tok = strtok(s, " ");
            string name(tok);

            while(tok = strtok(NULL, " ")) {
                string tmp(tok);
                m[tmp].emplace_back(name);
            }
        }

        for(auto & it : m) {
            cout << it.first << " ";
            sort(it.second.begin(), it.second.end());
            for(auto & it2 : it.second) {
                cout << it2 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}