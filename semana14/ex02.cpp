#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> spf(MAX + 1);

    for (int i = 0; i <= MAX; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    const int INF = 1e9;

    vector<int> menor(MAX + 1, INF);
    vector<int> segundo(MAX + 1, INF);
    vector<int> quantidade(MAX + 1, 0);

    for (int valor : a) {

        while (valor > 1) {

            int p = spf[valor];
            int expoente = 0;

            while (valor % p == 0) {
                valor /= p;
                expoente++;
            }

            quantidade[p]++;

            if (expoente < menor[p]) {
                segundo[p] = menor[p];
                menor[p] = expoente;
            } else if (expoente < segundo[p]) {
                segundo[p] = expoente;
            }
        }
    }

    long long resposta = 1;

    for (int p = 2; p <= MAX; p++) {

        int expoente;

        if (quantidade[p] <= n - 2) {
            expoente = 0;
        } else if (quantidade[p] == n - 1) {
            expoente = menor[p];
        } else {
            expoente = segundo[p];
        }

        while (expoente--)
            resposta *= p;
    }

    cout << resposta << '\n';
}