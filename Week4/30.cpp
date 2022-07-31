class Solution {
public:
    bool bipartite(int src, vector<vector<int>>& graph, vector<int>& color) {
        if(color[src] == -1) 
            color[src] = 1; 
        for(int node : graph[src]) {
            if(color[node] == -1) {
                color[node] = 1 - color[src]; 
                if(!bipartite(node, graph, color)) {
                    return false; 
                }
            } else if(color[node] == color[src]) {
                return false; 
            }
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> color(n, -1); 
        for(int i = 0; i < n; i++) {
            if(!bipartite(i, graph, color))
                return false; 
        }
        return true; 
    }
};
