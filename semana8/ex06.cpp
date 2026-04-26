#include <bits/stdc++.h>
using namespace std;

int n, m;
char mapa[1005][1005];
int tempo_monstro[1005][1005];
int meu_tempo[1005][1005];
char anterior_direcao[1005][1005];

int dl[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
char dirChar[] = {'R', 'L', 'D', 'U'};

bool eh_borda(int l, int c) {
    return (l == 0 || l == n - 1 || c == 0 || c == m - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    queue<pair<int, int>> fila_monstros;
    pair<int, int> inicio;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
            tempo_monstro[i][j] = 0x3f3f3f3f;
            meu_tempo[i][j] = 0x3f3f3f3f;
            if (mapa[i][j] == 'M') {
                tempo_monstro[i][j] = 0;
                fila_monstros.push({i, j});
            } else if (mapa[i][j] == 'A') {
                inicio = {i, j};
                meu_tempo[i][j] = 0;
            }
        }
    }

    while (!fila_monstros.empty()) {
        pair<int, int> atual = fila_monstros.front();
        fila_monstros.pop();

        for (int i = 0; i < 4; i++) {
            int nl = atual.first + dl[i];
            int nc = atual.second + dc[i];
            if (nl >= 0 && nl < n && nc >= 0 && nc < m && mapa[nl][nc] == '.' && tempo_monstro[nl][nc] == 0x3f3f3f3f) {
                tempo_monstro[nl][nc] = tempo_monstro[atual.first][atual.second] + 1;
                fila_monstros.push({nl, nc});
            }
        }
    }

    queue<pair<int, int>> fila_eu;
    fila_eu.push(inicio);
    
    if (eh_borda(inicio.first, inicio.second)) {
        cout << "YES\n0\n";
        return 0;
    }

    while (!fila_eu.empty()) {
        pair<int, int> atual = fila_eu.front();
        fila_eu.pop();

        for (int i = 0; i < 4; i++) {
            int nl = atual.first + dl[i];
            int nc = atual.second + dc[i];

            if (nl >= 0 && nl < n && nc >= 0 && nc < m && mapa[nl][nc] == '.' && meu_tempo[nl][nc] == 0x3f3f3f3f) {
                int proximo_tempo = meu_tempo[atual.first][atual.second] + 1;
                
                if (proximo_tempo < tempo_monstro[nl][nc]) {
                    meu_tempo[nl][nc] = proximo_tempo;
                    anterior_direcao[nl][nc] = dirChar[i];
                    
                    if (eh_borda(nl, nc)) {
                        cout << "YES\n";
                        string caminho = "";
                        int cl = nl, cc = nc;
                        while (cl != inicio.first || cc != inicio.second) {
                            char d = anterior_direcao[cl][cc];
                            caminho += d;
                            if (d == 'R') 
                                cc--;
                            else if (d == 'L') 
                                cc++;
                            else if (d == 'D') 
                                cl--;
                            else if (d == 'U') 
                                cl++;
                        }
                        reverse(caminho.begin(), caminho.end());
                        cout << caminho.length() << "\n" << caminho << "\n";
                        return 0;
                    }
                    fila_eu.push({nl, nc});
                }
            }
        }
    }
    cout << "NO\n";
}