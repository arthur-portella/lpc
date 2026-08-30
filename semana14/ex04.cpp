#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        vector<long long> b(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        b[0] = a[0];
        b[n] = a[n-1];

        for (int i = 1; i < n; i++) {
            b[i] = lcm(a[i - 1], a[i]);
        }

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (gcd(b[i], b[i + 1]) != a[i]) {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}