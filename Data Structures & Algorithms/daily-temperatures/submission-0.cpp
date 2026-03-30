class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(),0);
    stack<int> s;
    int j = 0;
    for(int i = 0; i<temperatures.size(); i++){
        while(!s.empty()){ 
            if((temperatures[i] - temperatures[s.top()]) > 0){
                res[s.top()] = i-s.top();
                s.pop();   
            }
            else{
                break;
            }
        }
        s.push(i);
    }
    return res;             
    }
};
