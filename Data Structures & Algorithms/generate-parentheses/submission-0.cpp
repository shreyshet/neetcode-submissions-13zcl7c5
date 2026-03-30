class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subset;
        dfs(n,0,0, subset, res);
        return res;
    }
private:
    void dfs(int n, int open, int close, string& subset, vector<string>& res) {
        if (subset.length() == 2 * n) {
        res.push_back(subset);
        return;
        }
        if(open < n){
            subset.push_back('(');
            dfs(n, open+1, close, subset, res);
            subset.pop_back();
        }
        if(close< open){
            subset.push_back(')');
            dfs(n, open, close+1, subset, res);
            subset.pop_back();
        }        
    }   
};
