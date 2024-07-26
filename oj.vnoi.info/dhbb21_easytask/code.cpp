#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1000005;

int n;
int a[MAXN], pf[MAXN];
int res = -10000000000000, mn = 1000000000000;
bool prime[MAXN];

void init();

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    init();

    for (int i = 1; i <= n; i++) {
        if (prime[i]) {
            mn = min(mn, pf[i - 1]);
            res = max(res, pf[i] - mn);
        }
    }

    cout << res;
    return 0;
}

void init()  {
    for (int i = 2; i <= 1000000; i++) {
        prime[i] = true;
    }

    for (int i = 2; i <= 1000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        pf[i] = pf[i - 1] + a[i];
    }
}
