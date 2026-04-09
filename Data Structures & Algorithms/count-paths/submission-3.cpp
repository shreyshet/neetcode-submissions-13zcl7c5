class Solution {
    int totalPaths(int m, int n, int i, int j, vector<vector<int>>& memo){
        if(i<0) return 0;
        if(j<0) return 0;
        if(i==0 and j == 0) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = totalPaths(m,n,i-1,j, memo) + totalPaths(m,n,i,j-1, memo);  
    }
public:
    int uniquePaths(int m, int n) {
        int count = 0;
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return totalPaths(m,n,m-1,n-1, memo);
    }
};
