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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);

        int minDpth = min(minLeft, minRight) + 1;
        int maxDpth = max(minLeft, minRight) + 1;
        return minDpth > 1 ? minDpth : maxDpth;
    }
};