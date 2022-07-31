void help(Node *root,vector<int> ans){
   queue <Node*> q;
   
   if (root == NULL) return ;
  
  q.push(root);q.push(NULL);
  while(!q.empty()){
      Node *curr = q.front();
      
      q.pop();
      if (curr == NULL) {
          Node *curr2 = q.front();
          ans.push_back(curr2->data);
          q.push(NULL);
          continue;
      }
      if(curr->left != NULL) q.push(curr->left);
      if (curr->right != NULL) q.push(curr->right);
      
  }
}

vector<int> leftView(Node *root)
{
  // Your code here
  vector<int> ans;
  
  
  help(root , ans);
  
  return ans;
}
