class Solution {
public:
    int maxsteal(int n, vector<int>& nums, vector<int>& memo, int p){
        if(n >= nums.size() and p == 0){
            return 0;
        }
        else if(n >= nums.size()-2 and p == 1){
            return 0;
        }
        if(memo[n] != -1) return memo[n];
        return memo[n] = max(nums[n] + maxsteal(n+2,nums, memo, p), maxsteal(n+1,nums, memo, p));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> memo1(n+1,-1);
        vector<int> memo2(n+1,-1);
        nums.push_back(0);
        int m1 = maxsteal(0,nums, memo1, 1);
        cout << " m1 " << m1 << endl;
        int m2 = maxsteal(1,nums, memo2, 0);
        cout << " m2 " << m2 << endl;
        return max(m1,m2);
    }
};