#include <bits/stdc++.h>
using namespace std;

long long potencia(long long base, long long expoente, long long modulo) {
    if (expoente == 0)
        return 1;

    long long res = potencia(base, expoente/2, modulo);
    res = (res * res) % modulo;

    if (expoente % 2 == 1) {
        res = (res * base) % modulo;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long modulo = 1e9 + 7;

        long long exp = potencia(b, c, modulo - 1);
        long long resultado = potencia(a, exp, modulo);

        cout << resultado << "\n";
    }
}