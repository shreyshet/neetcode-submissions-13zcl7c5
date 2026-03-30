class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> visited;
        if(!dfs(0, -1, graph, visited)){
                return false;
        }
        return visited.size() == n;
    }
    bool dfs(int node, int parent, vector<vector<int>>& graph, unordered_set<int>& visited){

        if(visited.count(node)){
            return false; 
        }
        visited.insert(node);
        for(auto k: graph[node]){
            if(k == parent) continue;
            if (!dfs(k, node, graph, visited)) {
                return false;
            }
        }
        return true;
    }
};
