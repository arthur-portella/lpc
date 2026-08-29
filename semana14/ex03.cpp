#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long l = 1;
        long long r = 2000000000LL;

        while (l < r) {
            long long m = (l + r) / 2;

            __int128 tipos = (__int128)m * (m - 1) / 2 + 1;

            if (tipos >= n)
                r = m;
            else
                l = m + 1;
        }

        cout << l << '\n';
    }
}