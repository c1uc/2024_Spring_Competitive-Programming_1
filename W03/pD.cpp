// pD - Parsing Hex
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        string s_(s);
        transform(s_.begin(), s_.end(), s_.begin(), ::tolower);
        int pos = 0;
        while(s_.find("0x", pos) != string::npos) {
            pos = s_.find("0x", pos);
            int end = s_.find_first_not_of("0123456789abcdefABCDEF", pos+2);
            if(end == string::npos) {
                end = s_.size();
            }
            string hex = s_.substr(pos, end - pos);
            stringstream ss;
            ss << std::hex << hex;
            unsigned long long dec;
            ss >> dec;
            cout << s.substr(pos, end - pos) << ' ' << dec << endl;
            pos = end;

        }

    }
    return 0;
}