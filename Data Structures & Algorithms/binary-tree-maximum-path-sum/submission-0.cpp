class Solution {
   public:
    int maxSum;
    int traversal(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int maxSumLeft = traversal(root->left);
        int maxSumRight = traversal(root->right);
        if (maxSumLeft < 0) {
            maxSumLeft = 0;
        }
        if (maxSumRight < 0) {
            maxSumRight = 0;
        }
        maxSum = max(maxSumLeft + maxSumRight + root->val, maxSum);
        return max(maxSumLeft, maxSumRight) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxSum = max(traversal(root), maxSum);
        return maxSum;
    }
};
