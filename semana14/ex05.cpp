#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long r, b, k, maior, menor;
        cin >> r >> b >> k;

        maior = max(r, b);
        menor = min(r, b);

        if ((maior - 1 - gcd(r, b)) / menor + 1>= k)
            cout << "REBEL\n";
        else
            cout << "OBEY\n";
    }
}