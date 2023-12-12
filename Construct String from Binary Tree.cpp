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
    string str;
    string tree2str(TreeNode* root) {
       
        
        str+=to_string(root->val);
        if(root->left!=nullptr)
        {
            str+="(";
            tree2str(root->left);
            str+=")";
        }
        if(root->right!=nullptr)
        {
            if(root->left==nullptr)
            {
                str+="()";
            }
            str+="(";
            tree2str(root->right);
            str+=")";
        }
        
        return str;
    }
};