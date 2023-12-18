/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dec=0;
    TreeNode* ans;
    TreeNode* pp;
    TreeNode* qq;
    int traverse(TreeNode* root)
    {
        int pro=0;
        if(root->left!=nullptr)
        {
            pro+=traverse(root->left);
        }
        if(root->right!=nullptr)
        {
            pro+=traverse(root->right);
        }

        if(pp!=nullptr && root->val == pp->val)
        {
            pp=nullptr;
            pro+=1;
        }
        else if(qq!=nullptr && root->val==qq->val)
        {
            qq=nullptr;
            pro+=1;
        }

        if(pro>=2 && dec==0)
        {
            dec=1;
            ans=root;
        }
        return pro;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        pp=p;
        qq=q;
       traverse(root);
       return ans;
    }
};