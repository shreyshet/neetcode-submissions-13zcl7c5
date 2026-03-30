class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int ar = 0, max =0;
        while(left<right){
            if(heights[left] <= heights[right]){
                ar = heights[left]*(right-left);
                left++;
            }
            else if(heights[left] > heights[right]){
                ar = heights[right]*(right-left);
                right--;
            }
            if (ar > max) max = ar;
        }
        return max;
    }
};
