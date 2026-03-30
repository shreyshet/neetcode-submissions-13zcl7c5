class Solution { 
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> listCourses;
        unordered_map<int,vector<int>> graph;
        unordered_set<int> visit;
        unordered_set<int> cycle;
        for(auto j: prerequisites){
            graph[j[0]].push_back(j[1]);
        }
        for(int c = 0; c < numCourses; c++){
            if(!dfs(c, graph, visit, cycle, listCourses)){
                return {};
            }
        }
        return listCourses;
    }

    bool dfs(int crs, const unordered_map<int, vector<int>>& graph, unordered_set<int>& visit, unordered_set<int>& cycle, 
    vector<int>& listCourses){
        if(cycle.count(crs)){
            return false; // cycle detected
        }
        if(visit.count(crs)){
            return true; // reached end of graph
        }
        cycle.insert(crs);
        
        if(graph.count(crs)){
            for(auto pre: graph.at(crs)){
                if (!dfs(pre, graph, visit, cycle, listCourses)) {
                    return false;
                }
            }
        }
        listCourses.push_back(crs);
        visit.insert(crs);
        cycle.erase(crs);
        //graph[crs].clear();
        return true;
    }
};
