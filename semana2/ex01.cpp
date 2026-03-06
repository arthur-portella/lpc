#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, exercicios = 0;
    cin >> n;

    vector<int> v;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i+=2) {
        if (v[i] != v[i+1])
            exercicios +=  v[i+1] - v[i]; 
    }

    cout << exercicios << "\n";
}