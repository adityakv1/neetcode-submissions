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
    void depth(TreeNode* root,int d,int &maxx){
        if(!root) return;
        maxx=max(maxx,d);
        
        depth(root->left,d+1,maxx);
        depth(root->right,d+1,maxx);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int d=1;
        int maxx=INT_MIN;
        depth(root,d,maxx);
        return maxx;
    }
};
