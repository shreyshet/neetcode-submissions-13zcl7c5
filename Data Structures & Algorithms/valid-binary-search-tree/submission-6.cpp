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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left = true;
        bool right = true;
        stack<TreeNode*> q;
        stack<int> maxs;
        stack<int> mins;
        q.push(root);
        maxs.push(INT_MAX);
        mins.push(INT_MIN);

        while(!q.empty()){
            TreeNode* cur = q.top(); q.pop();
            int lower = mins.top(); mins.pop();
            int upper = maxs.top(); maxs.pop();

            //cout << cur->val << endl;
            if (cur->val <= lower || cur->val >= upper) return false;

            if(cur->right) {
                q.push(cur->right);
                mins.push(cur->val);
                maxs.push(upper);
            }

            if(cur->left) {
                q.push(cur->left);
                mins.push(lower);
                maxs.push(cur->val);
            }
        }
        return true;
    }
};
