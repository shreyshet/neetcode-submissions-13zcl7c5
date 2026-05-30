class Solution {
public:
    int checkInterleave(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &memo){
        if(k == s3.size()) return 1;
        if(memo[i][j] != -1) return memo[i][j];
        int a = 0;
        int b = 0;
        if(i < s1.size() and s1[i] == s3[k]) a = checkInterleave(s1,s2,s3,i+1,j,k+1, memo);
        if(j < s2.size() and s2[j] == s3[k]) b = checkInterleave(s1,s2,s3,i,j+1,k+1, memo); 
        return memo[i][j] = (a or b);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return checkInterleave(s1,s2,s3,0,0,0, memo);

    }
};
