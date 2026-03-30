class Solution {

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        priority_queue<pair<int,int>> heapdist;
        for(int i =0; i < points.size(); i++){
            heapdist.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
            if(i>=k){
                heapdist.pop();
            }
        }
        while(!heapdist.empty()){
           ret.push_back(points[heapdist.top().second]);
           heapdist.pop();
        }

        return ret;
    }
};
