#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, q, x, l, r, pf[4][100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        pf[1][i] = pf[1][i - 1];
        pf[2][i] = pf[2][i - 1];
        pf[3][i] = pf[3][i - 1];
        pf[x][i]++;
    }

    while(q--){
        cin >> l >> r;
        cout << pf[1][r] - pf[1][l - 1] << " " << pf[2][r] - pf[2][l - 1] << " " << pf[3][r] - pf[3][l - 1] << endl;
    }

    return 0;
}