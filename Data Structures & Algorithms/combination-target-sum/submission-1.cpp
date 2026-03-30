class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        int sum = 0;
        dfs(nums, 0, subset, res, target, sum);
        return res;
    }
private:
    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res, int target, int sum) {
        
        if(sum == target){
            res.push_back(subset);
            return;
        }
        if ((i == nums.size())|| (sum>target)) {
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i, subset, res, target, sum+nums[i]);
        subset.pop_back();
        dfs(nums, i + 1, subset, res, target, sum);  
    }
};
