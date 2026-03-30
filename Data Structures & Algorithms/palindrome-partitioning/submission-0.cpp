class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> subset;
        dfs(0, s, ret, subset);
        return ret;
    }
private:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void dfs(int i, string s, vector<vector<string>>& ret, vector<string>& subset){

        if (i == s.size()) {
            ret.push_back(subset);
            return;
        }
        
        for(int j = i; j < s.length(); j++){
            if(isPalindrome(s, i, j)){
                subset.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,ret,subset);
                subset.pop_back();
            }

        }        
    }    
};
