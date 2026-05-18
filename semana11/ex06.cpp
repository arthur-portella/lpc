#include <bits/stdc++.h>
using namespace std;

vector<int> parent, len;
vector<tuple<double, int, int, double, int>> edges;

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

void kruskal(int n, int w, double &total_utp, double &total_fibra) {
    initDSU(n);

    total_utp = 0;
    total_fibra = 0;
    int arestas_usadas = 0;
    int meta = n - w;

    for (const auto &edge : edges) {
        if (arestas_usadas >= meta) 
            break;

        int u = get<1>(edge);
        int v = get<2>(edge);
        double custo = get<3>(edge);
        int tipo = get<4>(edge);

        if (same(get<1>(edge), get<2>(edge)) == false) {
            unite(get<1>(edge), get<2>(edge));
            if (tipo == 0) 
                total_utp += custo;
            else 
                total_fibra += custo;
            arestas_usadas++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int contador = 0;

    while (t--) {
        contador++;

        int n, r, w, u, v;
        cin >> n >> r >> w >> u >> v;

        vector<pair<int, int>> pos(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> pos[i].first >> pos[i].second;

        edges.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double dx = pos[i].first - pos[j].first;
                double dy = pos[i].second - pos[j].second;
                double d = sqrt(dx * dx + dy * dy);
                
                if (d <= r)
                    edges.push_back({d, i, j, d * u, 0});
                else 
                    edges.push_back({d, i, j, d * v, 1});
                
            }
        }

        sort(edges.begin(), edges.end());

        double total_utp, total_fibra;
        kruskal(n, w, total_utp, total_fibra);

        cout << "Caso #" << contador << ": " << fixed << setprecision(3) << total_utp << " " << total_fibra << "\n";
    }
}