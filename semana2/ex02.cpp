#include <bits/stdc++.h>
using namespace std;

void back(deque<int> &fila) {
    if (fila.empty()) {
        cout << "No job for Ada?" << "\n";
        return;
    }
    cout << fila.back() << "\n";
    fila.pop_back();
}

void front(deque<int> &fila) {
    if (fila.empty()) {
        cout << "No job for Ada?" << "\n";
        return;
    }
    cout << fila.front() << "\n";
    fila.pop_front();
}

void push_back(deque<int> &fila, int v) {
    fila.push_back(v);
}

void toFront(deque<int> &fila, int v) {
    fila.push_front(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> fila;

    int q;
    cin >> q;

    bool reversed = false;
    string acao;
    for (int i = 0; i < q; i++) {
        cin >> acao; 

        if (acao == "front") {
            if (!reversed)
                front(fila);
            else
                back(fila);
        } else if (acao == "back") {
            if (!reversed)
                back(fila);
            else
                front(fila);
        } else if (acao == "reverse") {
            reversed = !reversed;
        } else if (acao == "push_back") {
            int valor;
            cin >> valor;
            if (!reversed)
                push_back(fila, valor);
            else
                toFront(fila, valor);
        } else if (acao == "toFront") {
            int valor;
            cin >> valor;
            if (!reversed)
                toFront(fila, valor);
            else
                push_back(fila, valor);
        }
    }
}