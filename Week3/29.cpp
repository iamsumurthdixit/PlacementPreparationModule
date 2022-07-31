class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        if(!root) return ans;
        q.push({root,0});
        while(!q.empty())
        {
            Node *t = q.front().first;
            int h = q.front().second;
            q.pop();
            if(!m[h]) m[h] = t->data;
            if(t->left) q.push({t->left,h-1});
            if(t->right) q.push({t->right,h+1});
        }
        for(auto &it:m)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }

};
