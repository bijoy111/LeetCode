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
    TreeNode* node=nullptr;
    int max_depth=0;
    int inorder_traverse(TreeNode* root,int depth)
    {
        if(root->left==nullptr && root->right==nullptr)
        {
            if(depth>=max_depth)
            {
                max_depth=depth;
                node=root;
            }
            return depth;
        }
        int tmp1=-1,tmp2=-1;
        if(root->left!=nullptr)
        {
            tmp1=inorder_traverse(root->left,depth+1);
        }   
        if(root->right!=nullptr)
        {
            tmp2=inorder_traverse(root->right,depth+1);
            if(tmp1==tmp2&&tmp1==max_depth)
            {
                node=root;
            }
        }
        return max(tmp1,tmp2);
            
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        inorder_traverse(root,0);
        return node;
    }
};