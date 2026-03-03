#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<string> fila;

    fila.push("Sheldon");
    fila.push("Leonard");
    fila.push("Penny");
    fila.push("Rajesh");
    fila.push("Howard");

    long long n;
    cin >> n;

    string nome;
    for (int i = 1; i <= n; i++) {
        nome = fila.front();
        fila.pop();
        fila.push(nome);
        fila.push(nome);
    }

    cout << nome << "\n";
}