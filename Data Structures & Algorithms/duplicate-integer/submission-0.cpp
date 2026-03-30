class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto i: nums){
            um[i]++;
        }
        for(auto i: um){
            if(i.second > 1) return true;
        }
        return false;
    }
};