class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        stack<pair<int,int>> checklist;
        //vector<vector<bool>> visited(m, vector<bool>(n,false));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O'){
                        checklist.push({i,j});
                        board[i][j] = '#';
                    }
                }
            }
        }
        vector<vector<int>> neighbours = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!checklist.empty()){
            pair<int,int> cur = checklist.top();
            checklist.pop();
            int x = cur.first;
            int y = cur.second;
            for( auto k : neighbours){
                int adjx = x + k[0];
                int adjy = y + k[1];
                if(adjx < m && adjx >= 0 && adjy < n && adjy >= 0){
                    if(board[adjx][adjy] == 'O'){
                        board[adjx][adjy] = '#';
                        checklist.push({adjx,adjy});
                    }
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                    if(board[i][j] == 'O'){
                        board[i][j] = 'X';
                    }
                    if(board[i][j] == '#'){
                        board[i][j] = 'O';
                    }
            }
        }

    }
};
