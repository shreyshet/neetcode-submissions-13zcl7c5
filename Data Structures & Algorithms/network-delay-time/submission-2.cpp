class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i: times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> distance(n+1,INT_MAX);
        distance[0] = -1;
        distance[k] = 0;
        int res = -1;
        dfs(k, k,0,adj,distance);
        for(auto i: distance){
            cout << i << endl;
            if(i == INT_MAX){
                return -1;
            }
            res = max(res,i);
        }
        return res;
    }
    void dfs(int k, int node, int dist, vector<vector<pair<int,int>>>& adj, vector<int>& distance){
        if(adj[node].empty()) return;
        cout<< " Accessing Node " << node << endl;

        for(auto neighbor: adj[node]){
            if (neighbor.first == k) continue;
            int potential_dist = dist + neighbor.second;
            if(potential_dist < distance[neighbor.first])
            { distance[neighbor.first] = potential_dist;
                        dfs(k, neighbor.first, distance[neighbor.first], adj, distance);   }


        }
    }
};
