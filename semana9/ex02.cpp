#include <bits/stdc++.h>
using namespace std;

void addEdge (vector<vector<int>> &adj, int x, int y) {
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

        for(int i : adj[aux]) {
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

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        float d;
        cin >> n >> d;

        vector<vector<int>> adj(n + 1);
        vector<bool> visitado(n + 1, false);

        vector<pair<float, float>> estrelas(n);
        for (int j = 0; j < n; j++) {
            cin >> estrelas[j].first >> estrelas[j].second;
        }

        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                float dx = estrelas[j].first - estrelas[k].first;
                float dy = estrelas[j].second - estrelas[k].second;
                if ((dx * dx) + (dy * dy) <= d * d) {
                    addEdge(adj, j + 1, k + 1);
                }
            }
        }

        int constelacoes = 0;
        for (int j = 1; j < n + 1; j++) {
            if (!visitado[j]) {
                constelacoes++;
                bfs(j, adj, visitado);
            }
        }

        cout << "Case " << i + 1 << ": " << constelacoes << '\n';
    }
}