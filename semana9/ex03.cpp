#include <bits/stdc++.h>
using namespace std;

void addEdge (vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs (int inicio, vector<vector<int>> &adj, vector<bool> &visitado) {
    queue<int> fila;
    fila.push(inicio);
    visitado[inicio] = true;

    while (!fila.empty()) {
        int aux = fila.front();
        fila.pop();

        for (int i : adj[aux]) {
            if (!visitado[i]) {
                visitado[i] = true;
                fila.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (m != n - 1) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    vector<bool> visitado(n + 1, false);

    for (int i = 0 ; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    bfs(1, adj, visitado);

    for (int i = 2; i < n + 1; i++) {
        if (!visitado[i]) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
}