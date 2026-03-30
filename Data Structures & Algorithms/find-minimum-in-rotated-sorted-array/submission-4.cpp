class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int ret = 0;
        while(l<=r){
            int mid = l+ (r-l)/2;
            int a = (mid == 0)? nums.size()-1:(mid-1);
            int b = (mid == (nums.size()-1))? 0:(mid+1);

            //cout << nums[mid] << " " << nums[a] << " " << nums[b] <<  endl;
            
            if ((nums[mid] <= nums[b]) and (nums[mid] <= nums[a])){
                ret = nums[mid];
                break;
            }
            //cout << l << " " << r << " " << mid <<  endl;
            //cout << nums[a] << " " << nums[b] << endl;

            if((nums[mid] >= nums[l]) and (nums[mid] > nums[r])){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
            ret = min(nums[l],nums[r]);
            //cout << ret <<  endl;
            //cout << l << " " << r << " " << mid <<  endl;

        }
        return ret;
    }
};
