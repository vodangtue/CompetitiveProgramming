#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, a[50005], q, l, r;
pair<int, int> st[200005];
void build(int id = 1, int l = 1, int r = n) {
    if (l == r) {
        st[id].fi = a[l];
        st[id].se = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].fi = max(st[id * 2].fi, st[id * 2 + 1].fi);
    st[id].se = min(st[id * 2].se, st[id * 2 + 1].se);
}

pair<int, int> get(int u, int v, int id = 1, int l = 1, int r = n) {
    if (r < u || v < l) return {-INT_MAX, INT_MAX};
    if (u <= l && r <= v) return st[id];

    int mid = (l + r) / 2;

    pair<int, int> gt1 = get(u, v, id * 2, l, mid);
    pair<int, int> gt2 = get(u, v, id * 2 + 1, mid + 1, r);

    return {max(gt1.fi, gt2.fi), min(gt1.se, gt2.se)};
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        pair<int, int> gt = get(l, r);
        cout << gt.fi - gt.se << endl;
    }

    return 0;
}