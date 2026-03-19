#include <bits/stdc++.h>
using namespace std;

vector<long long> n(10);
long long k;

vector<int> permutation;
vector<bool> chosen(10);

bool resolveu = false;

void generatePermutations(int pos, long long soma) {

    if (soma > k)
        return;

    if (pos == 10) {
        for (int i = 0; i < 10; i++)
            cout << permutation[i] << " ";
        cout << "\n";
        resolveu = true;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (chosen[i])
            continue;

        chosen[i] = true;
        permutation.push_back(i);

        generatePermutations(pos + 1, soma + i * n[pos]);

        if (resolveu)
            return;

        permutation.pop_back();
        chosen[i] = false;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        for(int i = 0; i < 10; i++)
            cin >> n[i];

        cin >> k;

        permutation.clear();

        resolveu = false;
        for (int i = 0; i < 10; i++)
            chosen[i] = false;
        generatePermutations(0, 0);

        if (!resolveu)
            cout << "-1\n";
    }
}

