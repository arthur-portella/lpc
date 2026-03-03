#include <bits/stdc++.h>
using namespace std;

int transforma_numero (char pos) {
    if (pos == 'v') 
        return 0;
    if (pos == '<')
        return 1;
    if (pos == '^')
        return 2;
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char inicio, fim;
    long long n;
    
    cin >> inicio >> fim;
    cin >> n;

    int i = transforma_numero(inicio);
    int f = transforma_numero(fim);

    int cw = (i + (n % 4)) % 4;
    int ccw = (i - (n % 4) + 4) % 4;

    if (f == cw && f == ccw) {
        cout << "undefined" << "\n";
    }
    else if (f == cw) {
        cout << "cw" << "\n";
    } else if (f == ccw) {
        cout << "ccw" << "\n";
    } else {
        cout << "undefined" << "\n";
    }
}