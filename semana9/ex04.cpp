#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int x, int y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
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

    if (n != m) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    vector<bool> visitado(n + 1, false);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }

    bfs(1, adj, visitado);

    for (int i = 2; i < n + 1; i++) {
        if (!visitado[i]) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "FHTAGN!" << '\n';
}