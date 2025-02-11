#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

bool safe(vector<int>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) { //ista col ili dijagonala
            return false;
        }
    }
    return true;
}

void solve(vector<int>& board, int row, int n) {
    if (row == n) {//posledna kralica za 1 slucaj
        cnt++; 
        return;
    }
    for (int col = 0; col < n; col++) {
        if (safe(board, row, col, n)) {
            board[row] = col; 
            solve(board, row + 1, n);  //vidi za sledno
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int>board(n, -1); //vo itiot red na koja poz se naogja queen
    solve(board, 0, n);

    cout <<cnt<< endl;
    return 0;
}