class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> rotten;
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int countFresh = 0;
        for(int i= 0; i<m; i++){
            for(int j =0; j<n;j++){
                if(grid[i][j]==2){
                    rotten.push({i,j});
                }
                else if(grid[i][j]==1){
                    countFresh++;
                }
            }
        }
        int minutes = 0;
        vector<vector<int>> neighbours = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!rotten.empty()){
            int curlayer = rotten.size();
            while(curlayer){
                curlayer--;
                pair<int,int> cur = rotten.front();
                rotten.pop();
                int x = cur.first;
                int y = cur.second;
                
                for(auto k: neighbours){
                    int adjx = x + k[0];
                    int adjy = y + k[1];
                    if(adjx >= m || adjy >= n || adjx < 0 || adjy < 0)
                        continue;
                    if(grid[adjx][adjy] == 1){
                        grid[adjx][adjy] = 2;
                        countFresh--;
                        rotten.push({adjx,adjy});
                    }
                }
            }

            if (!rotten.empty()) minutes++;   
            if(countFresh == 0) return minutes;
        }
        if(countFresh!=0) return -1;
        return minutes;
        
    }
};
