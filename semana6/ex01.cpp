#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> alturas(n);
    for (int i = 0; i < n; i++)
        cin >> alturas[i];

    vector<long long> dp(n, 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(alturas[i] - alturas[i + 1]));
        } 
        if (i + 2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(alturas[i] - alturas[i + 2]));
        }
    }

    cout << dp[n - 1] << "\n";

}