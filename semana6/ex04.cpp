#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> moedas(n);
    for (int i = 0; i < n; i++)
        cin >> moedas[i];

    long long modulo = 1e9 + 7;

    vector<long long> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < moedas.size(); j++) {
            if (dp[i] != 0 && i + moedas[j] <= x) {
                dp[i + moedas[j]] = (dp[i + moedas[j]] + dp[i]) % modulo;
            }
        }
    }

    cout << dp[x] << "\n";
}