class Solution {
public:
    int findPath(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo, int& ret){
        if(i>= matrix.size() or j >= matrix[0].size() or i < 0 or j < 0) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        
        int a = 1, b = 1, c = 1, d = 1;
        
        if(i + 1 < matrix.size() and matrix[i+1][j] > matrix[i][j]) 
        { a = findPath(matrix, i+1, j, memo, ret) + 1;
        } 
        if(j + 1 < matrix[0].size() and matrix[i][j+1] > matrix[i][j]) 
        { b = findPath(matrix, i, j+1, memo, ret) + 1;
        } 
        if(i - 1 >= 0 and matrix[i-1][j] > matrix[i][j]) 
        { c = findPath(matrix, i-1, j, memo, ret) + 1;
        } 
        if(j - 1 >= 0 and matrix[i][j-1] > matrix[i][j]) 
        { d = findPath(matrix, i, j-1, memo, ret) + 1;
        }
        memo[i][j] = max(max(a,b),max(c,d));
        ret = max(ret,memo[i][j]);
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(),vector<int>(matrix[0].size(), -1));
        int ret = 1;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                findPath(matrix, i, j, memo, ret);      
            }
        }
        return ret;
    }
};
