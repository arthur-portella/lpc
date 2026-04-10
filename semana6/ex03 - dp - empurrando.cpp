#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> moedas = {1, 5, 10, 20, 100};
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < moedas.size(); j++) {
            if (i + moedas[j] <= n && dp[i] != 1e9)
                dp[i + moedas[j]] = min(dp[i + moedas[j]], dp[i] + 1);
        }
    }

    cout << dp[n] << "\n";

}