#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
long long a, b;

long long busca_solucao(long long esq, long long dir) {
    auto it1 = lower_bound(v.begin(), v.end(), esq);
    auto it2 = upper_bound(v.begin(), v.end(), dir);

    long long quantidade = it2 - it1;

    if (quantidade == 0)
        return a;

    long long custo = b * quantidade * (dir - esq + 1);

    if (esq == dir)
        return custo;

    long long meio = (esq + dir) / 2;

    long long esquerda = busca_solucao(esq, meio);
    long long direita = busca_solucao(meio + 1, dir);

    return min(custo, esquerda + direita);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k >> a >> b;

    v.resize(k);
    for (int i = 0; i < k; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cout << busca_solucao(1, ((long long)1 << n)) << "\n";
}