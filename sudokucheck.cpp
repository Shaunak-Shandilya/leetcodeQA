// O(1) complexity beats 86.7% in space and 66.4% in time

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
            for (int j = 0; j < 9; j++) {
                if (board[i][j] < 49 || board[i][j] > 57) continue;
                arr[int(board[i][j] - '0')]++;
            }
            for (int k = 0; k <= 9; k++) {
                if (arr[k] > 1) return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
            for (int j = 0; j < 9; j++) {
                if (board[j][i] < 49 || board[j][i] > 57) continue;
                arr[int(board[j][i] - '0')]++;
            }
            for (int k = 0; k <= 9; k++) {
                if (arr[k] > 1) return false;
            }
        }

        for (int i = 1; i <= 7; i += 3) {
            for (int j = 1; j <= 7; j += 3) {
                int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
                for (int p = i - 1; p <= i + 1; p++) {
                    for (int q = j - 1; q <= j + 1; q++) {
                        if (board[p][q] < 49 || board[p][q] > 57) continue;
                        arr[int(board[p][q] - '0')]++;
                    }
                }
                for (int k = 0; k <= 9; k++) {
                    if (arr[k] > 1) return false;
                }
            }
        }
        return true;
    }
};
