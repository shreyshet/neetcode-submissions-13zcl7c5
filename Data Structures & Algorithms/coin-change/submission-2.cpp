class Solution {
    int dfs(int amount, vector<int>& coins, vector<int>& memo){
        if (amount == 0) return 0;
        if(memo[amount] != -1) return memo[amount];
        int res = INT_MAX;
        for(int j = 0; j < coins.size();j++){
            if(amount-coins[j] < 0) continue;
            int nextstep = dfs(amount-coins[j], coins, memo);
            if(nextstep != INT_MAX){
                res = min(res,1+ nextstep);
            }
            //memo[amount] = min(memo[amount], 1 + dfs(amount-coins[j], coins, memo));
        }
        return memo[amount] = res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -1);

        int ret = -1;
        ret = dfs(amount, coins, memo);
        return (ret > amount) ? -1 : ret;
    }
};
