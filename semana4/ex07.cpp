#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c, d;
        cin >> a >> b;
        cin >> c >> d;

        if (b - a != 1 || d - c != 1) {
            cout << "-1\n";
            continue;
        }

        long long w = c - a;

        if (w < 2 || a % w == 0) {
            cout << "-1\n";
            continue;
        }

        if (c != a + w || d != b + w) {
            cout << "-1\n";
            continue;
        }

        long long h = max((long long)2, (d + w - 1) / w);

        cout << h << " " << w << "\n";
    }
}