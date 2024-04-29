//
// Created by duck on 2024/4/28.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ld = long double;
using comp = complex<ld>;

void solve() {
    string s; cin >> s;
    int n = s.size();
    n = 1 << ((int)ceil(log2(n)) + 1);
    vector<comp> a(n), b(n);

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'B') b[i] = comp{1, 0};
        else a[s.size() - 1 - i] = comp{1, 0};
    }

    auto fft = [&](auto& vec, bool inv) -> void {
        for(int i = 0, j = 0; i < n; i++) {
            if(i < j) swap(vec[i], vec[j]);
            for(int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        for(int l = 1; l < n; l <<= 1) {
            ld theta = (inv ? 1 : -1) * M_PI / l;
            comp wl = {cos(theta), sin(theta)};

            for(int i = 0; i < n; i += l * 2) {
                comp w = {1, 0};
                for(int j = 0; j < l; j++) {
                    comp u = vec[i + j], v = vec[i + j + l] * w;
                    vec[i + j] = u + v;
                    vec[i + j + l] = u - v;
                    w *= wl;
                }
            }
        }
        if(inv) for(int i = 0; i < n; i++) vec[i] /= n;
    };

    fft(a, false);
    fft(b, false);
    for(int i = 0; i < n; i++) a[i] *= b[i];
    fft(a, true);

    for(int i = 1; i < s.size(); i++) {
        cout << (int)round(a[s.size() - 1 - i].real()) << '\n';
    }
}

signed main() {_
    solve();
    return 0;
}
