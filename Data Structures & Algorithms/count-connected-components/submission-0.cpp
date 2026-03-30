class Solution {

public:
    int countComponents(int n, vector<vector<int>>& edges) {
     
    vector<vector<int>> graph(n);
    for(auto i: edges){
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
        
    }
    vector<bool> visited(n,false);
    int count=0;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        count++;
        dfs(i,graph,visited);
    }

    return count;    
    }
    void dfs(int node,vector<vector<int>>& graph,vector<bool>& visited){
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }
};
