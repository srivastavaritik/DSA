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
    
    void pseudoCount(vector<int>&vec, int&count, TreeNode*root)
    {
        if(root==NULL)return;
        vec[root->val]++;
        pseudoCount(vec, count, root->left);
        pseudoCount(vec, count, root->right);
        if(root->left==NULL and root->right==NULL)
        {
            int f=0;
            for(int i=1;i<10;i++)
            {
                if(vec[i]%2!=0)f++;
            }
            if(f==0 || f==1)count++;
        }
        
        vec[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int count =0;
        vector<int> vec(10,0);
        pseudoCount(vec, count, root);
        return count;
    }
};