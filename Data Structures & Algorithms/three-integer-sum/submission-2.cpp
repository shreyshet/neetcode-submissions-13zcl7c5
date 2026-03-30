class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0,left =1,right = nums.size()-1;
        vector<vector<int>> ret;
        while(i < nums.size()){
            if (nums[i] > 0) break;
            if((i>0) and (nums[i] == nums[i-1])) {i++; continue;}
            
            left = i+1;
            right = nums.size()-1;
            
            while(left<right){
                int s = nums[left] + nums[right] + nums[i];
                if(s > 0 ){
                    right--;
                }
                else if(s < 0){
                    left++;
                }
                else {
                    ret.push_back({nums[i],nums[left],nums[right]});
                    cout << i << " " << left << " " << right;
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                } 
            }

            i++;
        }
        return ret;
    }
};
