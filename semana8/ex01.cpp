#include <bits/stdc++.h>
using namespace std;

int n, m;
char mapa[1005][1005];
char anteriorDir[1005][1005];
bool visitado[1005][1005];

int dl[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
char dirChar[] = {'R', 'L', 'D', 'U'};

void bfs(int linha_inicial, int coluna_inicial) {
    queue<pair<int, int>> fila;
    
    fila.push({linha_inicial, coluna_inicial});
    visitado[linha_inicial][coluna_inicial] = true;

    while (!fila.empty()) {
        pair<int, int> atual = fila.front();
        fila.pop();

        int l = atual.first;
        int c = atual.second;

        if (mapa[l][c] == 'B') return;

        for (int i = 0; i < 4; i++) {
            int nova_linha = l + dl[i];
            int nova_coluna = c + dc[i];

            if (nova_linha >= 0 && nova_linha < n && nova_coluna >= 0 && nova_coluna < m && mapa[nova_linha][nova_coluna] != '#' && !visitado[nova_linha][nova_coluna]) {
                visitado[nova_linha][nova_coluna] = true;
                anteriorDir[nova_linha][nova_coluna] = dirChar[i];
                fila.push({nova_linha, nova_coluna});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int linha_inicial, coluna_inicial, linha_final, coluna_final;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'A') {
                linha_inicial = i; coluna_inicial = j;
            } else if (mapa[i][j] == 'B') {
                linha_final = i; coluna_final = j;
            }
        }
    }

    bfs(linha_inicial, coluna_inicial);

    if (!visitado[linha_final][coluna_final]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string caminho = "";
        int linha_atual = linha_final, coluna_atual = coluna_final;

        while (linha_atual != linha_inicial || coluna_atual != coluna_inicial) {
            char d = anteriorDir[linha_atual][coluna_atual];
            caminho += d;
            
            if (d == 'R') coluna_atual--;
            else if (d == 'L') coluna_atual++;
            else if (d == 'D') linha_atual--;
            else if (d == 'U') linha_atual++;
        }

        reverse(caminho.begin(), caminho.end());
        
        cout << caminho.length() << "\n";
        cout << caminho << "\n";
    }
}