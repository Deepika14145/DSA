class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            unsigned long long first = q.front().second;
            unsigned long long left, right;

            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= first; // Normalize indices

                if (i == 0) left = idx;
                if (i == sz - 1) right = idx;

                if (node->left)
                    q.push({node->left, 2 * idx + 1});

                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            ans = max(ans, (int)(right - left + 1));
        }

        return ans;
    }
};