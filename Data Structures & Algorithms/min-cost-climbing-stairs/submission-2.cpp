class Solution {
public:
    int calcost(int n, vector<int>& cost, vector<int>& cache){
        if(n == 0 || n == 1){
            return 0;
        }
        else if(cache[n] != -1) return cache[n];
        return cache[n] = min(cost[n-1] + calcost(n-1, cost, cache), cost[n-2] + calcost(n-2, cost, cache));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> cache(n+1, -1);
        return calcost(n,cost,cache);
    }
};
