class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> um;
        for(int i = 0; i < numbers.size(); i++){
            if(um.find(numbers[i]) != um.end()){
                auto it = um.find(numbers[i]);
                vector<int> ret = {it->second + 1, i + 1}; 
                return ret;
            }
            else{um[target - numbers[i]] = i;}
        }
        return {};
    }
};
