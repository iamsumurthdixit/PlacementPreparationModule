class Solution
{
public:
   
   int parent(vector<int>& par, int node){
       if(par[node] == node) return node;
       
       return par[node] = parent(par, par[node]);
   }
   
   void connect(vector<int>& rank, vector<int>& par, int first, int second){
       first = parent(par, first);
       second = parent(par, second);
       
       if(rank[first] != rank[second]){
           if(rank[first] > rank[second]){
               par[second] = first;
           }
           else{
               par[first] = second;
           }
       }
       else{
           rank[first]++;
           par[second] = first;
       }
   }
   
   bool isConnected(vector<int>& rank, vector<int>& par, int first, int second){
       first = parent(par, first);
       second = parent(par, second);
       
       if(first == second) return true;
       
       return false;
   }
   
   int spanningTree(int n, vector<vector<int>> adj[]){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<int> par(n);
        vector<int> rank(n, 0);
        
        for(int i=0; i<n; i++){
            par[i] = i;
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<adj[i].size(); j++){
                int first = i;
                int second = adj[i][j][0];
                int dis = adj[i][j][1];
                pq.push({dis, {first, second}});
            }
        }
        
        while(!pq.empty()){
            int first = pq.top().second.first;
            int second = pq.top().second.second;
            if(!isConnected(rank, par, first, second)){
                 ans += pq.top().first;
                 connect(rank, par, first, second);
            }
            pq.pop();
        }
        return ans;
   }
};
