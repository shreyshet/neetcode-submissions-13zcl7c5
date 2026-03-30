class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int ret = -1;
        while(l<=r){
            int m = l + (r-l)/2;
            cout << l << " " << r << " " << m << endl;
            if(nums[m] == target){
                ret = m;
                break;
            }
            if(nums[l]<=nums[m]){
                if (target > nums[m] || target < nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            else{
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

        }
        return ret;
    }
};
