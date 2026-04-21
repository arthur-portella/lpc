#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int inicio, vector<vector<int>> &adj) {
    vector<int> anterior(n + 1, 0);
    queue<int> fila;

    fila.push(inicio);
    anterior[inicio] = -1;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        if (atual == n) 
            return anterior;

        for (int vizinho : adj[atual]) {
            if (anterior[vizinho] == 0) {
                anterior[vizinho] = atual;
                fila.push(vizinho);
            }
        }
    }

    return anterior;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> anterior = bfs(n, 1, adj);

    if (anterior[n] == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> caminho;
        for (int v = n; v != -1; v = anterior[v]) {
            caminho.push_back(v);
        }
        reverse(caminho.begin(), caminho.end());

        cout << caminho.size() << "\n";
        for (int i = 0; i < caminho.size(); i++) {
            cout << caminho[i];
            if (i != caminho.size() - 1)
                cout << " ";
            else 
                cout << "";
        }
        cout << "\n";
    }
}