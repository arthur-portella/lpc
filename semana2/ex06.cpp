#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> flechas(1000001, 0);

    int altura, flechas_disparadas = 0;
    for (int i = 0; i < n; i++) {
        cin >> altura;
        
        if(flechas[altura] > 0) {
            flechas[altura]--;
            flechas[altura - 1]++;
        } else if (flechas[altura] == 0) {
            flechas[altura - 1]++;
            flechas_disparadas++;
        }
    }

    cout << flechas_disparadas << "\n";
}