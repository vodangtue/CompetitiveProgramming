#include<bits/stdc++.h>
using namespace std;

int n, a[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << *max_element(a + 1, a + 1 + n);
    return 0;
}