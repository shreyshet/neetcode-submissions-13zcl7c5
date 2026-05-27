class Solution {
public:
    int profit(vector<int> prices, int i, vector<vector<int>>& store, int hold){
        if(i >= prices.size()) return 0;
        if(store[i][hold] != -1) return store[i][hold];
        
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

        if(hold == 1){
            // case 1 sell
            c1 = prices[i] + profit(prices, i+2, store, 0);
            // case 2 do nothing
            c2 = 0 + profit(prices, i+1, store, 1);
            return store[i][hold] = max(c1, c2);
        }
        if(hold == 0){
        // case 1 buy
        c3 = -prices[i] + profit(prices, i+1, store, 1);
        // case 2 do nothing
        c4 = profit(prices, i+1, store, 0);
        return store[i][hold] = max(c3, c4);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> store(prices.size(), vector<int>(2,-1));
        int ret = 0;
        ret = profit(prices,0,store, 0);
        return ret;
    }
};
