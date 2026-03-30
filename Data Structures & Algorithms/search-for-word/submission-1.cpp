class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        map<pair<int,int>,bool> visited;
        bool found = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(i, j, board, word, 0, visited, found);
            }   
        }
        return found;
    }
private:
    void dfs(int i, int j, vector<vector<char>>& board, string word, int k, map<pair<int,int>,bool>& visited, bool& found){
        if (k>=word.size()){
            found = true; return;
        }
        if(i >= board.size() || j >=board[0].size() || i<0 || j<0 ){
            return;
        }
        if(visited[{i,j}] == true){
            return;
        }
        
        if(board[i][j] != word[k]){
            return;
        }
        visited[{i,j}] = true;        
        dfs(i+1, j, board, word, k+1, visited, found);
        dfs(i, j+1, board, word, k+1, visited, found);
        dfs(i-1, j, board, word, k+1, visited, found);
        dfs(i, j-1, board, word, k+1, visited, found);
        visited[{i,j}] = false; 

    }
};
