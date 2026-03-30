class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int max = 0;
        int b = 0;
        for(int i = 0; i<prices.size(); i++){
            for(int j =i; j<prices.size();j++){
                if((prices[j]-prices[i]) > max){
                    max = prices[j]-prices[i];
                    
                }
            }
        }
        return max;
    }
};
