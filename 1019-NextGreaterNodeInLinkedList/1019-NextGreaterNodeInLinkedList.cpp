// Last updated: 13/08/2026, 14:51:17
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    vector<int> nextLargerNodes(ListNode* head) {
14        vector<int> ans;
15
16        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
17            ListNode* temp = curr->next;
18
19            while (temp != nullptr && temp->val <= curr->val) {
20                temp = temp->next;
21            }
22
23            if (temp != nullptr)
24                ans.push_back(temp->val);
25            else
26                ans.push_back(0);
27        }
28
29        return ans;
30    }
31};