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
    int goodnodes = 0;
    

    void dfs(TreeNode* root, int maxval){
        if (root == nullptr) {
            //maxval = maxvalue;
            return;
        }
        
        if(maxval <= root->val){
           maxval = root->val;
           goodnodes +=1;      
        } 

        dfs(root->left, maxval);
        dfs(root->right, maxval);
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        //maxvalue = root->val;
        
        dfs(root, root->val);
        return goodnodes;
    }
};
