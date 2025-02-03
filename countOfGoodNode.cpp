class Solution {
public:
    int countGoodNodes(TreeNode* root, int maxValue) {
        if (root == NULL)
            return 0;

        int count = 0;

        // Check if this node is  good node
        if (root->val >= maxValue) {
            count = 1;
            maxValue = root->val; // Update maxValue
        }

        count += countGoodNodes(root->left, maxValue);
        count += countGoodNodes(root->right, maxValue);

        return count;
    }

    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return countGoodNodes(root, root->val); 
    }
};
