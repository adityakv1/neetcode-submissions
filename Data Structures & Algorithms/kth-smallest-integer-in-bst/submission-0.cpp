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
    void func(TreeNode* root,vector<int> & result){
        if(!root) return ;
        func(root->left,result);
        result.push_back(root->val);
        func(root->right,result);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        vector<int> result;
        func(root,result);
        return result[k-1];
    }
};
