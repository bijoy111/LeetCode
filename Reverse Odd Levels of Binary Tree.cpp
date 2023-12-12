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
    
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int>vec;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            vec.push_back(cur->val);
            if(cur->left!=nullptr)
            {
                q.push(cur->left);
            }
            if(cur->right!=nullptr)
            {
                q.push(cur->right);
            }
        }
        int odd_level=0;
        int traverse_index=1;
        int tra_ind_help=1;
        
        for(int i = 0; i < vec.size(); i += tra_ind_help) 
        {
            //cout<<i<<endl;
            if(odd_level % 2 == 0) 
            {
                odd_level++;
                tra_ind_help = traverse_index;
                traverse_index *= 2;
                continue;
            }
            int start = i;
            int end = min(i + traverse_index, (int)vec.size()) - 1;
            if (start < end) 
            {
                reverse(vec.begin() + start, vec.begin() + end + 1);
            }
            odd_level++;
            tra_ind_help = traverse_index;
            traverse_index *= 2;
        }
        for(int i=0;i<vec.size();i++)
        {
            cout<<vec[i]<<" ";
        }


        int index=0;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            //cur->val=vec.pop_back();
            cur->val=vec[index++];
            if(cur->left!=nullptr)
            {
                q.push(cur->left);
            }
            if(cur->right!=nullptr)
            {
                q.push(cur->right);
            }
        }

        return root;

    }
};