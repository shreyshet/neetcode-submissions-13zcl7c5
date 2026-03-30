class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        for(auto i : edges){
            vector<bool> visited(n+1, false);
            if(!graph[i[0]].empty() && !graph[i[1]].empty() && dfs(i[0],i[1], graph, visited)) 
                return i;
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }       
        return {};
    }
    bool dfs(int curr, int target,vector<vector<int>>& graph, vector<bool>& visited){
        if(curr == target) return true;
        visited[curr] = true;
        for(int neighbor: graph[curr]){
            if(!visited[neighbor]){
                if(dfs(neighbor, target, graph, visited)) return true;
            }
        }
        return false;
    }

};
