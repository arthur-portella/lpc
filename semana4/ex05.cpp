#include <bits/stdc++.h>
using namespace std;

vector<int> w;
long long total = 0;
long long resp = 0x3f3f3f3f;

void generateSubsets(int index, long long soma) {

    if (index == w.size()) {
        long long dif = abs ((total - soma) - soma);
        resp = min(resp, dif);
        return;
    }

    generateSubsets(index + 1, soma);
 
    generateSubsets(index + 1, soma + w[index]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    w.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i];
        total += w[i];
    }

    generateSubsets(0, 0);

    cout << resp << '\n';
}