#include <bits/stdc++.h>
using namespace std;

vector<int> parent, len;
int componentes, maior = 1;

int find(int x) {
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (len[x] < len[y])
        swap(x, y);

    parent[y] = x;
    len[x] += len[y];

    componentes--;
    maior = max(maior, len[x]);
}

void initDSU(int n) {
    parent = len = vector<int>(n + 1);

    for (int u = 1; u <= n; u++) {
        parent[u] = u;
        len[u] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    initDSU(n);

    componentes = n;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        cout << componentes << " " << maior << "\n";
    }
}