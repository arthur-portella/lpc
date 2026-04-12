#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> atividade(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> atividade[i];

    vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;

        if (atividade[i] == 1 || atividade[i] == 3) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }

        if (atividade[i] == 2 || atividade[i] == 3) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}