class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxEnd = nums[0];
        int minEnd = nums[0];
        for( int i = 1; i< nums.size(); i++){
            int temp = maxEnd; 
            maxEnd = max(max(nums[i], temp*nums[i]), minEnd*nums[i]);
            minEnd = min(min(nums[i], temp*nums[i]), minEnd*nums[i]);
            res = max(res,maxEnd);
        }
        return res;
    }
};
