#include <bits/stdc++.h>
using namespace std;

void addEdge (vector<vector<int>> &adj, int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int bfs (int inicio, vector<vector<int>> &adj, vector<bool> &visitado) {
    queue<int> fila;
    int tamanho = 1;

    fila.push(inicio);
    visitado[inicio] = true;

    while (!fila.empty()) {
        int aux = fila.front();
        fila.pop();

        for (int i : adj[aux]) {
            if (!visitado[i]) {
                visitado[i] = true;
                fila.push(i);
                tamanho++;
            }
        }       
    }
    
    return tamanho;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj (n + 1);
        vector<bool> visitado(n + 1, false);

        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            addEdge(adj, a, b);
        }

        int maior = 0;
        for (int j = 1; j < n + 1; j++) {
            if (!visitado[j]) {
                int temp = bfs(j, adj, visitado);
                maior = max(temp, maior);
            }
        }

        cout << maior << "\n";
    }
}