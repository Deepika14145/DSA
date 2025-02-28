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
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;
    
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse) pushAll(node->right); // Inorder successor
        else pushAll(node->left);           // Reverse inorder predecessor
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        BSTIterator left(root, false);  // Ascending order
        BSTIterator right(root, true);  // Descending order
        
        int i = left.next();
        int j = right.next();
        
        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = left.next();
            else j = right.next();
        }
        
        return false;
    }
};

// Utility function to insert a node in the BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}
