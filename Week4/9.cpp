TreeNode* bstFromPreorder(vector<int> &p, int first = 0, int last = 0) {
    if (last == 0) last = p.size();
    if (first == last) return nullptr;
    auto split = find_if(begin(p) + first, begin(p) + last, [&](int val) { return val > p[first]; });
    auto root = new TreeNode(p[first]);
    root->left = bstFromPreorder(p, first + 1, split - begin(p));
    root->right = bstFromPreorder(p, split - begin(p), last);
    return root;
}
