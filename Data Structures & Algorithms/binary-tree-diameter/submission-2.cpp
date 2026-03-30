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
    int maxd = 0;
public:
    int maxDepth(TreeNode* root){
        if (root == nullptr) return 0;
        cout << "checking Node " << root->val << endl; 
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int d = rightDepth + leftDepth;
        
        maxd = max(maxd,d);
        cout << "Max depth Node " << root->val << " is "<< maxd <<endl;
        return 1 + max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        maxDepth(root);
        return maxd;
    }
};
