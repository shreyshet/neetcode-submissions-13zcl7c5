class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                        unordered_map<int, int> um;
                                for(int i = 0; i < nums.size(); i++){
                                            if(um.find(nums[i]) != um.end()){
                                                            auto it = um.find(nums[i]);
                                                                            vector<int> ret = {it->second, i}; 
                                                                                            return ret;
                                                                                                        }
                                                                                                                    else{um[target - nums[i]] = i;}
                                                                                                                            }
                                                                                                                                    return {};
                                                                                                                                        }
                                                                                                                                        

        
    
};
