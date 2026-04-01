class Solution {
public:
    int maxsteal(int n, vector<int>& nums, vector<int>& memo){
        if(n < 0){
            return 0;
        }
        if(memo[n] != -1) return memo[n];
        return memo[n] = max(nums[n] + maxsteal(n-2,nums, memo), maxsteal(n-1,nums, memo));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+1,-1);
        nums.push_back(0);
        return maxsteal(n,nums, memo);
    }
};
