class Solution {
    int ways(int n, vector<int>& cache){
        if(n == 1 || n == 0) return 1;
        else if(n < 0) return 0;
        else if (cache[n] != 0) return cache[n];
        return cache[n] = ways(n-1,cache) + ways(n-2,cache);
    }

public:
    int climbStairs(int n) {
        vector<int> cache(45,0);
        return ways(n, cache);
    }
};
