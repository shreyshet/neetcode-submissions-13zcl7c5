class Solution {
    int countTarget(int m, int minitarget, vector<int>& nums, int i, vector<vector<int>>& store){
        if(i > nums.size()) return 0;
        if (minitarget == 0 and i == nums.size()) return 1;
        else if (i == nums.size()) return 0;
        
        int j = minitarget + m;
        if(store[i][j] != -1) return store[i][j];

        return countTarget(m, minitarget - nums[i], nums, i+1, store) 
                + countTarget(m, minitarget + nums[i], nums, i+1, store);        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int m = 0;
        for(auto i: nums){
            m+=i;
        }
        if(abs(target) > m) return 0;
        vector<vector<int>> store(nums.size(), vector<int>(3*m + 1,-1));
        int ret = countTarget(m, target, nums, 0, store);
        return ret;
    }
};
