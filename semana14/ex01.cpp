#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    while (k--) {
        long long n, x, t;
        cin >> n >> x >> t;

        long long m = t / x;

        m = min(m, n - 1);

        long long res = m * (n - 1) - m * (m - 1) / 2;

        cout << res << '\n';
    }
}