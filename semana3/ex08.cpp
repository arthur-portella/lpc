#include <bits/stdc++.h>
using namespace std;

bool possivel(const vector<int> &sacos, int c, int t, long long tempo) {
    long long qte_max = tempo * t, soma_atual = 0;
    int competidores = 1;

    for (int i = 0; i < sacos.size(); i++) {
        if (sacos[i] > qte_max)
            return false;

        if (soma_atual + sacos[i] <= qte_max) {
            soma_atual += sacos[i];
        } else {
            competidores++;
            soma_atual = sacos[i];
        }
    }

    return competidores <= c;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, t;
    cin >> n >> c >> t;

    vector<int> sacos;
    long long soma_total = 0;

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        sacos.push_back(aux);
        soma_total += aux;
    }

    long long esq = 0, dir = 10e9 / t, meio, resp = 0;

    while (esq <= dir) {
        meio = (esq + dir) / 2;

        if (possivel(sacos, c, t, meio)) {
            resp = meio;
            dir = meio - 1;
        } else {
            esq = meio + 1;
        }
    }

    cout << resp << '\n';
}