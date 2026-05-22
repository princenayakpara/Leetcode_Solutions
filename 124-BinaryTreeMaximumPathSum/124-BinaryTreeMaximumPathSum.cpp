// Last updated: 22/05/2026, 22:07:18
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int ans = INT_MIN;
15
16    int dfs(TreeNode* root) {
17        if (root == nullptr) return 0;
18
19        int left = max(0, dfs(root->left));
20        int right = max(0, dfs(root->right));
21
22        ans = max(ans, left + right + root->val);
23
24        return root->val + max(left, right);
25    }
26    int maxPathSum(TreeNode* root) {
27        dfs(root);
28        return ans;
29    }
30};