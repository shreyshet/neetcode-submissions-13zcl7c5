class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        int l = 0, r = nums.size()-1; 
        while(l<=r){
            int mid = (l+r)/2;
            if(target == nums[mid]){
                ret = mid;
                break;
            }
            else if (target == nums[l]){
                ret = l;
                break;
            }
            else if (target == nums[r]){
                ret = r;
                break;
            }
            else{
                if(target>nums[mid]){
                 l = mid+1;   
                }
                else{
                 r = mid-1;   
                }
            }
        }
        return ret;
    }
};
