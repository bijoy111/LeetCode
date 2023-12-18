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
    queue<TreeNode*> q;
    int ans=1;
    int sum=0;
    int pop=0;
    int level=1;
    int maxLevelSum(TreeNode* root) 
    {
        q.push(root);
        sum=root->val;
        cout<<sum<<endl;
        pop=1;
        
        while(!q.empty())
        {
            level++;
            int tmp=0;
            int tmp1=0;
            int duke=0;
            while(pop!=0)
            {
                TreeNode* tmpp=q.front();
                q.pop();
                pop--;
                if(tmpp->left!=nullptr)
                {
                    tmp+=tmpp->left->val;
                    q.push(tmpp->left);
                    tmp1++;
                    duke=1;
                }
                if(tmpp->right!=nullptr)
                {
                    tmp+=tmpp->right->val;
                    q.push(tmpp->right);
                    tmp1++;
                    duke=1;
                }
            }
            if(tmp>sum&&duke==1)
            {
                sum=tmp;
                cout<<sum<<endl;
                ans=level;
            }
            pop=tmp1;
        }
        cout<<sum<<endl;
        return ans;
    }
};