#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long soma_total = n * (n + 1) / 2;

    if (soma_total % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }

    long long soma = soma_total / 2, modulo = 1e9 + 7;

    vector<long long> dp(soma + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) 
        for (int j = soma; j >= i; j--)
            dp[j] = (dp[j -  i] + dp[j]) % modulo;

    cout << dp[soma] << "\n";
    
}