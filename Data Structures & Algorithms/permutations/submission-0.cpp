class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, subset, res, used);
        return res;
    }
private:    
    void dfs(const vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, vector<bool>& used) {
        if(subset.size() == nums.size()){
            res.push_back(subset);
            return;
        }
        for(int i =0; i < nums.size(); i++){
            if(used[i] == false){
                subset.push_back(nums[i]);
                used[i] = true;
                dfs(nums, subset, res, used);
                subset.pop_back();
                used[i] = false;
            } 
        }

    }
};
