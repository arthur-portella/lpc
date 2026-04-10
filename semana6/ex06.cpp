#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> tamanhos(3);

    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> tamanhos[i];

    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[j] != -1 && j + tamanhos[i] <= n) {
                dp[j + tamanhos[i]] = max(dp[j + tamanhos[i]], dp[j] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
}