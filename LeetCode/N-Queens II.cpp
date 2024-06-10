class Solution {
public:
    bool isSafe(vector<string>& board, int n, int row, int col){
        for(int i = row; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = col; i >= 0; i--){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        int i = row;
        int j = col;
        while(i >= 0 && j >=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--; j--;
        }
        i = row;
        j = col;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--; j++;
        }
        return true;

    }

    void backtrack(int& ans, vector<string>& board, int n, int row, int count){
        if(count == n){
            ans++;
            return;
        }

        for(int i = 0; i < n; i++){
            if(isSafe(board, n, row, i)){
                board[row][i] = 'Q';
                count++;
                backtrack(ans, board, n, row+1, count);
                board[row][i] = '.';
                count--;
            }
        }

    }


    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));

        backtrack(ans, board, n, 0, 0);
        return ans;
    }
};
