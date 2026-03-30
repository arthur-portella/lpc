#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long qte1, qte2, preco;

        if (2*a <= b) {
            preco = n * a;
        } else {
            qte2 = n / 2;
            qte1 = n % 2;

            preco = qte1 * a + qte2 * b;
        }

        cout << preco << "\n";
    }
}