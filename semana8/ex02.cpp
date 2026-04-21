#include <bits/stdc++.h>
using namespace std;

void dfs(int inicio, vector<vector<int>> &adj, vector<bool> &visitado) {
    stack<int> pilha;
    pilha.push(inicio);
    visitado[inicio] = true;

    while (!pilha.empty()) {
        int atual = pilha.top();
        pilha.pop();

        for (int vizinho : adj[atual]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                pilha.push(vizinho);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visitado(n+1, false);
    vector<int> representantes;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!visitado[i]) {
            representantes.push_back(i); 
            dfs(i, adj, visitado); 
        }
    }

    cout << representantes.size() - 1 << "\n";
    for(int i = 0; i < representantes.size() - 1; i++) {
        cout << representantes[i] << " " << representantes[i+1] << "\n";
    }
}