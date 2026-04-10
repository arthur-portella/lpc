#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    vector<int> dp(n, 0);
    
    int tamanho_maximo = 0;
    int cont = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i-1] == '(') {
                if (i >= 2) {
                    dp[i] = dp[i - 2] + 2;
                } else {
                    dp[i] = 0 + 2;
                }
            } else {
                int j = i - dp[i-1] - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (j >= 1)
                        dp[i] += dp[j - 1];
                }
            }
        }

        if (dp[i] > tamanho_maximo) {
            tamanho_maximo = dp[i];
            cont = 1;
        } else if (dp[i] > 0 && dp[i] == tamanho_maximo) {
            cont++;
        }
    }

    if (tamanho_maximo == 0)
        cout << "0 1" << "\n";
    else
        cout << tamanho_maximo << " " << cont << "\n";
}