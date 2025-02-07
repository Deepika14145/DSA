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
    TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return root;

    // Step 1: Search for the node to delete
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Step 2: Found the node to delete
        
        // Case 1: No child (Leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child (left or right)
        else if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            TreeNode* temp = findMin(root->right); // Inorder successor
            root->val = temp->val; // Replace value
            root->right = deleteNode(root->right, temp->val); // Delete successor
        }
    }
    return root;
}

// Helper function to print Inorder traversal (for testing)
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
};
