class Solution {
public:
    int count = 0;
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;

    int totalNQueens(int n) {
        cols.resize(n, false);
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);

        solve(0, n);
        return count;
    }

    void solve(int row, int n) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {

            int d1 = row - col + n - 1; // Main diagonal (\)
            int d2 = row + col;         // Anti-diagonal (/)

            if (cols[col] || diag1[d1] || diag2[d2])
                continue;

            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solve(row + 1, n);

            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};