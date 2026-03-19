#include <bits/stdc++.h>
using namespace std;

vector<string> tab(8);
bool col[8];
bool diagp[15];
bool diags[15];
int resp = 0;

void colocaRainha(int linha) {

    if (linha == 8) {
        resp++;
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (tab[linha][j] == '*')
            continue;

        if (col[j] || diagp[linha - j + 7] || diags[linha + j])
            continue;
            
        col[j] = diagp[linha - j + 7] = diags[linha + j] = true;

        colocaRainha(linha + 1);

        col[j] = diagp[linha - j + 7] = diags[linha + j] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++)
        cin >> tab[i];

    colocaRainha(0);

    cout << resp << "\n";
}