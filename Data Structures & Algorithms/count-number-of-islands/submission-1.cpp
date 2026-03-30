class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        int m = grid.size();
        int n = grid[0].size();

        // Boundary and visited/water check
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;

        grid[i][j] = '0';
        
    // 4-directional DFS: up, down, left, right
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
