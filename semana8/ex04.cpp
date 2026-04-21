#include <bits/stdc++.h>
using namespace std;

bool bfs(int inicio, vector<vector<int>> &adj, vector<int> &time) {
    queue<int> fila;
    
    fila.push(inicio);
    time[inicio] = 1;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (int amigo : adj[atual]) {
            if (time[amigo] == 0) {
                if (time[atual] == 1)
                    time[amigo] = 2;
                else 
                    time[amigo] = 1;
                fila.push(amigo);
            } else if (time[amigo] == time[atual]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> time(n + 1, 0);
    bool possivel = true;

    for (int i = 1; i <= n; i++) {
        if (time[i] == 0) {
            if (!bfs(i, adj, time)) {
                possivel = false;
                break;
            }
        }
    }

    if (!possivel) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << time[i];
            if (i == n)
                cout << "";
            else 
                cout << " ";
        }
        cout << "\n";
    }
}