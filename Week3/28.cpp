vector <int> bottomView(Node *root) {
       queue<pair<Node*,int>>q;
       map<int,int>ds;
       q.push({root,0});
       while(!q.empty()){
           int size=q.size();
           for(int i=0;i<size;i++){
               Node* node = q.front().first;
               int vl=q.front().second;
               q.pop();
               ds[vl]=node->data;
               if(node->left)  q.push({node->left,vl-1});
               if(node->right) q.push({node->right,vl+1});
           }
       }
       vector<int>ans;
       for(auto it:ds)
           ans.push_back(it.second);
       return ans;
   }
