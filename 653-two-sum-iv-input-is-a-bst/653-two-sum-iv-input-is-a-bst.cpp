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
     bool dhundho(TreeNode* root,unordered_set<int>& set, int k)
     {
         if(root==NULL) return false;
         if(set.count(k-root->val))return true;
         set.insert(root->val);
         return dhundho(root->left,set,k)||dhundho(root->right,set,k);
     }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return dhundho(root,set, k);
    }
};