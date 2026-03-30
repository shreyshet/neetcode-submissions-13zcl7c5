class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, int& count){
       
        int m = grid.size();
        int n = grid[0].size();

        // Boundary and visited/water check
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        count++;
        grid[i][j] = 0;
       
    // 4-directional DFS: up, down, left, right
        dfs(grid, i + 1, j, count);
        dfs(grid, i - 1, j, count);
        dfs(grid, i, j + 1, count);
        dfs(grid, i, j - 1, count);

        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int max_count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count = 0;
                    dfs(grid,i,j,count);
                    max_count = max(max_count,count);
                }
            }
        }
        return max_count;
    }
};
