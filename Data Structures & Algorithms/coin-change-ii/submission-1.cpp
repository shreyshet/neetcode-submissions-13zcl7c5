class Solution {
public:
    int countchange(int target, int i, vector<int>& coins,vector<vector<int>>& store){
        if (i >= coins.size()) return 0;
        if(target < 0) return 0;
        if(target <= 0) return 1;
        if (store[i][target] != -1) return store[i][target];
        int ways = 0;
        for(int j = i; j < coins.size(); j++){
            ways += countchange(target - coins[j], j, coins, store);
        } 
        return store[i][target] = ways;
    }

    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        vector<vector<int>> store(coins.size(),vector<int>(amount+1,-1));
        int ret = 0;
        ret = countchange(amount,0,coins,store);
        return ret;
    }
};
