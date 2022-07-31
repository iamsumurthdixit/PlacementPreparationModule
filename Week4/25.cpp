class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> egs(num); vector<int> ind(num);
        for(int i = 0; i < pre.size(); i++) {
            int u = pre[i][0], v = pre[i][1];
            egs[v].push_back(u);
            ind[u]++;
        }
        vector<int> res; stack<int> st; 
        for(int i = 0; i < num; i++) {
            if(ind[i] == 0) {
                st.push(i);
            }
        }
        while(!st.empty()) {
            int x = st.top(); st.pop(); 
            res.push_back(x);
            for(int node : egs[x]) {
                ind[node]--;
                if(ind[node] == 0) st.push(node);
            }
        }
        if(res.size() == num)
            return true; 
        return false; 
    }
};
