class Solution {
public:
    void makeZero(int m, int n, int row, int col, vector<vector<int>>& matrix){
        for(int i = row; i >= 0; i--){
            matrix[i][col] = 0;
        }
        for(int i = row; i < m ; i++){
            matrix[i][col] = 0;
        }
        for(int i = col; i >= 0; i--){
            matrix[row][i] = 0;
        }
        for(int i = col; i < n; i++){
            matrix[row][i] = 0;
        }

    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> zeroes;
        for(int row = 0; row < m ; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0){
                    zeroes.push_back(make_pair(row, col));
                }
            }
        }
        for(auto it : zeroes){
            makeZero(m, n, it.first, it.second, matrix);
        }
    }
};
