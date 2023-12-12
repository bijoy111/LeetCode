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

    long int ans=0;
    void traverse(TreeNode* tmp,int maximum)
    {
        if(tmp==nullptr)
        {
            return;
        }
        if(tmp->val>=maximum)
        {
            ans++;
            maximum=tmp->val;
        }

        traverse(tmp->left,maximum);
        traverse(tmp->right,maximum);

    }
    int goodNodes(TreeNode* root) {
        traverse(root,root->val);
        return ans;
    }
};