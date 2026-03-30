class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        int area = 0;
        for(int i = 0; i<heights.size(); i++){
            int left = i;
            int right = i;
            int area = 0;
            for(int j = i-1; j>=0; j--){
                if(heights[j]>=heights[i]){
                    left = j;
                }
                else{
                    break;
                }
            }
            
            for(int k = i+1; k<heights.size(); k++){
                if(heights[k]>=heights[i]){
                    right = k;
                }
                else{
                    break;
                }
            }

            
            if(right == left){
                area = heights[i];
            }
            else{
                
            }
            area = (right-left + 1)*heights[i];
            ret = max(ret, area);
            cout << left << " " << right << " " << area << " " << ret<<  endl;
        }
        return ret;
    }
};
