#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, balde, div, menor_divisao = 0x3f3f3f3f;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> balde;
        
        if (k % balde == 0){
            div = k / balde;
            if (div < menor_divisao) {
                menor_divisao = div;
            }
        }
    }

    cout << menor_divisao << "\n";
}