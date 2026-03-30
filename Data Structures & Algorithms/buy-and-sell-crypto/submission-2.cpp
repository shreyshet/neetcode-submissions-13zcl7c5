class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxp = 0; int mind = prices[0];
        for(int i = 0; i<prices.size(); i++){
            maxp = max(maxp,prices[i]-mind);
            mind = min(mind,prices[i]);
        }

        return maxp;
    }
};
