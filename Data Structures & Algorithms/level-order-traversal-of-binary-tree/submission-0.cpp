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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        if(!root) return result;
        while(!q.empty()){
            int n =q.size();
            vector<int> a;
            for(int i =0;i<n;i++){
                TreeNode* node=q.front();
                int b=q.front()->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
                a.push_back(b);
                

                
                
            }
            result.push_back(a);
        }
        return result;
    }
};
