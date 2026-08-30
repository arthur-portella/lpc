#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        map<pair<int, int>, long long> mapa12;
        map<pair<int, int>, long long> mapa13;
        map<pair<int, int>, long long> mapa23;
        map<tuple<int, int, int>, long long> mapa123;

        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int x = a[i];
            int y = a[i + 1];
            int z = a[i + 2];

            ans += mapa12[{x, y}];
            ans += mapa13[{x, z}];
            ans += mapa23[{y, z}];

            ans -= 3 * mapa123[{x, y, z}];

            mapa12[{x, y}]++;
            mapa13[{x, z}]++;
            mapa23[{y, z}]++;
            mapa123[{x, y, z}]++;
        }
        cout << ans << '\n';
    }
}