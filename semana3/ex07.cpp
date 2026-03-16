#include <bits/stdc++.h>
using namespace std;

bool possivel(const vector<long long> &posicoes, int c, long long distancia) {
    int vacas = 1;
    long long ultima = posicoes[0];

    for (int i = 1; i < posicoes.size(); i++) {
        if (posicoes[i] >= ultima + distancia) {
            vacas++;
            ultima = posicoes[i];
        }
    }

    if (vacas >= c)
        return true;
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, c;
        cin >> n >> c;

        vector<long long> posicoes;

        for (int j = 0; j < n; j++) {
            long long aux;
            cin >> aux;
            posicoes.push_back(aux);
        }

        sort(posicoes.begin(), posicoes.end());

        long long esq = 0, dir = posicoes[n-1] - posicoes[0], meio, resp = 0;

        while (esq <= dir) {
            meio = (esq + dir) / 2;

            if (possivel(posicoes, c, meio)) {
                resp = meio;
                esq = meio + 1;
            } else
                dir = meio - 1;
        }

        cout << resp << "\n";
    }
}