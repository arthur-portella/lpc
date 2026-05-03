#include <bits/stdc++.h>
using namespace std;

int profundidade(int u, vector<vector<int>> &adj) {
    int prof_max = 0;

    for (int v : adj[u])
        prof_max = max(prof_max, profundidade(v, adj));

    return prof_max + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> raizes;

    for (int i = 1; i <= n; i++) {
        int gerente;
        cin >> gerente;
        if (gerente == -1)
            raizes.push_back(i);
        else 
            adj[gerente].push_back(i);
    }

    int resposta = 0;

    for (int r : raizes)
        resposta = max(resposta, profundidade(r, adj));

    cout << resposta << endl;

}
