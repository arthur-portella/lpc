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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long a, b;

        cin >> n >> a >> b;

        long long g = gcd(a, b);

        vector<long long> c(n);

        for (int i = 0; i < n; i++) {
            cin >> c[i];
            c[i] %= g;
        }

        sort(c.begin(), c.end());

        long long maior_gap = 0;

        // Gaps normais
        for (int i = 0; i + 1 < n; i++) {
            maior_gap = max(maior_gap, c[i + 1] - c[i]);
        }

        // Gap que passa de g para 0
        maior_gap = max(maior_gap, g - c[n - 1] + c[0]);

        cout << g - maior_gap << '\n';
    }

    return 0;
}