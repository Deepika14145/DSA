class Solution {
public:
    bool mirror(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (!p || !q || p->val != q->val)
            return false;

        return mirror(p->left, q->right) &&
               mirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return mirror(root->left, root->right);
    }
};