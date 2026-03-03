#include <bits/stdc++.h>
using namespace std;

string encontra_pessoa(int n, int pessoas_iguais) {
    int numero = (int)ceil((double)n / pessoas_iguais);
    
    if (numero == 1)
        return "Sheldon";
    if (numero == 2)
        return "Leonard";
    if (numero == 3)
        return "Penny";
    if (numero == 4)
        return "Rajesh";
    return "Howard";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int pessoas_total = 5, pessoas_iguais = 1;

    int n;
    cin >> n;

    while (n > pessoas_total) {
        n -= pessoas_total;
        pessoas_iguais *= 2;
        pessoas_total = pessoas_iguais * 5;
    }

    cout << encontra_pessoa(n, pessoas_iguais) << "\n";

}