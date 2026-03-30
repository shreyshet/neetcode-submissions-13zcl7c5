class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        vector<int> output;
        output.push_back(1);
        for(int i = 1; i < nums.size(); i++){
            mul = mul*nums[i-1];
            output.push_back(mul); 
        }

        mul = 1;
        for(int j = (nums.size()-2); j >=0; j--){
           mul = mul*nums[j+1];
           output[j] = output[j]*mul;
        }

        return output;
    }
};
