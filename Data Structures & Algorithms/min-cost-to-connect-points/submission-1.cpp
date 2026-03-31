class Solution {
public:
    int mandist(vector<int> p1, vector<int>p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    int findBoss(int i, vector<int>& parent) {
        if (parent[i] == i) return i;
        return findBoss(parent[i], parent);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;

        for(int i = 0; i<points.size();i++){
            for(int j = i+1; j < points.size();j++){
                edges.push({mandist(points[i],points[j]),i,j}); 
            }
        }
        int count = n;
        vector<int> parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i; 
        }
        int totalcost = 0;
        while(!edges.empty() && count > 0){
            vector<int> cur = edges.top();
            int d = cur[0];
            int u = cur[1];
            int v = cur[2];
            int rootU = findBoss(u, parent);
            int rootV = findBoss(v, parent);
            edges.pop();
            if (rootU == rootV) continue;
            parent[rootU] = rootV;
            totalcost += d;
            count--;
        }
        return totalcost;
    }
};
