#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    for (long long k = 1; k <= n; k++) {

        long long total = k * k * (k * k - 1) / 2;

        long long ataca = 4 * (k - 1) * (k - 2);

        cout << total - ataca << '\n';
    }
}