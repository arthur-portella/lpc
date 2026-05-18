#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    int m;
    cin >> m;

    vector<int> custo_minimo(n + 1, 1e9);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < custo_minimo[b]) {
            custo_minimo[b] = c;
        }
    }

    long long custo_total = 0;
    int sem_supervisor = 0;

    for (int i = 1; i <= n; i++) {
        if (custo_minimo[i] == 1e9)
            sem_supervisor++;
        else 
            custo_total += custo_minimo[i];
    }

    if (sem_supervisor == 1)
        cout << custo_total << "\n";
    else 
        cout << "-1\n";
}