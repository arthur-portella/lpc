#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    vector<long double> dp(N + 1);
    vector<long double> pref(N + 1);

    int qtd = B - A + 1;

    dp[0] = 0;
    pref[0] = 0;

    for (int i = 1; i <= N; i++) {
        int l = max(0, i - B);
        int r = i - A;

        long double soma = 0;

        if (l <= r) {
            soma = pref[r];

            if (l > 0)
                soma -= pref[l - 1];
        }

        dp[i] = 1.0L + soma / qtd;

        pref[i] = pref[i - 1] + dp[i];
    }
    cout << fixed << setprecision(5) << (double)dp[N] << '\n';
}