#include <bits/stdc++.h>
using namespace std;

long long comprimento(long long n) {
    if (n <= 1) 
        return 1;

    return 2 * comprimento(n / 2) + 1;
}

long long procura_1(long long n, long long l, long long r, long long l_atual, long long r_atual) {
    if (l_atual > r || r_atual < l) 
        return 0;

    if (n <= 1) 
        return n;

    long long meio = (l_atual + r_atual) / 2;
    long long res = 0;

    res += procura_1(n / 2, l, r, l_atual, meio - 1);

    if (meio >= l && meio <= r) {
        res += (n % 2);
    }

    res += procura_1(n / 2, l, r, meio + 1, r_atual);

    return res;
}

int main() {
    long long n, l, r;
    cin >> n >> l >> r;

    if (n == 0) {
        cout << 0 << "\n";
    } else {
        long long c = comprimento(n);
        cout << procura_1(n, l, r, 1, c) << "\n";
    }  
}