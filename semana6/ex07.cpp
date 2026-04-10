#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cont = 0, aux;
    cin >> n; 
    
    aux = n;
    while (n > 0) {
        int maior = -1, digito;
        while (aux > 0) {
            digito = aux % 10;
            maior = max(digito, maior);
            aux /= 10;
        }
        n -= maior;
        aux = n;
        cont++;
    }

    cout << cont << "\n";
}