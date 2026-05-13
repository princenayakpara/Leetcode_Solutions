// Last updated: 13/05/2026, 19:25:39
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
14    bool mirror(TreeNode* a, TreeNode* b) {
15        if (!a && !b) return true;
16
17        if (!a || !b) return false;
18
19        return (a->val == b->val) &&
20               mirror(a->left, b->right) &&
21               mirror(a->right, b->left);
22    }
23
24    bool isSymmetric(TreeNode* root) {
25        return mirror(root->left, root->right);
26    }
27};
28