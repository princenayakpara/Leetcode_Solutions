// Last updated: 07/06/2026, 10:21:46
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
14    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
15        unordered_map<int, TreeNode*> mp;
16        unordered_set<int> childNodes;
17
18        for (auto &d : descriptions) {
19            int parent = d[0];
20            int child = d[1];
21            int isLeft = d[2];
22
23            if (!mp.count(parent))
24                mp[parent] = new TreeNode(parent);
25
26            if (!mp.count(child))
27                mp[child] = new TreeNode(child);
28
29            if (isLeft)
30                mp[parent]->left = mp[child];
31            else
32                mp[parent]->right = mp[child];
33
34            childNodes.insert(child);
35        }
36
37        for (auto &d : descriptions) {
38            int parent = d[0];
39
40            if (!childNodes.count(parent))
41                return mp[parent];
42        }
43
44        return nullptr;
45    }
46};