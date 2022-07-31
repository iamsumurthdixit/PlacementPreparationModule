vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> distances(V,1e8);
        distances[S]=0;
        for(int i=0;i<V;i++){
            for(auto &edge:adj){
                int u=edge[0],v=edge[1],w=edge[2];
                if(distances[u]!=1e8 && distances[v]>distances[u]+w){
                    distances[v]=distances[u]+w;
                }
            }
        }
        return distances;
    }
