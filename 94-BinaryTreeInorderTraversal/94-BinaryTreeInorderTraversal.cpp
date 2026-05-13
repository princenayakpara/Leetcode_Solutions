// Last updated: 13/05/2026, 15:53:33
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
14    vector<int> ans;
15
16    void inorder(TreeNode* root) {
17        if (!root) return;
18
19        inorder(root->left);
20        ans.push_back(root->val);
21        inorder(root->right);
22    }
23
24    vector<int> inorderTraversal(TreeNode* root) {
25        inorder(root);
26        return ans;
27    }
28};