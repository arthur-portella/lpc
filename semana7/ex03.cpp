#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, w, primeiro = 1;
    
    while(cin >> t >> w) {

        if (!primeiro)
            cout << "\n";
        primeiro = 0;

        int n;
        cin >> n;

        vector<int> profundidade(n);
        vector<int> custo(n);
        vector<int> quantidade(n);
        for (int i = 0; i < n; i++) {
            cin >> profundidade[i] >> quantidade[i];
            custo[i] = (w * profundidade[i]) + (2 * w * profundidade[i]);
        }

        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        for (int i = 1; i <= n; i++) {
            int c = custo[i-1];
            int v = quantidade[i-1];
            for (int j = 0; j <= t; j++) {
                if (c <= j)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - c] + v);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        cout << dp[n][t] << "\n";

        vector<int> escolhidos;
        int atual = t;
        for (int i = n; i > 0; i--) {
            if (dp[i][atual] != dp[i-1][atual]) {
                escolhidos.push_back(i-1);
                atual -= custo[i-1];
            }
        }

        cout << escolhidos.size() << "\n";
        for (int i = escolhidos.size() - 1; i >= 0; i--) {
            int num = escolhidos[i];
            cout << profundidade[num] << " " << quantidade[num] << "\n";
        }
    }

}