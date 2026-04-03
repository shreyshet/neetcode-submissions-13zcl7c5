class Solution {
public:
    int dfs(int i, string& s, vector<int>& memo){
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0;
        if(memo[i] != -1) return memo[i];
        int single =  dfs(i+1, s, memo);
        int twochar = 0;
        if (i+1 < s.size()){
            if(s[i] == '1') twochar = dfs(i+2, s, memo);
            else if (s[i] == '2' and s[i+1] <= '6') twochar = dfs(i+2, s, memo);
        }
        return memo[i] =  single + twochar;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> memo(s.size()+1, -1);
        return dfs(0,s,memo);
    }
};
