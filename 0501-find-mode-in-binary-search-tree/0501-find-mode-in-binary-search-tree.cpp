class Solution {
public:
    int currCount = 0;
    int maxCount = 0;
    TreeNode* prev = nullptr;
    vector<int> ans;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val == root->val)
            currCount++;
        else
            currCount = 1;

        if (currCount > maxCount) {
            maxCount = currCount;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (currCount == maxCount) {
            ans.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};