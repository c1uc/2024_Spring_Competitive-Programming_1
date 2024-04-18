//
// Created by duck on 2024/4/18.
//
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
using ll = long long;
constexpr ll MAX_N = 2e6 + 1;

typedef struct {
    ll Lvalue, Rvalue;
    ll value;
} node;

//vector<node> arr(4 * MAX_N + 1);
//vector<ll> a(MAX_N + 1);

void solve() {
    int N, Q; cin >> N >> Q;

    vector<node> arr(4 * N + 1);
    vector<ll> a(N + 1);

    for(int i = 1;i <= N;i++) cin >> a[i];

    auto merge = [&](const ll l, const ll mid, const ll r, const node& L, const node& R) -> node {
        node res;
        res.Lvalue = (L.Lvalue == (mid - l + 1) ? L.Lvalue + R.Lvalue : L.Lvalue);
        res.Rvalue = (R.Rvalue == (r - mid) ? L.Rvalue + R.Rvalue : R.Rvalue);

        res.value = max(L.value, R.value);
        res.value = max(res.value, L.Rvalue + R.Lvalue);

        if(L.value == (mid - l + 1) && R.value == (r - mid)) res.Lvalue = res.Rvalue = res.value;

        return res;
    };

    auto init = [&]() {
        auto build = [&](ll x, ll l, ll r, auto self) {
            if(l == r) {
                arr[x].value = arr[x].Lvalue = arr[x].Rvalue = a[l];
                return;
            }
            ll mid = (l + r) >> 1;
            self(x << 1, l, mid, self);
            self(x << 1 | 1, mid + 1, r, self);

            arr[x] = merge(l, mid, r, arr[x << 1], arr[x << 1 | 1]);
        };

        build(1ll, 1, N, build);
    };

    auto modify = [&](ll x, ll l, ll r, ll pos, auto self) {
        if(l == r) {
            arr[x].value = !arr[x].value;
            arr[x].Lvalue = arr[x].Rvalue = arr[x].value;
            return;
        }
        ll mid = (l + r) >> 1;

        if(pos <= mid) self(x << 1, l, mid, pos, self);
        else self(x << 1 | 1, mid + 1, r, pos, self);

        arr[x] = merge(l, mid, r, arr[x << 1], arr[x << 1 | 1]);
    };

    auto query = [&](ll x, ll l, ll r, ll tl, ll tr, auto self) -> node {
//        cout << 'q' << l << ' ' << r << ' ' << tl << ' ' << tr << endl;

        if(l > r) return {0, 0, 0};
        if(l == tl && r == tr) return arr[x];

        ll mid = (tl + tr) >> 1;

        node L = self(x << 1, l, min(mid, r), tl, mid, self);
        node R = self(x << 1 | 1, max(mid + 1, l), r, mid + 1, tr, self);

        node res = merge(l, mid, r, L, R);

//        cout << l << ' ' << r << ' ' << tl << ' ' << tr << ' ' << res.value << endl;

        return res;
    };

    init();
    while(Q--) {
        char op;
        int l, r; cin >> op;
        if(op == 'Q') {
            cin >> l >> r;
            cout << query(1, l, r, 1, N, query).value << '\n';
        } else {
            cin >> l;
            modify(1, 1, N, l, modify);
        }
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}

//10 5
//0 1 1 0 1 1 0 0 1 1
//Q 2 8
//C 4
//C 5
//Q 1 5
//Q 4 10

//10 5
//0 1 1 0 1 1 0 0 1 1
//Q 1 1
//Q 2 2
//Q 3 3
//Q 4 4
//Q 5 5

