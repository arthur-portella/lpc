#include <bits/stdc++.h>
using namespace std;

vector<int> parent, len;
vector<tuple<long long, int, int>> edges;

void addEdge(long long c, int b, int a) {
    edges.push_back({c, a, b});
    edges.push_back({c, b, a});
}

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
}

void initDSU(int n) {
    parent = len = vector<int>(n + 1);

    for (int u = 1; u <= n; u++) {
        parent[u] = u;
        len[u] = 1;
    }
}

long long kruskal(int n, int &arestas_usadas) {
    int components = n;
    long long cost = 0;

    initDSU(n);

    for (const auto &edge : edges) {
        if (same(get<1>(edge), get<2>(edge)) == false) {
            unite(get<1>(edge), get<2>(edge));

            cost += get<0>(edge);
            arestas_usadas++;
            components--;
        }
    }

    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        addEdge(c, a, b);
    }

    sort(begin(edges), end(edges));

    int arestas_usadas = 0;
    long long custo = kruskal(n, arestas_usadas);

    if (arestas_usadas == n - 1)
        cout << custo << "\n";
    else
        cout << "IMPOSSIBLE\n";
}