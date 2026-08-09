#include <bits/stdc++.h>
using namespace std;

int parent[30001];
int tamanho[30001];
int maior;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
        tamanho[a] += tamanho[b];
        if (tamanho[a] >= maior)
            maior = tamanho[a];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        maior = 1;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            tamanho[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }

        cout << maior << "\n";
    }
}