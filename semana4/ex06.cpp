#include <bits/stdc++.h>
using namespace std;

bool tabuleiro[10][10];
bool visitado[10][10];

int deslocamento_linha[8] = {-2,-2,-1,-1,1,1,2,2};
int deslocamento_coluna[8] = {-1,1,-2,2,-2,2,-1,1}; 

int total, casas_alcancadas;

void teste(int l, int c, int cont) {
    casas_alcancadas = max(casas_alcancadas, cont);

    for (int i = 0; i < 8; i++) {
        int nova_linha = l + deslocamento_linha[i];
        int nova_coluna = c + deslocamento_coluna[i];

        if (nova_linha >= 0 && nova_linha < 10 && nova_coluna >= 0 && nova_coluna < 10) {
            if (tabuleiro[nova_linha][nova_coluna] && !visitado[nova_linha][nova_coluna]) {
                visitado[nova_linha][nova_coluna] = true;
                teste(nova_linha, nova_coluna, cont + 1);
                visitado[nova_linha][nova_coluna] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, caso = 1;

    while (cin >> n && n) {

        for (int i = 0; i < 10; i++)
            for (int j = 0 ; j < 10; j++) {
                tabuleiro[i][j] = false;
                visitado[i][j] = false;
            }

        total = 0;

        int linha_inicial = 0, coluna_inicial = 0;

        for (int i = 0; i < n; i++) {
            int skip, tamanho;
            cin >> skip >> tamanho;

            for (int j = skip; j < skip + tamanho; j++) {
                tabuleiro[i][j] = true;
                total++;

                if (i == 0 && j == skip)
                    coluna_inicial = j;
            }
        }

        casas_alcancadas = 0;

        visitado[0][coluna_inicial] = true;
        teste(0, coluna_inicial, 1);

        int nao_alcancadas = total - casas_alcancadas;

        cout << "Case " << caso++ << ", ";

        if (nao_alcancadas == 1)
            cout << "1 square can not be reached.\n";
        else  
            cout << nao_alcancadas << " squares can not be reached.\n";
    }
}