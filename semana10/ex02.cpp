#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 1e18));

    for (int i = 1; i <= n; i++) 
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (c < dist[a][b]) {
            dist[a][b] = dist[b][a] = c;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (dist[u][k] + dist[k][v] < dist[u][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == 1e18) 
            cout << -1 << "\n";
        else 
            cout << dist[a][b] << "\n";
    }
}