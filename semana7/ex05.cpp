#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<long long> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    vector<vector<long long>> dp(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = d[i];
    }

    for (int tamanho = 2; tamanho <= n; tamanho++) 
        for (int i = 0; i <= n - tamanho; i++) {
            int j = i + tamanho - 1;
            dp[i][j] = max(d[i] - dp[i + 1][j], d[j] - dp[i][j - 1]);
        }

    cout << dp[0][n - 1] << "\n";
}