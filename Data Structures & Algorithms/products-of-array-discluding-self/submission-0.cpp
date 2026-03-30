class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            mul = 1;
            for(int j = 0; j < nums.size(); j++){
                if(i != j){
                     //cout<< i << " " << j << " ";
                    mul = mul*nums[j];
                }

            } 
            cout << endl << mul;
            output.push_back(mul); 
        }

        return output;
    }
};
