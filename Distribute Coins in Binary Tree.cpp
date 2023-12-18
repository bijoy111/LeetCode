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
class Solution 
{
public:
    long int move=0;
    int traverse(TreeNode* root)
    {
        int tmp;
        if(root->left!=nullptr)
        {
            root->val+=traverse(root->left);
        }
        if(root->right!=nullptr)
        {
            root->val+=traverse(root->right);
        }

        //if(root->left==nullptr&&root->right==nullptr)
        //{
            if(root->val==0)
            {
                move++;
                tmp= -1;
            }
            else if(root->val<0)
            {
                move+=abs(root->val)+1;
                tmp= (root->val-1);
            }
            else
            {
                move+=(root->val-1);
                tmp =(root->val-1);
            }
        //}
        return tmp;
    }
    int distributeCoins(TreeNode* root) 
    {
        traverse(root);
        return move;
    }
};