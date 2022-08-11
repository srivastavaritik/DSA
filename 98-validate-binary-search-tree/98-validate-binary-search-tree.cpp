class Solution {
public:
    
    bool validate(TreeNode* root, long minval, long maxval)
    {
        if(root == NULL) return true;
        if(root->val>=maxval || root->val<=minval) return false;
        return validate(root->left, minval, root->val) && validate(root->right, root->val, maxval);
        }
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};