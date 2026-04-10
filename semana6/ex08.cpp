#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;

    long long soma = 0;
    int aux;
    vector<long long> dp(n);
    for(int i = 0; i < n; i++) {
        cin >> aux;
        soma += aux;
        dp[i] = soma;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int ini, f; 
        long long resp;
        cin >> ini >> f;

        if (ini == 0)
            resp = dp[f] - 0;
        else
            resp = dp[f] - dp[ini - 1];

        cout << resp << "\n";
    }
}