/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, long long & prev, bool& ok) {
        if(!root) return; 
        dfs(root->left, prev, ok); 
        if(prev >= (long long) root->val) {
            ok = false; 
            return; 
        }
        prev = (long long) root->val; 
        dfs(root->right, prev, ok); 
    }
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        // cout << prev; 
        bool ok = true; 
        dfs(root, prev, ok); 
        return ok; 
    }
};
