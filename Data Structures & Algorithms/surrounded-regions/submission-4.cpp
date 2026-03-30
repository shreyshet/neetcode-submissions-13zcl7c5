class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        stack<pair<int,int>> checklist;
        //vector<vector<bool>> visited(m, vector<bool>(n,false));
        
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O'){ checklist.push({i,0});  board[i][0] = '#';}
            if(board[i][n-1] == 'O'){ checklist.push({i,n-1});  board[i][n-1] = '#';}
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O'){ checklist.push({0,j});  board[0][j] = '#';}
            if(board[m-1][j] == 'O') { checklist.push({m-1,j});  board[m-1][j] = '#';}
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
