class Solution {

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> treasures;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    treasures.push({i,j});
                }
            }   
        }
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!treasures.empty()){
            auto [r, c] = treasures.front();
            treasures.pop();
            
            for (auto& dir : d) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // valid land cell
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1) {
                    // If not visited AND not treasure AND not already minimized
                    if (grid[nr][nc] > grid[r][c] + 1) {
                        grid[nr][nc] = grid[r][c] + 1;
                        treasures.push({nr, nc});
                    }
                }
            }
        }

    }
};
