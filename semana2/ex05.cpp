#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> vetor;

    long long aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        vetor.push_back(aux);
    }

    long long soma_atual = 0, cont = 0;
    int a = 0;

    for (int b = 0; b < n; b++) {
        soma_atual += vetor[b];

        while (soma_atual > x && a <= b) {
            soma_atual -= vetor[a];
            a++;
        }

        if (soma_atual == x) {
            cont++;
        }
    }

    cout << cont << "\n";
}