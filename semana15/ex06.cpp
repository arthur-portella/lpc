#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    vector<double> dp(n + 1, 0.0);
    int L = b - a + 1;
    double soma = 0.0;

    if (a == 0) {
        for (int i = 1; i <= n; i++) {
            soma += dp[i - 1];

            if (i - b - 1 >= 0) {
                soma -= dp[i - b - 1];
            }

            dp[i] = (double)L / (L - 1) + soma / (L - 1);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (i - a >= 0) {
                soma += dp[i - a];
            }

            if (i - b - 1 >= 0) {
                soma -= dp[i - b - 1];
            }

            dp[i] = 1.0 + soma / L;
        }
    }
    cout << fixed << setprecision(5) << dp[n] << "\n";
}