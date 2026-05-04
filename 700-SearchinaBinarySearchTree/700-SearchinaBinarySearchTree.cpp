// Last updated: 05/05/2026, 01:13:09
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
14    TreeNode* searchBST(TreeNode* root, int val) {
15        while(root != NULL){
16            if(root->val == val) return root;
17            else if(val < root->val) root = root->left;
18            else root = root->right;
19        }
20        return NULL;
21    }
22};