#include<bits/stdc++.h>
using namespace std;
int n, x, cnt[10005], mx;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
        mx = max(mx, cnt[x]);
    }

    for (int i = 1; i <= 10000; i++) {
        if (cnt[i] == mx) {
            cout << i;
            return 0;
        }
    }
}