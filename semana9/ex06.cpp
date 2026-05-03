#include <bits/stdc++.h>

#define MAX 200005

using namespace std;

int n, m, diameter;
vector<int> altura;
vector<int> adj[MAX + 1];

int dfs(int u, int p) {
    int a1 = 0, a2 = 0;

    for (auto v : adj[u]) {
        if (v != p) {
            altura[u] = max(altura[u], dfs(v, u));

            if (altura[v] > a2) {
                a2 = altura[v];

                if (a2 > a1)
                    swap(a1, a2);
            }
        }
    }

    diameter = max(diameter, a1 + a2);

    return altura[u] = altura[u] + 1;
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    m = n - 1;
    altura = vector<int>(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    dfs(1, -1);

    cout << diameter << "\n";
}