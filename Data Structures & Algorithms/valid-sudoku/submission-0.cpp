class Solution {
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            unordered_map<char,int> umr;
            unordered_map<char,int> umc;
            unordered_map<char,int> umb;

            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.') umr[board[i][j]]++;
                if(board[j][i]!='.') umc[board[j][i]]++;                
                int r = (i/3)*3+(j/3);
                int c = (i%3)*3+(j%3);
                if(board[r][c]!='.') umb[board[r][c]]++;
                cout << board[i][j] << " " << board[j][i] << " " << board[r][c] << " " << endl;
                if(umr[board[i][j]]>1){
                    cout << " failed Row ";
                    return false;
                }
                if(umc[board[j][i]]>1){
                    cout << " failed Column ";
                    return false;
                }
                if(umb[board[r][c]]>1){
                    cout << " failed Box ";
                    return false;
                }
                
            }
            cout << " NEXT "<< endl;

        }
        
        return true;
    }
};
