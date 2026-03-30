class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int len = 1;
        int max = 1;
        cout << endl;
        for(int i =1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                continue;
                //cout<< i << " Ignoring repeat" << endl;
            }
            else if ((nums[i]-nums[i-1])==1){
                len++;
                //cout<<i<<" Adding one" << endl;
                if(max < len) max = len;
            }
            else{
                len=1;
                //cout << max << " Max so far"<< endl;
            }
            
        }
        if(max < len) max = len;
        return max;
    }
};
