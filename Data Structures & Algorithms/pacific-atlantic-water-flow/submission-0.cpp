class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        map<pair<int,int>,int> pacific;
        map<pair<int,int>,int> atlantic;
        vector<vector<int>> ret;
        stack<pair<int,int>> checklistpacific;
        stack<pair<int,int>> checklistatlantic;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0|| j == 0 ){
                    checklistpacific.push({i,j});
                    visited[i][j] = true;
                    pacific[{i,j}] = 1;   // Mark as reachable
                }
            }
        }
        vector<vector<int>> neighbours = {{1,0},{0,1},{-1,0},{0,-1}};

        while(!checklistpacific.empty()){
            pair<int,int> cur = checklistpacific.top();
            checklistpacific.pop();
            int x = cur.first;
            int y = cur.second;
            for(auto k: neighbours){
                int adjx = x + k[0];
                int adjy = y + k[1];
                if(adjx < 0 || adjy < 0 || adjx >= m || adjy >= n || visited[adjx][adjy] == true){
                    continue;
                }
                
                if(heights[adjx][adjy] >= heights[x][y]){
                    visited[adjx][adjy] = true;
                    checklistpacific.push({adjx,adjy});
                    pacific[{adjx,adjy}]++;
                }
            }

        }
        //visited.clear();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
                if(i == m-1|| j == n-1){
                    checklistatlantic.push({i,j});
                    visited[i][j] = true;
                    atlantic[{i,j}] = 1;   // Mark as reachable
                }
            }
        }

        while(!checklistatlantic.empty()){
            pair<int,int> cur = checklistatlantic.top();
            checklistatlantic.pop();
            int x = cur.first;
            int y = cur.second;
            for(auto k: neighbours){
                int adjx = x + k[0];
                int adjy = y + k[1];
                if(adjx < 0 || adjy < 0 || adjx >= m || adjy >= n || visited[adjx][adjy] == true){
                    continue;
                }
                
                if(heights[adjx][adjy] >= heights[x][y]){
                    visited[adjx][adjy] = true;
                    checklistatlantic.push({adjx,adjy});
                    atlantic[{adjx,adjy}]++;
                }
            }

        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // check pacific and atlantic
                if(pacific.find({i,j}) != pacific.end() and atlantic.find({i,j}) != atlantic.end()){
                   ret.push_back({i,j}); 
                }
            }
        }
        return ret;
    }
};
