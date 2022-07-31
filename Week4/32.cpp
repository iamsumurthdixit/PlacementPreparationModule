vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector <int> ans(V, INT_MAX), vis(V);
        ans[S] = 0;
        priority_queue <pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>> > pq;
        pq.push({0, S});
        while(!pq.empty()){
            int n = pq.size();
            while(n--){
                pair <int,int> p = pq.top();
                pq.pop();
                int weight = p.first;
                int vertex = p.second;
                ans[vertex] = min(ans[vertex], weight);
                vis[vertex] = true;
                for(auto &i:adj[vertex]){
                    if(!vis[i[0]]){
                        pq.push({weight+i[1], i[0]});
                    }
                }
            }
        }
        return ans;
    }
