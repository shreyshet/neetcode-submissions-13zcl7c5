class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        //ret.push_back({});
        int l = pow(2,nums.size()); 
        for(int i = 0; i < l; i++){
            vector<int> x;
            for (int j = 0; j < nums.size(); ++j) {
                // Check if the i-th bit is set to 1
                if (i & (1 << j)) {
                    x.push_back(nums[j]);
                    // Access the vector at index i
                    std::cout << "Bit " << i << " is 1. Vector element: " << nums[i] << std::endl;
                }
            }
            ret.push_back(x);
        }
        return ret;
    }
};
