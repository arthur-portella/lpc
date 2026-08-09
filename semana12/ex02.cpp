#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int contador;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = parent[a];
        contador--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        float d;
        cin >> n >> d;
        contador = n;

        for (int j = 0; j < n; j++)
            parent[j] = j;

        vector<pair<float, float>> coordenadas(n);
        for (int j = 0; j < n; j++) {
            cin >> coordenadas[j].first >> coordenadas[j].second;
        }

        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                float dist = sqrt(pow(coordenadas[j].first - coordenadas[k].first, 2) + pow(coordenadas[j].second - coordenadas[k].second, 2));
                if (dist <= d)
                    unite(j, k);
            }
        }

        cout << "Case " << i << ": " << contador << "\n";
    }
}