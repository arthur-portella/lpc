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
        cin >> n;

        vector<int> a(n);

        int g_total = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            g_total = gcd(g_total, a[i]);
        }

        int quantidade = 0;

        for (int x : a) {
            if (x == g_total)
                quantidade++;
        }

        if (quantidade > 0) {
            cout << n - quantidade << '\n';
            continue;
        }

        const int INF = 1e9;

        vector<int> dp(5001, INF);

        for (int x : a) {

            vector<int> novo = dp;

            novo[x] = min(novo[x], 1);

            for (int g = 1; g <= 5000; g++) {

                if (dp[g] != INF) {

                    int novo_g = gcd(g, x);

                    novo[novo_g] = min(
                        novo[novo_g],
                        dp[g] + 1
                    );
                }
            }

            dp = novo;
        }

        int min_len = dp[g_total];

        cout << (min_len - 1) + (n - 1) << '\n';
    }
}