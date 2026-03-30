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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        
        if (!p || !q) return false;
        
        if(p->val != q->val){
            return false;
        }

        //cout << " Node " << p->val << " is same " << endl;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        if(left and right){
            return true;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            
            if(isSameTree(r,subRoot)){
                return true;
            }

            if(r->left) q.push(r->left);
            if(r->right) q.push(r->right);
        }
        return false;
    }
};
