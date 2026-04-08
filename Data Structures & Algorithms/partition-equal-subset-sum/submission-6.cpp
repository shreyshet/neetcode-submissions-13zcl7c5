class Solution {
    bool findSS(int i, vector<int>& nums, int target, int curSum, vector<vector<int>>& memo){
        
        if(curSum == target) return true;
        if(i == nums.size()) return false;
        if (curSum > target) return false;
        if (memo[i][curSum] != -1) return memo[i][curSum];
        bool result = findSS(i + 1, nums, target, curSum + nums[i], memo);
        bool result2 = findSS(i + 1, nums, target, curSum, memo);
        return memo[i][curSum] = result || result2;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        
        if (sum%2 != 0) return false;
        int target = sum/2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        int curSum = 0;
        return findSS(0, nums, target, curSum, memo); 
    }
};