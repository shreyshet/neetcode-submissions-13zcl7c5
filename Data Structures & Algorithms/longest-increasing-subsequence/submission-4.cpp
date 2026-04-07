class Solution {
    int findMaxSS(int ind, vector<int>& nums, vector<int>& memo){
        // for each neighbor try to find max SS
        if(ind >= nums.size()) return 0;
        if(memo[ind] != -1) return memo[ind];
        int ret = 1;
        for(int i = ind+1; i < nums.size(); i++){
            if (nums[i] <= nums[ind]) continue;
            ret = max(1 + findMaxSS(i,nums,memo), ret);
        }
        return memo[ind] = ret;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        int maxcount = 0;
        for(int i = 0; i < nums.size(); i++){
            maxcount = max(maxcount, findMaxSS(i,nums,memo));
        }
        return maxcount;
    }
};
