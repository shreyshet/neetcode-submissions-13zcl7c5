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
    bool isbalance = true;
public:
    int maxDepth(TreeNode* root){
        if (root == nullptr) return 0;
        cout << "checking Node " << root->val << endl; 
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        cout << "Depth on Node " << root->val << " LeftDepth " << leftDepth <<  " RightDepth " << rightDepth << endl ;
        if(abs(leftDepth - rightDepth ) > 1) isbalance = false;

        return 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return isbalance;
    }
};
