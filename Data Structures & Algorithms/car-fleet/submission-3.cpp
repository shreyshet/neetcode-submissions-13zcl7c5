class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ret = 0;
        float currmax = 0.0f;
        vector<pair<int,float>> combined;
        for (int i = 0; i < position.size(); ++i) {
            float t1 = (float)(target - position[i])/speed[i];
            combined.push_back({position[i], t1});
        }
        std::sort(combined.begin(), combined.end(), [](pair<int, float> a, pair<int, float> b){ return a.first > b.first;});
        stack<pair<int,float>> fleet;
        for(int i = 0; i < position.size(); i++){
            cout << combined[i].first << " " << combined[i].second << endl;   
            
            if(fleet.empty()){ fleet.push(combined[i]); ret++; continue;}

            
            if(fleet.top().second >= combined[i].second){}
            else{ fleet.push(combined[i]); ret++;} 
        }
        
        return ret;
    }
};
