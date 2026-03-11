#include <bits/stdc++.h>
using namespace std;

int busca_binaria(const vector<long long> &vetor, int n, int x) {
    int esq = 0, dir = n - 1, meio;
    int pos = -1;

    while (esq <= dir) {
        meio = (esq + dir) / 2;

        if (vetor[meio] == x) {
            pos = meio;
            dir = meio - 1;
        }
        else if (vetor[meio] > x)
            dir = meio - 1;
        else
            esq = meio + 1;
    }
    
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> vetor(n);

    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << busca_binaria(vetor, n, x) << "\n";
    }
}