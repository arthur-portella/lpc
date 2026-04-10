#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> preco(n);
    for (int i = 0; i < n; i++)
        cin >> preco[i];

    vector<int> paginas(n);
    for (int i = 0; i < n; i++)
        cin >> paginas[i];

    vector<int> dp(x + 1, 0);  
    
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= preco[i]; j--) {
            dp[j] = max(dp[j], dp[j - preco[i]] + paginas[i]);
        }
    }

    cout << dp[x] << "\n";
}