#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, cont = 0;
    cin >> n >> k;

    unordered_set<int> inteiros;
    int aux;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        inteiros.insert(aux);
    }

    for (int aux : inteiros) {
        if (inteiros.count(aux + k)) {
            cont++;
        }
    }

    cout << cont << "\n";

}
