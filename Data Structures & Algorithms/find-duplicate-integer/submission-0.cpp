class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto i:nums){
            um[i]++;
            if(um[i]>1){
                return i;
            }
        }
        return 0;
    }
};
