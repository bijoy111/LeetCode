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
    void solution(TreeNode* root,int max_val,int min_val)
    {
        if(max_val>=min_val)
            {
                if(ans<abs(max_val-root->val))
                {
                    ans=abs(max_val-root->val);
                }
                if(ans<abs(min_val-root->val))
                {
                    ans=abs(min_val-root->val);
                }
            }
            if(max_val<root->val)
                max_val=root->val;
            if(min_val>root->val)
                min_val=root->val;
        if(root->left!=nullptr)
        {
            solution(root->left,max_val,min_val);
        }
        if(root->right!=nullptr)
        {
            solution(root->right,max_val,min_val);
        }
    }
    int maxAncestorDiff(TreeNode* root)
    {
        solution(root,INT_MIN,INT_MAX);
        return ans;
    }
};