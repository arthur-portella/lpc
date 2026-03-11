#include <bits/stdc++.h>
using namespace std;

bool possivel (const vector<long long> &alturas, long long altura_corte, long long m) {
    long long madeiras_coletadas = 0;

    for (int i = 0; i < alturas.size(); i++) {
        if (alturas[i] > altura_corte) {
            madeiras_coletadas += alturas[i] - altura_corte;
        }
    }

    if (madeiras_coletadas >= m) 
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> alturas;

    for (int i = 0; i < n; i++) {
        long long aux;
        cin >> aux;
        alturas.push_back(aux);
    }

    long long esq = 0, dir = 1e9, meio, resp;

    while (esq <= dir) {
        meio = (esq + dir) / 2;

        if(possivel(alturas, meio, m)) {
            resp = meio;
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }

    cout << resp << "\n";
}