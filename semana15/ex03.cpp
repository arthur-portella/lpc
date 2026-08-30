#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long inicio = 2, fim = 2e9, k = 2;

        while (inicio <= fim) {
            long long meio = inicio + (fim - inicio) / 2;
            
            if (meio * (meio - 1) / 2 <= n) {
                k = meio;
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }

        long long combinacoes_k = k * (k - 1) / 2;
        long long resto = n - combinacoes_k;

        cout << k + resto << "\n";
    }
}