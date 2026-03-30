class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        vector<string> subset(n, string(n,'.'));
        dfs(n,0,board,subset);
        return board;
    }
    private:
    bool checkposs(vector<string>& subset, int i, int j){
        for(int x = 1; x<=j; x++){
           if (subset[i][j - x] == 'Q') return false;

            // 2. Check upper-left diagonal
            if (i - x >= 0 && subset[i - x][j - x] == 'Q') return false;

            // 3. Check lower-left diagonal
            if (i + x < subset.size() && subset[i + x][j - x] == 'Q') return false;
        }
        return true;
    }
    void dfs(int n, int j, vector<vector<string>>& board, vector<string>& subset){
        if(j==n){
            board.push_back(subset);
            return;
        }
        for(int k =0; k < n; k++){
            if(checkposs(subset, k, j)){
                subset[k][j] = 'Q';
                dfs(n,j+1,board,subset);
                subset[k][j] = '.';
            }
        }        
    }
};
