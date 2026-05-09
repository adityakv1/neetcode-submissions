class Solution {
public:
    void depth(TreeNode* root, int d, int &maxx) {
        if (!root) return;

        maxx = max(maxx, d);

        depth(root->left, d + 1, maxx);
        depth(root->right, d + 1, maxx);
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int maxx = 0;
        depth(root, 1, maxx);

        return maxx;
    }
};