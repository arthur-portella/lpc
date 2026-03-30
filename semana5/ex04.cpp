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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int min_removidos = 0x3f3f3f3f;    
        for (int i = 0; i < n;  i++) {
            int removidos = 0;
            if (i != 0) 
                removidos += i;
            for (int j = i+1; j < n; j++) {
                if (a[j] > a[i])
                    removidos++;
            }
            min_removidos = min(min_removidos, removidos);
        }

        cout << min_removidos << "\n";
    }
}