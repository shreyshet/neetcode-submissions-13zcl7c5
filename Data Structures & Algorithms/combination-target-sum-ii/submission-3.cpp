class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                vector<vector<int>> res;
                        vector<int> subset;
                                int sum = 0;
                                        sort(candidates.begin(),candidates.end());
                                                dfs(candidates, 0, subset, res, target, sum);
                                                        return res;
                                                            }
                                                            private:
                                                                void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res, int target, int sum) {
                                                                        if(sum == target){
                                                                                    res.push_back(subset);
                                                                                                return;
                                                                                                        }
                                                                                                                if ((i == nums.size())|| (sum>target)) {
                                                                                                                            return;
                                                                                                                                    }
                                                                                                                                            subset.push_back(nums[i]);
                                                                                                                                                    dfs(nums, i + 1, subset, res, target, sum+nums[i]);
                                                                                                                                                            subset.pop_back();

                                                                                                                                                                    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                                                                                                                                                                            i++; 
                                                                                                                                                                                    }
                                                                                                                                                                                            
                                                                                                                                                                                                    dfs(nums, i + 1, subset, res, target, sum);  
                                                                                                                                                                                                        }
                                                                                                                                                                                                        };
