#include <bits/stdc++.h>
using namespace std;

int inicio_ciclo, fim_ciclo;

bool dfs(int u, int p, vector<vector<int>> &adj, vector<int> &anterior) {
    anterior[u] = p;

    for (int vizinho : adj[u]) {
        if (vizinho == p) 
            continue;

        if (anterior[vizinho] != 0) {
            inicio_ciclo = vizinho;
            fim_ciclo = u;
            return true;
        }

        if (dfs(vizinho, u, adj, anterior)) 
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> anterior(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool encontrou = false;
    for (int i = 1; i <= n; i++) {
        if (anterior[i] == 0) {
            if (dfs(i, -1, adj, anterior)) {
                encontrou = true;
                break;
            }
        }
    }

    if (!encontrou) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> caminho;
        int atual = fim_ciclo;
        caminho.push_back(inicio_ciclo);
        while (atual != inicio_ciclo) {
            caminho.push_back(atual);
            atual = anterior[atual];
        }
        caminho.push_back(inicio_ciclo);

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