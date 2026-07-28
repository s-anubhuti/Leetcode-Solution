class Solution {
public:
    unordered_map<int, int> inorderIndexes;
    int i_post;

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int start, int end) {
        if (start > end || i_post < 0)
            return NULL;

        TreeNode* node = new TreeNode(postorder[i_post]);

        int i_in = inorderIndexes[postorder[i_post]];

        i_post--;

        node->right = solve(postorder, inorder, i_in + 1, end);
        node->left = solve(postorder, inorder, start, i_in - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderIndexes[inorder[i]] = i;

        i_post = postorder.size() - 1;

        return solve(postorder, inorder, 0, inorder.size() - 1);
    }
};