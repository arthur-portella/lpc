#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string dna;
    cin >> dna;

    int contagem = 1, maior = 1;
    char aux = dna[0];

    for (int i = 1; i < dna.length(); i++) {
        if (dna[i] == aux) {
            contagem++;
        } else {
            aux = dna[i];
            contagem = 1;
        }
        
        if (contagem > maior) {
            maior = contagem;
        }
    }

    cout << maior << "\n";
}