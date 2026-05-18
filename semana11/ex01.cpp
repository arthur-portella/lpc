#include <bits/stdc++.h>
using namespace std;

int bfs(int inicio, bool &governo, vector<vector<int>> &adj, vector<bool> &visitado, vector<bool> &tem_governo_no_componente) {
    queue<int> q;
    q.push(inicio);
    visitado[inicio] = true;
    int tamanho = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tamanho++;
        if (tem_governo_no_componente[u]) 
            governo = true;

        for (int v : adj[u]){
            if (!visitado[v]) {
                visitado[v] = true;
                q.push(v);
            }
        }
    }
    
    return tamanho;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> tem_governo_no_componente(n + 1);

    vector<int> governos(k);
    for (int i = 0; i < k; i++) {
        cin >> governos[i];
        tem_governo_no_componente[governos[i]] = true;
    }

    vector<vector<int>> adj(n + 1);
    vector<bool> visitado(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tam_com_governo;
    int nos_sozinhos = 0;

    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            bool tem_gov = false;
            int tam = bfs(i, tem_gov, adj, visitado, tem_governo_no_componente);
            if (tem_gov)
                tam_com_governo.push_back(tam);
            else 
                nos_sozinhos += tam;
        }
    }

    sort(tam_com_governo.begin(), tam_com_governo.end());
    
    tam_com_governo.back() += nos_sozinhos;

    long long max_arestas = 0;
    for (int tam : tam_com_governo) {
        max_arestas += (long long)tam * (tam - 1) / 2;
    }

    cout << max_arestas - m << "\n";
}